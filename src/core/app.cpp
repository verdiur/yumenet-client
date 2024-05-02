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
#include <core/app.hpp>
#include <core/game.hpp>


App::App(int fps, int window_width, int window_height, int game_width, int game_height):
    m_fps(fps),
    m_window_width(window_width),
    m_window_height(window_height),
    m_game_width(game_width),
    m_game_height(game_height),
    p_game(nullptr),
    m_ratio(),
    m_rec()
{
    m_ratio = (float)m_window_width / (float)m_game_width;
    m_rec = { -m_ratio, -m_ratio, m_window_width + m_ratio * 2, m_window_height + m_ratio * 2 };
}


App::~App()
{}


void App::loadGame()
{
    p_game = new Game(m_game_width, m_game_height);
}

void App::unloadGame()
{
    delete p_game;
    p_game = nullptr;           // avoids having a dangling pointer
}


void App::run()
{
    /// INITIALIZE

    InitWindow(m_window_width, m_window_height, "yumenet");
    SetTargetFPS(m_fps);
    loadGame();

    /// GAME LOOP

    while (!WindowShouldClose())
    {
        p_game->update();
        p_game->render();

        BeginDrawing();
            ClearBackground(RED);
            DrawTexturePro(p_game->getTarget().texture, p_game->getRec(), m_rec, {}, 0, WHITE);
        EndDrawing();
    }

    /// DE-INITIALIZE

    unloadGame();
    CloseWindow();
}
