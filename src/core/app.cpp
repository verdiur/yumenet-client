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

#include <cmath>
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
    m_app_rec()
{   
    // assign initial values to m_ratio and m_app_rec
    this->updateScaling();
}


App::~App()
{}


void App::loadGame() {
    p_game = new Game(m_game_width, m_game_height);
}


void App::unloadGame()
{
    delete p_game;
    p_game = nullptr;           // avoids having a dangling pointer
}


void App::updateWindowDimensions()
{
    m_window_width = GetScreenWidth();
    m_window_height = GetScreenHeight();
}


void App::updateScaling()
{
    // update scaling ratio
    m_ratio = fmin(m_window_width, m_window_height) / fmin(m_game_width, m_game_height);

    // update destination Rectangle
    int offset_x = (m_window_width - m_game_width * m_ratio) / 2;
    int offset_y = (m_window_height - m_game_height * m_ratio) / 2;
    m_app_rec = {
        (float) offset_x, 
        (float) offset_y,
        (float) m_game_width * m_ratio, 
        (float) m_game_height * m_ratio
    };
}


void App::run()
{
    // --------------------------------------------------------------------------------------------
    // INITIALIZE

    InitWindow(m_window_width, m_window_height, "yumenet");
    SetTargetFPS(m_fps);
    this->loadGame();

    // --------------------------------------------------------------------------------------------
    // GAME LOOP

    while (!WindowShouldClose())
    {
        // ----------------------------------------------------------------------------------------
        // UPDATE

        p_game->update();
        
        // ----------------------------------------------------------------------------------------
        // RENDER

        p_game->render();

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(
                p_game->getTarget().texture, 
                p_game->getRec(), 
                m_app_rec, 
                {}, 0, WHITE
            );
        EndDrawing();
    }

    // --------------------------------------------------------------------------------------------
    // DE-INITIALIZE

    this->unloadGame();
    CloseWindow();
}
