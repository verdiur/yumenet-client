#include <cassert>
#include <iostream>
#include <algorithm>

#include <raylib.h>
#include <json/json.hpp>

#include <utils/consts.hh>
#include <core/app.hh>

using json = nlohmann::json;


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

void App::draw_game(float scale)
{
    Rectangle src = { 0, 0, GAME_TARGET_WIDTH, -GAME_TARGET_HEIGHT };
    Rectangle dst = {
        (float) ((int) (window_width_ - GAME_TARGET_WIDTH * scale) / 2),
        (float) ((int) (window_height_ - GAME_TARGET_HEIGHT * scale) / 2),
        GAME_TARGET_WIDTH * scale,
        GAME_TARGET_HEIGHT * scale
    };
    DrawTexturePro(game_->get_target().texture, src, dst, {}, 0, WHITE);
}


int App::calc_game_scale_factor()
{
    int width_ratio = window_width_ / GAME_TARGET_WIDTH;
    int height_ratio = window_height_ / GAME_TARGET_HEIGHT;
    return std::min(width_ratio, height_ratio);
}


void App::update_window_dimensions()
{
    window_width_ = GetScreenWidth();
    window_height_ = GetScreenHeight();
}


/**************************************************************************************************
 * PUBLIC METHODS
*/

void App::run(json cfg)
{

    /**********************************************************************************************
     * INIT
    */

        /**
         * Init window
        */
        
    InitWindow(window_width_, window_height_, "yumenet");
    SetTargetFPS(window_fps_);

        /**
         * Read config
        */

    bool cfg_window_vsync =         cfg["window"]["vsync"];
    bool cfg_window_borderless =    cfg["window"]["borderless"];
    bool cfg_debug =                cfg["debug"]["debug"];
    
    if (cfg_window_vsync) {
        SetWindowState(FLAG_VSYNC_HINT);
    }
    if (cfg_window_borderless) {
        window_width_ = GetMonitorWidth(GetCurrentMonitor());
        window_height_ = GetMonitorHeight(GetCurrentMonitor());
        SetWindowState(FLAG_BORDERLESS_WINDOWED_MODE);
    }
    
        /**
         * Load game
        */
    
    game_->load_target();
    
        /**
         * Load debug
        */
    
    if (cfg_debug) {
        game_->load_debug_world();
    }

    /**********************************************************************************************
     * GAME LOOP
    */

    while (!WindowShouldClose())
    {
            /**
             * Update game
            */

        game_->update();

            /**
             * Draw
            */

        BeginDrawing();
            ClearBackground(BLACK);
            draw_game(calc_game_scale_factor());
            if (cfg_debug)
            {
                DrawFPS(4, 4);
            }
        EndDrawing();
    }

    /**********************************************************************************************
     * DEINIT
    */

    game_->unload_target();
    CloseWindow();
}
