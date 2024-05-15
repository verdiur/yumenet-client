#include <memory>

#include <core/world.hh>
#include <core/game.hh>


Game::Game(int width_, int height_):
    width(width_),
    height(height_),
    target()
{}


RenderTexture &Game::getTarget() {
    return target;
}


void Game::loadTarget() {
    target = LoadRenderTexture(width, height);
}


void Game::unloadTarget() {
    UnloadRenderTexture(target);
}


void Game::render()
{
    BeginTextureMode(target);
        ClearBackground(BLACK);
    EndTextureMode();
}
