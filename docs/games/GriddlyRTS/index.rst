.. _doc_griddlyrts:

GriddlyRTS
==========

.. code-block::

   RTS/GriddlyRTS.yaml

Description
-------------

An RTS Game. There's aliens and stuff.

Levels
---------

.. list-table:: Levels
   :class: level-gallery
   :header-rows: 1

   * - 
     - Block2D
     - Sprite2D
     - Vector
     - Isometric
   * - .. list-table:: 

          * - Level ID
            - 0
          * - Size
            - 16x16
     - .. thumbnail:: img/GriddlyRTS-level-Block2D-0.png
     - .. thumbnail:: img/GriddlyRTS-level-Sprite2D-0.png
     - .. thumbnail:: img/GriddlyRTS-level-Vector-0.png
     - .. thumbnail:: img/GriddlyRTS-level-Isometric-0.png
   * - .. list-table:: 

          * - Level ID
            - 1
          * - Size
            - 30x30
     - .. thumbnail:: img/GriddlyRTS-level-Block2D-1.png
     - .. thumbnail:: img/GriddlyRTS-level-Sprite2D-1.png
     - .. thumbnail:: img/GriddlyRTS-level-Vector-1.png
     - .. thumbnail:: img/GriddlyRTS-level-Isometric-1.png
   * - .. list-table:: 

          * - Level ID
            - 2
          * - Size
            - 30x30
     - .. thumbnail:: img/GriddlyRTS-level-Block2D-2.png
     - .. thumbnail:: img/GriddlyRTS-level-Sprite2D-2.png
     - .. thumbnail:: img/GriddlyRTS-level-Vector-2.png
     - .. thumbnail:: img/GriddlyRTS-level-Isometric-2.png
   * - .. list-table:: 

          * - Level ID
            - 3
          * - Size
            - 57x58
     - .. thumbnail:: img/GriddlyRTS-level-Block2D-3.png
     - .. thumbnail:: img/GriddlyRTS-level-Sprite2D-3.png
     - .. thumbnail:: img/GriddlyRTS-level-Vector-3.png
     - .. thumbnail:: img/GriddlyRTS-level-Isometric-3.png

Code Example
------------

The most basic way to create a Griddly Gym Environment. Defaults to level 0 and SPRITE_2D rendering.

.. code-block:: python


   import gym
   import griddly
   from griddly.util.wrappers import InvalidMaskingRTSWrapper

   if __name__ == '__main__':

       env = gym.make('GDY-GriddlyRTS-v0')
       env.reset()
       env = InvalidMaskingRTSWrapper(env)

       # Replace with your own control algorithm!
       for s in range(1000):
           obs, reward, done, info = env.step(env.action_space.sample())
           for p in range(env.player_count):
               env.render(observer=p) # Renders the environment from the perspective of a single player

           env.render(observer='global') # Renders the entire environment
        
           if done:
               env.reset()


Objects
-------

