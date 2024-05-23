#include <entt/entt.hpp>
#include <raylib.h>

#include <utils/consts.hh>
#include <comp/comp.hh>
#include <sys/render.hh>


void debug_draw_npc(entt::registry &reg)
{
    auto view = reg.view<TilePos, Origin, Rotation, Scale, DebugRec, DebugColor>();
    for (auto [ent, tile_pos, o, r, s, debug_rec, debug_color]: view.each()) {
        DrawRectangleLinesEx(
            {
                tile_pos.x * NPC_SIZE - o.x, 
                tile_pos.y * NPC_SIZE - o.y, 
                debug_rec.width,
                debug_rec.height,
            },
            1,
            debug_color.color
        );
    }
}