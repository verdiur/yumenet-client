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

#include <entt/entt.hpp>


class World
{
private:

    std::string m_name;
    std::string m_author;
    int m_chunk_width;              // the width of a chunk is 40 tiles
    int m_chunk_height;             // the height of a chunk is 30 tiles
    entt::registry m_reg;

public:

    World(std::string name, std::string author, int chunk_width, int chunk_height);
    World (World &world);
    ~World();

    entt::registry &getRegistry();

    void update();
    void render();
};
