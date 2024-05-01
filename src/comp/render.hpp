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


/// @brief Render order component.
/// @brief At render time, each layer is ordered before rendering based on this component.
struct RenderOrder {
    int index;
};


/// @brief Render layer component.
/// @brief At render time, layers are sorted by index before rendering based on this component.
struct RenderLayer {
    int index;
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
    Texture *p_sheet;
    Rectangle *p_frame;
};
