#include <algorithm>
#include <raylib.h>

#include <utils/consts.hh>
#include <core/app.hh>


App::App(const char *window_title, int window_width, int window_height, int window_fps):
    window_title_(window_title),
    window_width_(window_width),
    window_height_(window_height),
    window_fps_(window_fps),
    game_(std::make_unique<Game>(GAME_TARGET_WIDTH, GAME_TARGET_HEIGHT))
{}


/************************************************************************************************** 
 * PRIVATE METHODS
*/


void App::drawGame(float scale) {
    Rectangle src = { 0, 0, GAME_TARGET_WIDTH, -GAME_TARGET_HEIGHT };
    Rectangle dst = {
        (float) ((int) (window_width_ - GAME_TARGET_WIDTH * scale) / 2),
        (float) ((int) (window_height_ - GAME_TARGET_HEIGHT * scale) / 2),
        GAME_TARGET_WIDTH * scale,
        GAME_TARGET_HEIGHT * scale
    };
    DrawTexturePro(game_->getTarget().texture, src, dst, {}, 0, WHITE);
}


int App::calcGameScaleFactor() {
    int width_ratio = window_width_ / GAME_TARGET_WIDTH;
    int height_ratio = window_height_ / GAME_TARGET_HEIGHT;
    return std::min(width_ratio, height_ratio);
}


void App::updateWindowDimensions() {
    window_width_ = GetScreenWidth();
    window_height_ = GetScreenHeight();
}


/************************************************************************************************** 
 * PUBLIC METHODS 
*/


void App::run()
{
    /* INIT */

    InitWindow(window_width_, window_height_, "yumenet");
    SetWindowMinSize(
        GAME_TARGET_WIDTH, 
        GAME_TARGET_HEIGHT
    );
    SetWindowMaxSize(
        GetMonitorWidth(GetCurrentMonitor()), 
        GetMonitorHeight(GetCurrentMonitor())
    );
    SetTargetFPS(window_fps_);

    // load 
    game_->loadTarget();

    /* GAME LOOP */

    while (!WindowShouldClose())
    {
        // update
        // TODO: game update
        
        // render on target
        game_->render();

        // draw on window
        BeginDrawing();
            ClearBackground(BLACK);
            drawGame(calcGameScaleFactor());
        EndDrawing();
    }

    /* DE-INIT */

    game_->unloadTarget();
    CloseWindow();
}
