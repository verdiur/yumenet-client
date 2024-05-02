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

World::World(std::string name, int chunk_width, int chunk_height):
    m_name(name),
    m_width(chunk_width * 40),
    m_height(chunk_height * 30)
{
    
}
