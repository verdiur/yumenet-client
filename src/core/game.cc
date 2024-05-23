#include <memory>

#include <core/world.hh>
#include <core/game.hh>


Game::Game(int width, int height):
    width_(width),
    height_(height),
    target_()
{}


RenderTexture &Game::get_target() {
    return target_;
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


void Game::render()
{
    BeginTextureMode(target_);
        ClearBackground(BLACK);
        world_vec_[0]->debug_draw();
    EndTextureMode();
}
