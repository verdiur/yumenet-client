#include <core/game.hh>


Game::Game(int width_, int height_):
    width(width_),
    height(height_),
    target()
{}


void Game::loadGame() {
    target = LoadRenderTexture(width, height);
}


void Game::unloadGame() {
    UnloadRenderTexture(target);
}


RenderTexture &Game::getTarget() {
    return target;
}


void Game::placeholderRender() {
    BeginTextureMode(target);

        ClearBackground(BLACK);
        DrawText("placeholder", 10, 10, 10, WHITE);

    EndTextureMode();
}
