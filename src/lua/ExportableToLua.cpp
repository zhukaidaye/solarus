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
#include "lua/ExportableToLua.h"
#include "lowlevel/Debug.h"

namespace solarus {

/**
 * \brief Creates an object exportable to Lua.
 */
ExportableToLua::ExportableToLua():
  RefCountable(),
  known_to_lua(false),
  with_lua_table(false) {

}

/**
 * \brief Destroys this exportable object.
 */
ExportableToLua::~ExportableToLua() {
}

/**
 * \brief Returns whether this object was exported in the Lua side.
 *
 * This stays \c true even if the object was collected from Lua.
 *
 * \param known_to_lua \c true if this object was exported in the Lua side
 * at least once.
 */
bool ExportableToLua::is_known_to_lua() const {
  return known_to_lua;
}

/**
 * \brief Sets whether this object was exported in the Lua side.
 * \param known_to_lua \c true if this object was exported in the Lua side
 * at least once.
 */
void ExportableToLua::set_known_to_lua(bool known_to_lua) {
  this->known_to_lua = known_to_lua;
}

/**
 * \brief Returns whether this userdata has an associated table in Lua.
 *
 * This is the case if __newindex was called at least once for the userdata.
 * It might be \c true even if the userdata does not exist anymore in Lua.
 *
 * \return \c true if there is a Lua table for this userdata.
 */
bool ExportableToLua::is_with_lua_table() const {
  return with_lua_table;
}

/**
 * \brief Sets whether this userdata has an associated table in Lua.
 * \param with_lua_table \c true if there is a Lua table for this userdata.
 */
void ExportableToLua::set_with_lua_table(bool with_lua_table) {
  this->with_lua_table = with_lua_table;
}

}

