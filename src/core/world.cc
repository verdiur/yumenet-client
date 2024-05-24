#include <entt/entt.hpp>

#include <utils/consts.hh>
#include <sys/create.hh>
#include <sys/render.hh>
#include <core/world.hh>


World::World(int max_chunk_x, int max_chunk_y):
    max_chunk_x_(max_chunk_x),
    max_chunk_y_(max_chunk_y),
    reg_()
{}


World::~World()
{}


void World::update() {
    
}


void World::render() {
    debug_draw();
}


void World::debug_load() {
    create_player(reg_, 10, 10);
}


void World::debug_draw() {
    debug_draw_npc(reg_);
}
