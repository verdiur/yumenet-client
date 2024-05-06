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

#include <comp/coord/direction.hpp>
#include <comp/coord/position.hpp>
#include <comp/move.hpp>


/// @brief Utility functions
namespace
{
    void randomMoveControl(
        IsMoving &is_moving, 
        TilePosition &current, 
        MoveFromTile &from, 
        MoveToTile &to, 
        CharacterDirection direction
    );
}


/// @brief Npc movement control.
/// @param reg Entity registry.
void updateMoveNpc(entt::registry &reg);
