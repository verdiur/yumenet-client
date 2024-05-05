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

#include <raylib.h>

#include <core/consts.hpp>
#include <comp/direction.hpp>
#include <utils/dir_to_pos.hpp>


Vector2 characterDirToPos(Vector2 from, CharacterDirection::D dir)
{
    switch (dir)
    {
    case CharacterDirection::UP:
        return {from.x, from.y - TILE_SIZE};
    case CharacterDirection::DOWN:
        return {from.x, from.y + TILE_SIZE};
    case CharacterDirection::LEFT:
        return {from.x - TILE_SIZE, from.y};
    case CharacterDirection::RIGHT:
        return {from.x + TILE_SIZE, from.y};
    default:
        return {from.x, from.y};
    }
}