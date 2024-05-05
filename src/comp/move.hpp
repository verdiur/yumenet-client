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


struct IsMoving
{
    bool answer;
};


struct CanMove
{
    bool answer;
};


/// @brief This is where the entity started moving from.
struct FromTilePosition
{
    Vector2 position;
};


/// @brief Desired tile position. This is where the entity wants to go.
struct ToTilePosition
{
    Vector2 position;
};


/// @brief Linear interpolation for movement function.
struct MoveLerp
{
    float amount;
};


/// @brief Speed component.
struct Speed
{
    float speed;
};
