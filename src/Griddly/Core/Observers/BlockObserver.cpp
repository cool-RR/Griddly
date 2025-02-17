#include "BlockObserver.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <utility>

#include "../Grid.hpp"

namespace griddly {

const std::map<std::string, SpriteDefinition> BlockObserver::blockSpriteDefinitions_ = {
    {"circle", {{"block_shapes/circle.png"}}},
    {"triangle", {{"block_shapes/triangle.png"}}},
    {"square", {{"block_shapes/square.png"}}},
    {"pentagon", {{"block_shapes/pentagon.png"}}},
    {"hexagon", {{"block_shapes/hexagon.png"}}},
};

BlockObserver::BlockObserver(std::shared_ptr<Grid> grid)
    : SpriteObserver(grid) {
}

ObserverType BlockObserver::getObserverType() const {
  return ObserverType::BLOCK_2D;
}

void BlockObserver::init(BlockObserverConfig& config) {
  blockDefinitions_ = config.blockDefinitions;
  config.spriteDefinitions = blockSpriteDefinitions_;
  config_ = config;
  SpriteObserver::init(config);
}

void BlockObserver::updateObjectSSBOData(PartialObservableGrid& observableGrid, glm::mat4& globalModelMatrix, DiscreteOrientation globalOrientation) {
  const auto& objects = grid_->getObjects();
  const auto& objectIds = grid_->getObjectIds();
  for (auto& object : objects) {
    auto location = object->getLocation();

    if (!(location.x < observableGrid.left || location.x > observableGrid.right || location.y < observableGrid.bottom || location.y > observableGrid.top)) {
      vk::ObjectDataSSBO objectData;
      std::vector<vk::ObjectVariableSSBO> objectVariableData;

      auto objectOrientation = object->getObjectOrientation();
      const auto& objectName = object->getObjectName();
      const auto& tileName = object->getObjectRenderTileName();
      auto objectPlayerId = object->getPlayerId();
      auto objectTypeId = objectIds.at(objectName);
      auto zIdx = object->getZIdx();

      spdlog::trace("Updating object {0} at location [{1},{2}]", objectName, location.x, location.y);

      const auto& blockDefinition = blockDefinitions_.at(tileName);

      // Translate the locations with respect to global transform
      glm::vec4 renderLocation = globalModelMatrix * glm::vec4(location, 0.0, 1.0);

      // Translate
      objectData.modelMatrix = glm::translate(objectData.modelMatrix, glm::vec3(renderLocation.x, renderLocation.y, 0.0));
      objectData.modelMatrix = glm::translate(objectData.modelMatrix, glm::vec3(0.5, 0.5, 0.0));  // Offset for the the vertexes as they are between (-0.5, 0.5) and we want them between (0, 1)

      // Rotate the objects that should be rotated
      if (config_.rotateAvatarImage) {
        if (!(object == avatarObject_ && config_.rotateWithAvatar)) {
          auto objectAngleRadians = objectOrientation.getAngleRadians() - globalOrientation.getAngleRadians();
          objectData.modelMatrix = glm::rotate(objectData.modelMatrix, objectAngleRadians, glm::vec3(0.0, 0.0, 1.0));
        }
      }

      // Scale the objects based on their scales
      auto scale = blockDefinition.scale;
      objectData.modelMatrix = glm::scale(objectData.modelMatrix, glm::vec3(scale, scale, 1.0));

      if(blockDefinition.usePlayerColor) {
        auto playerColorId = getEgocentricPlayerId(objectPlayerId);
        spdlog::debug("player color size:{0}, idx: {1}", config_.playerColors.size(), playerColorId-1);
        objectData.color = glm::vec4(config_.playerColors[playerColorId-1], 1.0);
      } else {
        objectData.color = glm::vec4(blockDefinition.color[0], blockDefinition.color[1], blockDefinition.color[2], 1.0);
      }
      
      objectData.playerId = objectPlayerId;
      objectData.textureIndex = device_->getSpriteArrayLayer(blockDefinition.shape);
      objectData.objectTypeId = objectTypeId;
      objectData.zIdx = zIdx;

      for (auto variableValue : getExposedVariableValues(object)) {
        objectVariableData.push_back({variableValue});
      }

      frameSSBOData_.objectSSBOData.push_back({objectData, objectVariableData});
    }
  }

  // Order cache by z idx so we draw them in the right order
  std::sort(frameSSBOData_.objectSSBOData.begin(), frameSSBOData_.objectSSBOData.end(),
            [this](const vk::ObjectSSBOs& a, const vk::ObjectSSBOs& b) -> bool {
              return a.objectData.zIdx < b.objectData.zIdx;
            });
}

}  // namespace griddly
