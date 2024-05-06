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

#include <core/game.hpp>


/// @brief The actual app container for the `Game` instance.
/// @brief `App` initializes and de-initializes the Raylib context via `App::run()`.
class App
{
private:

    int m_window_width;     // Window width.
    int m_window_height;    // Window height.
    int m_game_width;       // Game width.
    int m_game_height;      // Game height.
    int m_fps;              // Frames per second.
    Game *p_game;           // Pointer to game instance.
    int m_ratio;            // Ratio between game size and window size
    Rectangle m_app_rec;    // Destination rectangle

public:

    App(int fps, int window_width, int window_height, int game_width = 640, int game_height = 480);
    ~App();

    /// @brief Updates window dimensions.
    void updateWindowDimensions();

    /// @brief Updates game scaling based on the window size.
    void updateScaling();

    void loadGame();
    void unloadGame();
    void run();
};
