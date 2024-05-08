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
#include <string>
#include <vector>
#include <map>
#include <raylib.h>


/// @brief Render layer component.
/// @brief At render time, layers are sorted by index before rendering based on this component.
/// @see sys/render.cpp
struct RenderOrder {
    int y;
    int layer;
};


/// @brief Simple sprite component.
/// @brief This component doesn't use pointers, so it's best to avoid using it if you need multiple
/// @brief instances to have the same sprite.
struct BasicSprite {
    Texture sheet;
};


/// @brief Spritesheet component.
/// @brief Contains a spritesheet description, which contains `std::vector`s of `Rectangle`s
/// @brief classified by a name id.
struct Spritesheet {
    Texture sheet;
    std::map<std::string, std::vector<Rectangle>> desc;
};


/// @brief Spritesheet-based sprite component.
/// @brief Uses pointers, to be used in conjunction with a `Spritesheet`.
struct Sprite {
    /// @brief Spritesheet texture.
    Texture *p_sheet;
    /// @brief Rectangle that delimits the portion of the spritesheet to use.
    Rectangle *p_frame;
};
