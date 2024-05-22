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


void Game::render()
{
    BeginTextureMode(target_);
        ClearBackground(BLACK);
    EndTextureMode();
}
