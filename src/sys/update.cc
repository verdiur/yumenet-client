#include <memory>
#include <iostream>
#include <entt/entt.hpp>
#include <raylib.h>
#include <raymath.h>

#include <comp/comp.hh>
#include <utils/consts.hh>
#include <utils/types.hh>
#include <utils/dir_to_pos.hh>
#include <core/world.hh>
#include <sys/update.hh>


bool is_player_moving(entt::registry &reg)
{
    bool result = false;
    auto view = reg.view<Player, IsMoving>();
    for (auto [ent, is_moving]: view.each())
    {
        // not scalable but it works for now,
        // as long as only 1 player entity is present in the registry
        result = is_moving.val;
    }
    return result;
}


void set_direction_player(entt::registry &reg, DirEnum desired_dir)
{
    auto view = reg.view<Player, Direction>();
    for (auto [ent, dir]: view.each()) {
        dir.dir = desired_dir;
    }
}


void set_can_move_player(entt::registry &reg, World *w) {
    auto view = reg.view<Player, TilePos, Direction, CanMove>();
    for (auto [ent, pos, dir, can_move]: view.each())
    {   
        // calculate desired direction
        Vector2 to = dir_to_pos(dir.dir, pos.pos);
        // check for world boundaries
        switch (dir.dir) {
            case UP:    
                can_move.val = (to.y >= 0);
                break;
            case DOWN:  
                can_move.val = (to.y < w->get_chunk_height() * WORLD_CHUNK_HEIGHT);
                break;
            case LEFT:  
                can_move.val = (to.x >= 0);
                break;
            case RIGHT:
                can_move.val = (to.x < w->get_chunk_width() * WORLD_CHUNK_WIDTH);
                break;
        }
    }
}


void init_move_player(entt::registry &reg)
{   
    auto view = reg.view<Player, TilePos, Direction, CanMove, IsMoving, FromTilePos, ToTilePos, MoveProgress>();
    for (auto [ent, current_pos, dir, can_move, is_moving, from, to, progress]: view.each())
    {   
        if (can_move.val) {
            is_moving.val = true;
            from.pos = current_pos.pos;
            to.pos = dir_to_pos(dir.dir, from.pos);
            progress.amt = 0;
        }
    }
}


void move_characters(entt::registry &reg)
{
    auto view = reg.view<TilePos, CanMove, IsMoving, FromTilePos, ToTilePos, MoveProgress>();
    for (auto [ent, current, can_move, is_moving, from, to, progress]: view.each())
    {   
        // advance movement
        if (is_moving.val) {
            progress.amt += 4 * GetFrameTime();
            current.pos = Vector2Lerp(from.pos, to.pos, progress.amt);
        }
        // check movement progression
        if (progress.amt >= 1.f) {
            // stop movement and correct position
            is_moving.val = false;
            current.pos = to.pos;
            // reset from and to
            from.pos = current.pos;
            to.pos = current.pos;
        }
    }
}
