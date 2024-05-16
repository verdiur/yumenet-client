#include <entt/entt.hpp>

#include <utils/consts.hh>
#include <core/world.hh>

World::World(int max_chunk_x, int max_chunk_y):
    max_chunk_x_(max_chunk_x),
    max_chunk_y_(max_chunk_y),
    reg_()
{}


World::~World()
{}
