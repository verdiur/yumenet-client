#include <entt/entt.hpp>

#include <utils/consts.hh>
#include <comp/comp.hh>
#include <sys/create.hh>


void create_player(entt::registry &reg, float x, float y)
{
    const entt::entity ent = reg.create();
    
    // tags
    reg.emplace<Player>     (ent);

    // transform
    reg.emplace<TilePos>    (ent, x, y);
    reg.emplace<Origin>     (ent, 0, TILE_SIZE);
    reg.emplace<Rotation>   (ent, 0);
    reg.emplace<Scale>      (ent, 1);

    // movement
    reg.emplace<CanMove>        (ent, true);
    reg.emplace<IsMoving>       (ent, false);
    reg.emplace<FromTilePos>    (ent, x, y);
    reg.emplace<ToTilePos>      (ent, x, y);
    reg.emplace<MoveProgress>   (ent, 0);

    // state
    reg.emplace<IsHurt>   (ent, false);

    // draw
    reg.emplace<DebugRec>   (ent, Rectangle{0, 0, (float) TILE_SIZE, TILE_SIZE * 2});
    reg.emplace<DebugColor> (ent, WHITE);
}


void create_passive_npc(entt::registry &reg, float x, float y)
{
    const entt::entity ent = reg.create();
    
    // transform
    reg.emplace<TilePos>    (ent, x, y);
    reg.emplace<Origin>     (ent, 0, TILE_SIZE);
    reg.emplace<Rotation>   (ent, 0);
    reg.emplace<Scale>      (ent, 1);

    // movement
    reg.emplace<CanMove>        (ent, true);
    reg.emplace<IsMoving>       (ent, false);
    reg.emplace<FromTilePos>    (ent, x, y);
    reg.emplace<ToTilePos>      (ent, x, y);
    reg.emplace<MoveProgress>   (ent, 0);

    // state
    reg.emplace<IsHurt> (ent, false);
    reg.emplace<IsDead> (ent, false);

    // draw
    reg.emplace<DebugRec>   (ent, Rectangle{0, 0, (float) TILE_SIZE, TILE_SIZE * 2});
    reg.emplace<DebugColor> (ent, GREEN);
}


void create_chaser_npc(entt::registry &reg, float x, float y, bool is_hurt)
{
    const entt::entity ent = reg.create();

    // tags
    reg.emplace<Chaser>     (ent);
    
    // transform
    reg.emplace<TilePos>    (ent, x, y);
    reg.emplace<Origin>     (ent, 0, TILE_SIZE);
    reg.emplace<Rotation>   (ent, 0);
    reg.emplace<Scale>      (ent, 1);

    // movement
    reg.emplace<CanMove>        (ent, true);
    reg.emplace<IsMoving>       (ent, false);
    reg.emplace<FromTilePos>    (ent, x, y);
    reg.emplace<ToTilePos>      (ent, x, y);
    reg.emplace<MoveProgress>   (ent, 0);

    // state
    reg.emplace<IsHurt> (ent, is_hurt);

    // draw
    reg.emplace<DebugRec>   (ent, Rectangle{0, 0, (float) TILE_SIZE, TILE_SIZE * 2});
    reg.emplace<DebugColor> (ent, GREEN);
}
