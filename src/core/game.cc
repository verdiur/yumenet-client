#include <memory>
#include <iostream>

#include <utils/types.hh>
#include <sys/update.hh>
#include <core/world.hh>
#include <core/game.hh>

#include <sys/create.hh>


Game::Game(int width, int height):
    width_(width),
    height_(height),
    target_()
{}


RenderTexture &Game::get_target() {
    return target_;
}


std::unique_ptr<World> &Game::get_active_world() {
    return world_vec_[0];
}


void Game::load_target() {
    target_ = LoadRenderTexture(width_, height_);
}


void Game::unload_target() {
    UnloadRenderTexture(target_);
}


void Game::load_debug_world() {
    world_vec_.push_back(std::make_unique<World>(1, 1));
    world_vec_[0]->debug_load();
}


void Game::update()
{   
    /**
     * Input + update
    */

    world_vec_[0]->input();
    world_vec_[0]->update();

    /**
     * Render on target
    */

    BeginTextureMode(target_);
        ClearBackground(BLACK);
        world_vec_[0]->debug_draw();
    EndTextureMode();
}