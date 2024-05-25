#include <entt/entt.hpp>
#include <raylib.h>
#include <raymath.h>

#include <comp/comp.hh>
#include <utils/types.hh>
#include <utils/dir_to_pos.hh>
#include <sys/update.hh>


bool is_player_moving(entt::registry &reg)
{
    bool result = false;
    auto view = reg.view<Player, IsMoving>();
    for (auto [ent, is_moving]: view.each())
    {
        // kind of gross but it works sooo
        result = is_moving.val;
    }
    return result;
}


void init_move_player(entt::registry &reg, DirEnum desired_dir)
{
    auto view = reg.view<Player, TilePos, Direction, CanMove, IsMoving, FromTilePos, ToTilePos, MoveProgress>();
    for (auto [ent, current_pos, dir, can_move, is_moving, from, to, progress]: view.each())
    {   
        dir.dir = desired_dir;
        if (can_move.val) {
            is_moving.val = true;
            from.pos = current_pos.pos;
            to.pos = dir_to_pos(desired_dir, from.pos);
            progress.amt = 0;
        }
    }
}


void move_characters(entt::registry &reg)
{
    auto view = reg.view<Player, TilePos, CanMove, IsMoving, FromTilePos, ToTilePos, MoveProgress>();
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
