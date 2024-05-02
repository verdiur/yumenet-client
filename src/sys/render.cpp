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
#include <entt/entt.hpp>
#include <comp/position.hpp>
#include <comp/rotation.hpp>
#include <comp/scale.hpp>
#include <comp/render.hpp>
#include <comp/types.hpp>
#include <core/consts.hpp>
#include <sys/render.hpp>


void tileRender(entt::registry &reg)
{
    // sort registry
    reg.sort<RenderOrder>(
        [](const auto &lhs, const auto &rhs) {
            return (lhs.layer < rhs.layer) && (lhs.y < rhs.y);
        }
    );
    // create view
    auto view = reg.view<TilePosition, Rotation, Scale, RenderOrder, Sprite>();
    view.use<RenderOrder>();
    // draw
    for (auto [entity, tile_position, rotation, scale, render_order, sprite]: view.each()) {
        DrawTexturePro(
            *sprite.p_sheet, 
            *sprite.p_frame, 
            {
                (float)tile_position.x * TILE_SIZE, 
                (float)tile_position.y * TILE_SIZE,
                TILE_SIZE,
                TILE_SIZE},
            {}, 0, WHITE
        );
    }
}

