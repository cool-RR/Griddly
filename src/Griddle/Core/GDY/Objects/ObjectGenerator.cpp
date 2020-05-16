#include "ObjectGenerator.hpp"

#include <spdlog/spdlog.h>

#define SPDLOG_HEADER_ONLY
#include <spdlog/fmt/fmt.h>

#include "Object.hpp"

namespace griddle {
ObjectGenerator::ObjectGenerator() {
}

ObjectGenerator::~ObjectGenerator() {
}

void ObjectGenerator::defineNewObject(std::string objectName, uint32_t zIdx, char mapChar, std::unordered_map<std::string, uint32_t> parameterDefinitions) {
  spdlog::debug("Defining new object {0}", objectName);

  ObjectDefinition objectDefinition;
  objectDefinition.objectName = objectName;
  objectDefinition.zIdx = zIdx;
  objectDefinition.parameterDefinitions = parameterDefinitions;

  objectDefinitions_.insert({objectName, std::make_shared<ObjectDefinition>(objectDefinition)});

  objectChars_[mapChar] = objectName;
  objectIds_.insert({objectName, objectCount_++});
}

void ObjectGenerator::defineActionBehaviour(
    std::string objectName,
    ActionBehaviourDefinition behaviourDefinition) {
  auto objectDefinition = getObjectDefinition(objectName);
  objectDefinition->actionBehaviourDefinitions.push_back(behaviourDefinition);

  spdlog::debug("{0} behaviours {1}", objectName, objectDefinition->actionBehaviourDefinitions.size());
}

std::shared_ptr<Object> ObjectGenerator::newInstance(std::string objectName, std::unordered_map<std::string, std::shared_ptr<int32_t>> globalParameters) {
  auto objectDefinition = getObjectDefinition(objectName);

  spdlog::debug("Creating new object {0}. {1} parameters, {2} behaviours.",
                objectName, 
                objectDefinition->parameterDefinitions.size(), 
                objectDefinition->actionBehaviourDefinitions.size());

  // Initialize the parameters for the Object
  std::unordered_map<std::string, std::shared_ptr<int32_t>> availableParameters;
  for (auto &parameterDefinitions : objectDefinition->parameterDefinitions) {
    auto initializedParameter = std::make_shared<int32_t>(parameterDefinitions.second);
    availableParameters.insert({parameterDefinitions.first, initializedParameter});
  }

  for(auto &globalParameter : globalParameters) {
    auto parameterName = globalParameter.first;
    auto initializedParameter = globalParameter.second;
    availableParameters.insert({parameterName, initializedParameter});
  }

  auto objectZIdx = objectDefinition->zIdx;
  auto id = objectIds_[objectName];
  auto initializedObject = std::shared_ptr<Object>(new Object(objectName, id, objectZIdx, availableParameters, shared_from_this()));

  if(objectName == avatarObject_) {
    spdlog::info("Setting avatar object as {0}", objectName);
    initializedObject->markAsPlayerAvatar();
  }

  for (auto &actionBehaviourDefinition : objectDefinition->actionBehaviourDefinitions) {
    switch (actionBehaviourDefinition.behaviourType) {
      case ActionBehaviourType::SOURCE:
        initializedObject->addActionSrcBehaviour(
            actionBehaviourDefinition.actionName,
            actionBehaviourDefinition.destinationObjectName,
            actionBehaviourDefinition.commandName,
            actionBehaviourDefinition.commandParameters,
            actionBehaviourDefinition.conditionalCommands);
        break;
      case ActionBehaviourType::DESTINATION:
        initializedObject->addActionDstBehaviour(
            actionBehaviourDefinition.actionName,
            actionBehaviourDefinition.sourceObjectName,
            actionBehaviourDefinition.commandName,
            actionBehaviourDefinition.commandParameters,
            actionBehaviourDefinition.conditionalCommands);
        break;
    }
  }

  return initializedObject;
}

void ObjectGenerator::setAvatarObject(std::string objectName) {
  avatarObject_ = objectName;
}

std::string& ObjectGenerator::getObjectNameFromMapChar(char character) {
  auto objectCharIt = objectChars_.find(character);
  if (objectCharIt == objectChars_.end()) {
    throw std::invalid_argument(fmt::format("Object with map character {0} not defined.", character));
  }
  return objectCharIt->second;
}

std::shared_ptr<ObjectDefinition>& ObjectGenerator::getObjectDefinition(std::string objectName) {
  auto objectDefinitionIt = objectDefinitions_.find(objectName);
  if (objectDefinitionIt == objectDefinitions_.end()) {
    throw std::invalid_argument(fmt::format("Object {0} not defined.", objectName));
  }

  return objectDefinitionIt->second;
}

}  // namespace griddle