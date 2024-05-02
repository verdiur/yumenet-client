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

#include <cassert>
#include <raylib.h>
#include <core/game.hpp>


Game::Game(int width, int height):
    m_width(width),
    m_height(height),
    m_target(),
    m_rec({ 0, 0, (float)m_width, -(float)m_height })
{
    assert(IsWindowReady());
    m_target = LoadRenderTexture(m_width, m_height);
}


Game::~Game() {
    UnloadRenderTexture(m_target);
}


RenderTexture Game::getTarget() { return m_target; }
Rectangle Game::getRec()        { return m_rec; }
int Game::getWidth()            { return m_width; }
int Game::getWidth() const      { return m_width; }
int Game::getHeight()           { return m_height; }
int Game::getHeight() const     { return m_height; }


void Game::update()
{}


void Game::render() {
    BeginTextureMode(m_target);
        ClearBackground(BLACK);             // TODO:
    EndTextureMode();
}
