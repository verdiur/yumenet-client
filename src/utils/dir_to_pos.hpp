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
#include <raylib.h>

#include <comp/coord/direction.hpp>


/// @brief Convert a CharacterDirection enum to a destination tile vector relative to 
/// @brief an initial tile vector.
/// @param from Initial tile vector.
/// @param dir Direction the character is pointing to.
/// @return Destination tile vector.
Vector2 characterDirToPos(Vector2 from, CharacterDirection::D dir);