.. list-table:: Tiles
   :header-rows: 2

   * - Name ->
     - minerals
     - worker
     - ranged
     - combat
     - fixed_wall
     - movable_wall
     - base
     - barracks_disabled
     - barracks
   * - Map Char ->
     - `M`
     - `H`
     - `r`
     - `c`
     - `W`
     - `w`
     - `A`
     - `b`
     - `B`
   * - Block2D
     - .. image:: img/GriddlyRTS-tile-minerals-Block2D.png
     - .. image:: img/GriddlyRTS-tile-worker-Block2D.png
     - .. image:: img/GriddlyRTS-tile-ranged-Block2D.png
     - .. image:: img/GriddlyRTS-tile-combat-Block2D.png
     - .. image:: img/GriddlyRTS-tile-fixed_wall-Block2D.png
     - .. image:: img/GriddlyRTS-tile-movable_wall-Block2D.png
     - .. image:: img/GriddlyRTS-tile-base-Block2D.png
     - .. image:: img/GriddlyRTS-tile-barracks_disabled-Block2D.png
     - .. image:: img/GriddlyRTS-tile-barracks-Block2D.png
   * - Sprite2D
     - .. image:: img/GriddlyRTS-tile-minerals-Sprite2D.png
     - .. image:: img/GriddlyRTS-tile-worker-Sprite2D.png
     - .. image:: img/GriddlyRTS-tile-ranged-Sprite2D.png
     - .. image:: img/GriddlyRTS-tile-combat-Sprite2D.png
     - .. image:: img/GriddlyRTS-tile-fixed_wall-Sprite2D.png
     - .. image:: img/GriddlyRTS-tile-movable_wall-Sprite2D.png
     - .. image:: img/GriddlyRTS-tile-base-Sprite2D.png
     - .. image:: img/GriddlyRTS-tile-barracks_disabled-Sprite2D.png
     - .. image:: img/GriddlyRTS-tile-barracks-Sprite2D.png
   * - Vector
     - .. image:: img/GriddlyRTS-tile-minerals-Vector.png
     - .. image:: img/GriddlyRTS-tile-worker-Vector.png
     - .. image:: img/GriddlyRTS-tile-ranged-Vector.png
     - .. image:: img/GriddlyRTS-tile-combat-Vector.png
     - .. image:: img/GriddlyRTS-tile-fixed_wall-Vector.png
     - .. image:: img/GriddlyRTS-tile-movable_wall-Vector.png
     - .. image:: img/GriddlyRTS-tile-base-Vector.png
     - .. image:: img/GriddlyRTS-tile-barracks_disabled-Vector.png
     - .. image:: img/GriddlyRTS-tile-barracks-Vector.png
   * - Isometric
     - .. image:: img/GriddlyRTS-tile-minerals-Isometric.png
     - .. image:: img/GriddlyRTS-tile-worker-Isometric.png
     - .. image:: img/GriddlyRTS-tile-ranged-Isometric.png
     - .. image:: img/GriddlyRTS-tile-combat-Isometric.png
     - .. image:: img/GriddlyRTS-tile-fixed_wall-Isometric.png
     - .. image:: img/GriddlyRTS-tile-movable_wall-Isometric.png
     - .. image:: img/GriddlyRTS-tile-base-Isometric.png
     - .. image:: img/GriddlyRTS-tile-barracks_disabled-Isometric.png
     - .. image:: img/GriddlyRTS-tile-barracks-Isometric.png


Actions
-------

build_barracks
^^^^^^^^^^^^^^

.. list-table:: 
   :header-rows: 1

   * - Action Id
     - Mapping
   * - 1
     - Left
   * - 2
     - Up
   * - 3
     - Right
   * - 4
     - Down


move
^^^^

.. list-table:: 
   :header-rows: 1

   * - Action Id
     - Mapping
   * - 1
     - Left
   * - 2
     - Up
   * - 3
     - Right
   * - 4
     - Down


spawn_combat
^^^^^^^^^^^^

:Internal: This action can only be called from other actions, not by the player.

.. list-table:: 
   :header-rows: 1

   * - Action Id
     - Mapping
   * - 1
     - Left
   * - 2
     - Up
   * - 3
     - Right
   * - 4
     - Down


attack
^^^^^^

.. list-table:: 
   :header-rows: 1

   * - Action Id
     - Mapping
   * - 1
     - Left
   * - 2
     - Up
   * - 3
     - Right
   * - 4
     - Down


spawn_worker
^^^^^^^^^^^^

:Internal: This action can only be called from other actions, not by the player.

.. list-table:: 
   :header-rows: 1

   * - Action Id
     - Mapping
   * - 1
     - Left
   * - 2
     - Up
   * - 3
     - Right
   * - 4
     - Down


construct_barracks
^^^^^^^^^^^^^^^^^^

:Internal: This action can only be called from other actions, not by the player.

.. list-table:: 
   :header-rows: 1

   * - Action Id
     - Mapping
   * - 1
     - Completes construction of a barracks


build_combat
^^^^^^^^^^^^

.. list-table:: 
   :header-rows: 1

   * - Action Id
     - Mapping
   * - 1
     - Build


gather
^^^^^^

.. list-table:: 
   :header-rows: 1

   * - Action Id
     - Mapping
   * - 1
     - Left
   * - 2
     - Up
   * - 3
     - Right
   * - 4
     - Down


build_worker
^^^^^^^^^^^^

.. list-table:: 
   :header-rows: 1

   * - Action Id
     - Mapping
   * - 1
     - Build


YAML
----

