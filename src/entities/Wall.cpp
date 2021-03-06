/*
 * Copyright (C) 2006-2014 Christopho, Solarus - http://www.solarus-games.org
 * 
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "entities/Wall.h"
#include "entities/Hero.h"
#include "lowlevel/FileTools.h"

namespace solarus {

/**
 * \brief Constructor.
 * \param name name of the wall to create
 * \param layer layer of the Wall to create
 * \param x x position of the Wall to create
 * \param y y position of the Wall to create
 * \param width width of the Wall to create
 * \param height height of the Wall to create
 * \param stops_hero true to make this entity an obstacle for the hero
 * \param stops_enemies true to make this entity an obstacle for the enemies
 * \param stops_npcs true to make this entity an obstacle for the NPCs
 * \param stops_blocks true to make this entity an obstacle for the blocks and statues
 */
Wall::Wall(
    const std::string& name,
    Layer layer,
    int x,
    int y,
    int width,
    int height,
    bool stops_hero,
    bool stops_enemies,
    bool stops_npcs,
    bool stops_blocks):
  MapEntity(name, 0, layer, x, y, width, height),
  enabled(true),
  waiting_enabled(false) {

  entity_types_stopped[ENTITY_HERO] = stops_hero;
  entity_types_stopped[ENTITY_ENEMY] = stops_enemies;
  entity_types_stopped[ENTITY_NPC] = stops_npcs;
  entity_types_stopped[ENTITY_BLOCK] = stops_blocks;
}

/**
 * \brief Destructor.
 */
Wall::~Wall() {

}

/**
 * \brief Returns the type of entity.
 * \return the type of entity
 */
EntityType Wall::get_type() const {
  return ENTITY_WALL;
}

/**
 * \brief Returns whether entities of this type can be drawn.
 * \return true if this type of entity can be drawn
 */
bool Wall::can_be_drawn() const {
  return false;
}

/**
 * \brief Returns whether this entity is an obstacle for another one
 * when it is enabled.
 * \param other another entity
 * \return true if this entity is an obstacle for the other one
 */
bool Wall::is_obstacle_for(const MapEntity& other) const {

  std::map<EntityType, bool>::const_iterator it =
      entity_types_stopped.find(other.get_type());
  return it != entity_types_stopped.end() && it->second;
}

}

