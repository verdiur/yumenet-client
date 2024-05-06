/**
 * This file is part of yumenet.
 *
 * yumenet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * yumenet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with yumenet. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <entt/entt.hpp>

#include <utils/rng.hpp>
#include <utils/dir_to_pos.hpp>

#include <comp/coord/position.hpp>
#include <comp/coord/direction.hpp>
#include <comp/move.hpp>
#include <comp/tags.hpp>

#include <core/consts.hpp>


/// @brief Move all Npcs and update state for 1 frame. 
/// @param reg Entity registry.
void moveCharacter(entt::registry &reg);
