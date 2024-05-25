#include <entt/entt.hpp>
#include <raylib.h>

#include <utils/consts.hh>
#include <comp/comp.hh>
#include <sys/create.hh>


void create_player(entt::registry &reg, Vector2 pos)
{
    const entt::entity ent = reg.create();
    
    // tags
    reg.emplace<Player>     (ent);

    // transform
    reg.emplace<TilePos>    (ent, pos);
    reg.emplace<Origin>     (ent, 0.f, TILE_SIZE * 2);
    reg.emplace<Rotation>   (ent, 0.f);
    reg.emplace<Scale>      (ent, 1.f);
    reg.emplace<Direction>  (ent, DirEnum::DOWN);

    // movement
    reg.emplace<CanMove>        (ent, true);
    reg.emplace<IsMoving>       (ent, false);
    reg.emplace<FromTilePos>    (ent, pos);
    reg.emplace<ToTilePos>      (ent, pos);
    reg.emplace<MoveProgress>   (ent, 0.f);

    // state
    reg.emplace<IsHurt>   (ent, false);

    // draw
    reg.emplace<DebugRec>   (ent, TILE_SIZE * 2, TILE_SIZE * 4);
    reg.emplace<DebugColor> (ent, WHITE);
}


void create_passive_npc(entt::registry &reg, Vector2 pos)
{
    const entt::entity ent = reg.create();
    
    // transform
    reg.emplace<TilePos>    (ent, pos);
    reg.emplace<Origin>     (ent, 0.f, TILE_SIZE * 2);
    reg.emplace<Rotation>   (ent, 0.f);
    reg.emplace<Scale>      (ent, 1.f);
    reg.emplace<Direction>  (ent, DirEnum::DOWN);

    // movement
    reg.emplace<CanMove>        (ent, true);
    reg.emplace<IsMoving>       (ent, false);
    reg.emplace<FromTilePos>    (ent, pos);
    reg.emplace<ToTilePos>      (ent, pos);
    reg.emplace<MoveProgress>   (ent, 0.f);

    // state
    reg.emplace<IsHurt> (ent, false);
    reg.emplace<IsDead> (ent, false);

    // draw
    reg.emplace<DebugRec>   (ent, TILE_SIZE * 2, TILE_SIZE * 4);
    reg.emplace<DebugColor> (ent, GREEN);
}


void create_chaser_npc(entt::registry &reg, Vector2 pos, bool is_hurt)
{
    const entt::entity ent = reg.create();

    // tags
    reg.emplace<Chaser>     (ent);
    
    // transform
    reg.emplace<TilePos>    (ent, pos);
    reg.emplace<Origin>     (ent, 0.f, TILE_SIZE * 2);
    reg.emplace<Rotation>   (ent, 0.f);
    reg.emplace<Scale>      (ent, 1.f);
    reg.emplace<Direction>  (ent, DirEnum::DOWN);

    // movement
    reg.emplace<CanMove>        (ent, true);
    reg.emplace<IsMoving>       (ent, false);
    reg.emplace<FromTilePos>    (ent, pos);
    reg.emplace<ToTilePos>      (ent, pos);
    reg.emplace<MoveProgress>   (ent, 0.f);

    // state
    reg.emplace<IsHurt> (ent, is_hurt);

    // draw
    reg.emplace<DebugRec>   (ent, TILE_SIZE * 2, TILE_SIZE * 4);
    reg.emplace<DebugColor> (ent, GREEN);
}
