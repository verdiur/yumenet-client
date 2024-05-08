#include <algorithm>
#include <raylib.h>

#include <core/app.hh>


App::App(const char *window_title_, int window_width_, int window_height_, int window_fps_, Game *game_):
    window_title(window_title_),
    window_width(window_width_),
    window_height(window_height_),
    window_fps(window_fps_),
    game(game_)
{}


/************************************************************************************************** 
 * PRIVATE METHODS
*/


void App::drawGame(float scale)
{
    float game_width = (float) game->getTarget().texture.width;
    float game_height = (float) game->getTarget().texture.height;

    Rectangle src = { 0, 0, game_width, -game_height};

    Rectangle dst = {
        (float) ((int) (window_width - game_width * scale) / 2),
        (float) ((int) (window_height - game_height * scale) / 2),
        game_width * scale,
        game_height * scale
    };
    
    DrawTexturePro(game->getTarget().texture, src, dst, {}, 0, WHITE);
}


int App::calcGameScaleFactor()
{
    int width_ratio = window_width / game->getTarget().texture.width;
    int height_ratio = window_height / game->getTarget().texture.height;
    return std::min(width_ratio, height_ratio);
}


void App::updateWindowDimensions() {
    window_width = GetScreenWidth();
    window_height = GetScreenHeight();
}


/************************************************************************************************** 
 * PUBLIC METHODS 
*/


void App::run()
{
    /* INIT */

    InitWindow(window_width, window_height, "yumenet");
    SetWindowMinSize(
        game->getTarget().texture.width, 
        game->getTarget().texture.height
    );
    SetWindowMaxSize(
        GetMonitorWidth(GetCurrentMonitor()), 
        GetMonitorHeight(GetCurrentMonitor())
    );
    SetTargetFPS(window_fps);
    game->loadGame();

    /* GAME LOOP */

    while (!WindowShouldClose())
    {
        // update
        // TODO: game update
        updateWindowDimensions();
        
        // render on target
        game->placeholderRender();

        // draw on window
        BeginDrawing();
            ClearBackground(BLACK);
            drawGame(calcGameScaleFactor());
        EndDrawing();
    }

    /* DE-INIT */

    game->unloadGame();
    CloseWindow();
}
