#include <entt/entt.hpp>
#include <raylib.h>

#include <utils/consts.hh>
#include <comp/comp.hh>
#include <sys/render.hh>


void draw_debug(entt::registry &reg)
{
    auto view = reg.view<TilePos, Origin, Rotation, Scale, DebugRec, DebugColor>();
    for (auto [ent, tile_pos, o, r, s, debug_rec, debug_color]: view.each()) {
        DrawRectangleLinesEx(
            {
                tile_pos.x * TILE_SIZE, 
                tile_pos.y * TILE_SIZE, 
                debug_rec.width,
                debug_rec.height,
            },
            1,
            debug_color.color
        );
    }
}
