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

#include <entt/entt.hpp>

#include <core/consts.hpp>
#include <core/world.hpp>
#include <sys/move.hpp>
#include <sys/render.hpp>


World::World(std::string name, std::string author, int chunk_width, int chunk_height):
    m_name(name),
    m_author(author),
    m_chunk_width(chunk_width),
    m_chunk_height(chunk_height),
    m_reg()
{}


World::World(World &world)
{
    // TODO:
}


World::~World()
{
    m_reg.clear();
}


void World::update()
{
    // TODO:

    // Movement control
    controlMoveNpc(m_reg);
    controlMovePlayer(m_reg);

    // Movement execution
    moveCharacter(m_reg);
}


void World::render()
{
    // TODO:
    renderTile(m_reg);
}
