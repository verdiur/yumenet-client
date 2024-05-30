#include <entt/entt.hpp>

#include <utils/consts.hh>
#include <sys/create.hh>
#include <sys/update.hh>
#include <sys/render.hh>
#include <core/world.hh>


World::World(int chunk_width, int chunk_height):
    chunk_width_(chunk_width),
    chunk_height_(chunk_height),
    reg_()
{}


World::~World()
{}


entt::registry &World::get_registry() {
    return reg_;
}


int World::get_chunk_width() const {
    return chunk_width_;
}


int World::get_chunk_height() const {
    return chunk_height_;
}


void World::input()
{
    if (!is_player_moving(reg_))
    {
        if (IsKeyDown(KeyboardKey::KEY_RIGHT)) {
            set_direction_player(reg_, DirEnum::RIGHT);
            set_can_move_player(reg_, this);
            init_move_player(reg_);
        }
        else if (IsKeyDown(KeyboardKey::KEY_LEFT)) {
            set_direction_player(reg_, DirEnum::LEFT);
            set_can_move_player(reg_, this);
            init_move_player(reg_);
        } 
        else if (IsKeyDown(KeyboardKey::KEY_UP)) {
            set_direction_player(reg_, DirEnum::UP);
            set_can_move_player(reg_, this);
            init_move_player(reg_);
        }
        else if (IsKeyDown(KeyboardKey::KEY_DOWN)) {
            set_direction_player(reg_, DirEnum::DOWN);
            set_can_move_player(reg_, this);
            init_move_player(reg_);
        }
    }

    if (IsKeyPressed(KeyboardKey::KEY_KP_1)) {
        create_passive_npc(reg_, {0, 0});
    }
}


void World::update() {
    move_characters(reg_);
}


void World::render() {
    debug_draw();
}


void World::debug_load() {
    create_player(reg_, Vector2{10, 10});
}


void World::debug_draw() {
    debug_draw_characters(reg_);
}
