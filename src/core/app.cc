#include <algorithm>
#include <raylib.h>

#include <utils/consts.hh>
#include <core/app.hh>


App::App(const char *window_title_, int window_width_, int window_height_, int window_fps_):
    window_title(window_title_),
    window_width(window_width_),
    window_height(window_height_),
    window_fps(window_fps_),
    game(std::make_unique<Game>(GAME_WIDTH, GAME_HEIGHT))
{}


/************************************************************************************************** 
 * PRIVATE METHODS
*/


void App::drawGame(float scale)
{
    Rectangle src = { 0, 0, GAME_WIDTH, -GAME_HEIGHT };
    Rectangle dst = {
        (float) ((int) (window_width - GAME_WIDTH * scale) / 2),
        (float) ((int) (window_height - GAME_HEIGHT * scale) / 2),
        GAME_WIDTH * scale,
        GAME_HEIGHT * scale
    };
    
    DrawTexturePro(game->getTarget().texture, src, dst, {}, 0, WHITE);
}


int App::calcGameScaleFactor()
{
    int width_ratio = window_width / GAME_WIDTH;
    int height_ratio = window_height / GAME_HEIGHT;
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
        GAME_WIDTH, 
        GAME_HEIGHT
    );
    SetWindowMaxSize(
        GetMonitorWidth(GetCurrentMonitor()), 
        GetMonitorHeight(GetCurrentMonitor())
    );
    SetTargetFPS(window_fps);

    // load 
    game->loadTarget();

    /* GAME LOOP */

    while (!WindowShouldClose())
    {
        // update
        // TODO: game update
        
        // render on target
        game->render();

        // draw on window
        BeginDrawing();
            ClearBackground(BLACK);
            drawGame(calcGameScaleFactor());
        EndDrawing();
    }

    /* DE-INIT */

    game->unloadTarget();
    CloseWindow();
}