.. code-block:: YAML

   Version: "0.1"
   Environment:
     Name: GriddlyRTS
     Description: An RTS Game. There's aliens and stuff.
     Observers:
       Sprite2D:
         TileSize: 16
         BackgroundTile: oryx/oryx_tiny_galaxy/tg_sliced/tg_world/tg_world_floor_panel_metal_a.png
       Isometric:
         TileSize: [ 32, 48 ]
         BackgroundTile: oryx/oryx_iso_dungeon/floor-1.png
         IsoTileHeight: 16
         IsoTileDepth: 4
       Vector:
         IncludePlayerId: true
         IncludeVariables: true
     Variables:
       - Name: player_resources
         InitialValue: 0
         PerPlayer: true
     Player:
       Count: 2
     Termination:
       Lose:
         - Conditions:
             - eq: [ base:count, 0 ] # If the player has no bases
           Reward: -10 # -10 for a loss
           OpposingReward: 10 # as the agent didnt lose
     Levels:
       - |
         M  M  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         M  M  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  A1 H1 .  .  .  .  .  .  .  .  .  .  .  .
         .  .  H1 .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  .  .  .  .  .  H2 .  .
         .  .  .  .  .  .  .  .  .  .  .  .  H2 A2 .  .
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  M  M
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  M  M
       - |
         W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W
         W  .  .  B1 .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  H1 .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  H1 .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  M  M  M  M  M  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  M  M  M  M  M  M  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  M  M  .  M  M  M  M  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  M  .  M  M  M  .  M  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  M  M  M  M  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  M  M  M  M  M  M  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  M  .  .  M  .  M  M  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  M  M  M  M  M  M  M  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  M  M  M  M  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  H2 .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  H2 .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  B2 .  .  W
         W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W
       - |
         W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W
         W  .  .  B1 .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  H1 .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  H1 .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  M  M  M  M  M  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  M  M  M  M  M  M  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  M  M  .  M  M  M  M  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  M  .  M  M  M  .  M  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  W  W  W  W  w  W
         W  W  W  W  W  W  W  W  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  W  W  W  W  w  W
         W  .  .  .  .  .  .  W  W  .  .  .  w  w  w  w  w  w  .  .  .  .  .  W  W  W  W  W  w  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  w  w  .  .  .  .  .  .  .  W  W  W  W  W  w  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  W  W  W  W  w  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  W  W  W  W  w  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  M  M  M  M  .  .  .  .  W  W  W  W  W  w  W
         W  .  .  .  .  .  w  .  .  .  .  .  .  .  .  M  M  M  M  M  M  .  W  W  W  W  W  W  W  W
         W  .  .  .  .  .  w  .  .  .  .  .  .  .  M  .  .  M  .  M  M  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  w  .  .  .  .  .  .  .  M  M  M  M  M  M  M  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  M  M  M  M  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  H2 .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  H2 .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  B2 .  .  W
         W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W
       - |
         W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W
         W  .  .  .  .  M  M  M  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  M  M  M  M  W
         W  .  .  .  .  .  M  M  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  M  M  W
         W  .  .  .  .  .  .  M  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  H2 .  .  M  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  B2 H2 .  M  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  W  W  w  w  W  W  W  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  W  W  .  .  W  W  W  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  W  W  W  W  W  W  W  W  W  W  W  W  w  w  w  w  w  w  w  w  w  w  w  w  w  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  M  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  M  M  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  M  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  M  M  M  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  M  M  M  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  W  W  W  W  W  W  W  W  W  W  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  M  M  M  M  M  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  W  W  W  W  W  W  W  W  W  W  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  M  M  M  M  M  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  M  M  M  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  M  M  M  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  M  M  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  M  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  M  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  w  w  w  w  w  w  w  w  w  w  w  w  w  W  W  W  W  W  W  W  W  W  W  W  W  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W
         W  W  W  W  .  .  W  W  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  W  W  w  w  W  W  W  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  M  .  H1 B1 .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  W
         W  M  .  .  H1 .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  M  .  .  .  .  .  .  W
         W  M  M  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  M  M  .  .  .  .  .  W
         W  M  M  M  M  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  w  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  M  M  M  .  .  .  .  W
         W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W

   Actions:
     - Name: spawn_worker
       InputMapping:
         Internal: true
       Behaviours:
         - Src:
             Object: base
             Commands:
               - spawn: worker
               - set: [ is_busy, 0 ]
           Dst:
             Object: _empty

         - Src:
             Object: base
           Dst:
             Object: [ base, barracks, combat, worker, ranged, movable_wall ]
             Commands:
               # Try to spawn in another location on the next tick
               - exec:
                   Action: spawn_worker
                   Delay: 1
                   Randomize: true
     - Name: spawn_combat
       InputMapping:
         Internal: true
       Behaviours:
         - Src:
             Object: barracks
             Commands:
               - spawn: combat
               - set: [ is_busy, 0 ]
           Dst:
             Object: _empty

         - Src:
             Object: barracks
           Dst:
             Object: [ base, barracks, combat, worker, ranged, movable_wall ]
             Commands:
               # Try to spawn in another location on the next tick
               - exec:
                   Action: spawn_combat
                   Delay: 1
                   Randomize: true

     - Name: construct_barracks
       InputMapping:
         Inputs:
           1:
             Description: Completes construction of a barracks
             VectorToDest: [ 0, 0 ]
         Internal: true
       Behaviours:
         - Src:
             Object: barracks_disabled
             Commands:
               - set: [ is_busy, 0 ]
               - change_to: barracks
           Dst:
             Object: barracks_disabled

     # worker costs 5 resources to build, get a reward when a worker is built
     - Name: build_worker
       InputMapping:
         Inputs:
           1:
             Description: Build
             VectorToDest: [ 0, 0 ]
       Behaviours:
         - Src:
             Object: base
             Preconditions:
               - gte: [ player_resources, 5 ]
               - eq: [ is_busy, 0 ]
             Commands:
               - set: [ is_busy, 1 ]
               - sub: [ player_resources, 5 ]
               - reward: 1
                 # Queue a build which will take 10 seconds
               - exec:
                   Action: spawn_worker
                   Delay: 10
                   Randomize: true
                   Executor: action
           Dst:
             Object: base

     - Name: build_combat
       InputMapping:
         Inputs:
           1:
             Description: Build
             VectorToDest: [ 0, 0 ]
       Behaviours:
         - Src:
             Object: barracks
             Preconditions:
               - gte: [ player_resources, 5 ]
               - eq: [ is_busy, 0 ]
             Commands:
               - set: [ is_busy, 1 ]
               - sub: [ player_resources, 5 ]
               - reward: 1
               - exec:
                   Action: spawn_combat
                   Delay: 10
                   Randomize: true
                   Executor: action
           Dst:
             Object: barracks

     - Name: build_barracks
       Behaviours:
         - Src:
             Object: worker
             Preconditions:
               - gte: [ player_resources, 20 ]
               - eq: [ is_busy, 0 ]
             Commands:
               - sub: [ player_resources, 20 ]
               - reward: 1
               - spawn: barracks_disabled
           Dst:
             Object: _empty

     - Name: gather
       Behaviours:
         - Src:
             Object: worker
             Preconditions:
               - lt: [ resources, 5 ]
               - eq: [ is_busy, 0 ]
             Commands:
               - incr: resources
               - reward: 1
           Dst:
             Object: minerals
             Commands:
               - decr: resources
               - lt:
                   Arguments: [resources, 10]
                   Commands:
                     - set_tile: 1
               - lt:
                   Arguments: [ resources, 5 ]
                   Commands:
                     - set_tile: 2
               - eq:
                   Arguments: [ resources, 0 ]
                   Commands:
                     - remove: true
         - Src:
             Object: worker
             Preconditions:
               - eq: [ is_busy, 0 ]
               - gt: [ resources, 0 ]
               - eq: [ src._playerId, dst._playerId ]
             Commands:
               - decr: resources
               - reward: 1
           Dst:
             Object: base
             Commands:
               - incr: player_resources

     - Name: move
       Behaviours:
         - Src:
             Preconditions:
               - eq: [ is_busy, 0 ]
             Object: [ worker, combat, ranged ]
             Commands:
               - mov: _dest # mov will move the object, _dest is the destination location of the action
           Dst:
             Object: _empty

         - Src:
             Object: ranged
             Commands:
               - mov: _dest # mov will move the object, _dest is the destination location of the action
           Dst:
             Object: [ movable_wall, worker, combat ]
             Commands:
               - cascade: _dest # reapply the same action to the dest location of the action

     #   Name: ranged_attack
     - Name: attack
       Behaviours:

         - Src:
             Object: worker
             Preconditions:
               - neq: [ src._playerId, dst._playerId ]
               - eq: [ is_busy, 0 ]
             Commands:
               - reward: 1
           Dst:
             Object: [ base, combat, worker, ranged ]
             Commands:
               - sub: [ health, 1 ]
               - lte:
                   Arguments: [ health, 0 ]
                   Commands:
                     - remove: true

         - Src:
             Object: combat
             Preconditions:
               - neq: [ src._playerId, dst._playerId ]
               - eq: [ is_busy, 0 ]
             Commands:
               - reward: 1
           Dst:
             Object: [ base, combat, worker, ranged, barracks ]
             Commands:
               - sub: [ health, 5 ]
               - lte:
                   Arguments: [ health, 0 ]
                   Commands:
                     - remove: true

   Objects:
     - Name: minerals
       MapCharacter: M
       Variables:
         - Name: resources
           InitialValue: 20
       Observers:
         Sprite2D:
           - Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_items/tg_items_crystal_green.png
             Scale: 1.0
           - Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_items/tg_items_crystal_green.png
             Scale: 0.5
           - Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_items/tg_items_crystal_green.png
             Scale: 0.3
         Block2D:
           - Shape: triangle
             Color: [ 0.0, 1.0, 0.0 ]
             Scale: 1.0
           - Shape: triangle
             Color: [ 0.0, 1.0, 0.0 ]
             Scale: 0.5
           - Shape: triangle
             Color: [ 0.0, 1.0, 0.0 ]
             Scale: 0.1
         Isometric:
           - Image: oryx/oryx_iso_dungeon/minerals-1-0.png
           - Image: oryx/oryx_iso_dungeon/minerals-1-1.png
           - Image: oryx/oryx_iso_dungeon/minerals-1-2.png

     - Name: worker
       MapCharacter: H
       Variables:
         - Name: resources
           InitialValue: 0
         - Name: health
           InitialValue: 10
         - Name: is_busy
           InitialValue: 0
       Observers:
         Sprite2D:
           - Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_monsters/tg_monsters_jelly_d1.png
         Block2D:
           - Shape: square
             Color: [ 0.6, 0.2, 0.2 ]
             Scale: 0.5
         Isometric:
           - Image: oryx/oryx_iso_dungeon/jelly-1.png

     - Name: ranged
       MapCharacter: r
       Variables:
         - Name: health
           InitialValue: 20
         - Name: is_busy
           InitialValue: 0
       Observers:
         Sprite2D:
           - Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_monsters/tg_monsters_crawler_queen_d1.png
         Block2D:
           - Shape: square
             Color: [ 0.2, 0.2, 0.6 ]
             Scale: 1.0
         Isometric:
           - Image: oryx/oryx_iso_dungeon/queen-1.png

     - Name: combat
       MapCharacter: c
       Variables:
         - Name: health
           InitialValue: 30
         - Name: is_busy
           InitialValue: 0
       Observers:
         Sprite2D:
           - Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_monsters/tg_monsters_beast_d1.png
         Block2D:
           - Color: [ 0.2, 0.6, 0.6 ]
             Shape: square
             Scale: 0.8
         Isometric:
           - Image: oryx/oryx_iso_dungeon/beast-1.png

     - Name: fixed_wall
       MapCharacter: W
       Observers:
         Sprite2D:
           - TilingMode: WALL_2 # Will tile walls with two images
             Image:
               - oryx/oryx_tiny_galaxy/tg_sliced/tg_world_fixed/img33.png
               - oryx/oryx_tiny_galaxy/tg_sliced/tg_world_fixed/img40.png
         Block2D:
           - Color: [ 0.5, 0.5, 0.5 ]
             Shape: square
         Isometric:
           - Image: oryx/oryx_iso_dungeon/wall-grey-1.png

     - Name: movable_wall
       MapCharacter: w
       Observers:
         Sprite2D:
           - Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_world_fixed/img282.png
         Block2D:
           - Color: [ 0.8, 0.8, 0.8 ]
             Shape: square
         Isometric:
           - Image: oryx/oryx_iso_dungeon/crate-1.png

     - Name: base
       MapCharacter: A
       Variables:
         - Name: health
           InitialValue: 50
         - Name: is_busy
           InitialValue: 0
       Observers:
         Sprite2D:
           - Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_world_fixed/img324.png
         Block2D:
           - Color: [ 0.8, 0.8, 0.3 ]
             Shape: triangle
         Isometric:
           - Image: oryx/oryx_iso_dungeon/base-1.png

     - Name: barracks_disabled
       MapCharacter: b
       InitialActions:
         - Action: construct_barracks
           Delay: 20
       Variables:
         - Name: health
           InitialValue: 20
         - Name: is_busy
           InitialValue: 1
       Observers:
         Sprite2D:
           - Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_world_fixed/img280.png
         Block2D:
           - Color: [ 0.3, 0.3, 0.3 ]
             Shape: triangle
             Size: 0.5
         Isometric:
           - Image: oryx/oryx_iso_dungeon/barracks-disabled-1.png

     - Name: barracks
       MapCharacter: B
       Variables:
         - Name: health
           InitialValue: 40
         - Name: is_busy
           InitialValue: 0
       Observers:
         Sprite2D:
           - Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_world_fixed/img320.png
         Block2D:
           - Color: [ 0.8, 0.3, 0.8 ]
             Shape: triangle
         Isometric:
           - Image: oryx/oryx_iso_dungeon/barracks-1.png


