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
#include <random>


/// @brief Size of a tile texture in pixels
constexpr int TILE_TEXTURE_SIZE = 8;   

/// @brief When rendering, textures are scaled by a factor of 2
constexpr int TEXTURE_SIZE_MULTIPLIER = 2;

/// @brief Utility shorthand to get the size of a tile in pixels
constexpr int TILE_SIZE = TILE_TEXTURE_SIZE * TEXTURE_SIZE_MULTIPLIER;


/// @brief Time required for a 1-tile move at normal speed.
constexpr float MOVE_TIME = 1;

/// @brief Movement probability.
constexpr float MOVE_PROBABILITY = 0.2;

