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


/// @brief Game class. Renders on a texture that can then be scaled accordingly on the window.
class Game
{
private:
    
    const int m_width;
    const int m_height;
    RenderTexture m_target;         // Target texture
    Rectangle m_game_rec;           // Source rectangle

public:

    Game(int width = 640, int height = 480);
    ~Game();

    int getWidth();
    int getWidth() const;
    int getHeight();
    int getHeight() const;
    RenderTexture getTarget();
    Rectangle getRec();

    void update();
    void render();
};
