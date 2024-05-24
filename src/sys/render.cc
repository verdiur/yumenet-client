#include <entt/entt.hpp>
#include <raylib.h>

#include <utils/consts.hh>
#include <comp/comp.hh>
#include <sys/render.hh>


void debug_draw_npc(entt::registry &reg)
{
    auto view = reg.view<TilePos, Origin, Rotation, Scale, DebugRec, DebugColor>();
    for (auto [ent, tile_pos, o, r, s, debug_rec, debug_color]: view.each())
    {    
        // draw box
        DrawRectangleLinesEx(
            {
                tile_pos.x * TILE_SIZE * 2 - o.x, 
                tile_pos.y * TILE_SIZE * 2 - o.y, 
                debug_rec.width,
                debug_rec.height,
            },
            DEBUG_LINE_THICK,
            debug_color.color
        );

        // draw origin
        DrawCircleLinesV(
            { tile_pos.x * TILE_SIZE * 2, tile_pos.y * TILE_SIZE * 2 }, 
            DEBUG_ORIGIN_SIZE, 
            debug_color.color
        );
    }
}