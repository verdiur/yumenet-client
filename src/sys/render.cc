#include <entt/entt.hpp>
#include <raylib.h>

#include <utils/consts.hh>
#include <comp/comp.hh>
#include <sys/render.hh>


void debug_draw_characters(entt::registry &reg)
{
    auto view = reg.view<TilePos, Origin, Rotation, Scale, Direction, DebugRec, DebugColor>();
    for (auto [ent, tile_pos, o, r, s, dir, debug_rec, debug_color]: view.each())
    {    
        // draw box
        DrawRectangleLinesEx(
            {
                tile_pos.pos.x * TILE_SIZE - o.pos.x, 
                tile_pos.pos.y * TILE_SIZE - o.pos.y, 
                debug_rec.width,
                debug_rec.height,
            },
            DEBUG_LINE_THICK,
            debug_color.color
        );

        // draw origin
        DrawCircleLinesV(
            {
                tile_pos.pos.x * TILE_SIZE,
                tile_pos.pos.y * TILE_SIZE 
            }, 
            DEBUG_ORIGIN_SIZE, 
            debug_color.color
        );

        // draw direction line
        Vector2 pt1 = {
            tile_pos.pos.x * TILE_SIZE + debug_rec.width / 2 - o.pos.x, 
            tile_pos.pos.y * TILE_SIZE + debug_rec.height / 2 - o.pos.y,
        };
        Vector2 pt2 = {};
        switch (dir.dir) {
            case DirEnum::RIGHT:
                pt2 = {
                    pt1.x + DEBUG_DIRECTION_LINE_LENGTH,
                    pt1.y
                };
                break;
            case DirEnum::LEFT:
                pt2 = {
                    pt1.x - DEBUG_DIRECTION_LINE_LENGTH,
                    pt1.y
                };
                break;
            case DirEnum::DOWN:
                pt2 = {
                    pt1.x,
                    pt1.y + DEBUG_DIRECTION_LINE_LENGTH
                };
                break;
            case DirEnum::UP:
                pt2 = {
                    pt1.x,
                    pt1.y - DEBUG_DIRECTION_LINE_LENGTH
                };
                break;
            default:
                pt2 = pt1;
                break;
        }
        DrawLineV(pt1, pt2, debug_color.color);
    }
}
