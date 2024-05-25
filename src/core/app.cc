#include <cassert>
#include <iostream>
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

void App::run(std::string cfg_path)
{
    assert(cfg_path != "");
    assert(cfg_path.back() == '/');

    /**********************************************************************************************
     * INIT
    */

        /**
         * Load config
        */

    // flags
    inih::INIReader cfg_flags(cfg_path + "flags.ini");
    bool cfg_flag_debug = cfg_flags.Get<bool>("flags", "debug");

    // controls
    // inih::INIReader cfg_controls(cfg_path + "controls.ini");
    // std::vector<int> cfg_ctrl_right =       cfg_controls.GetVector<int>("game", "right");
    // std::vector<int> cfg_ctrl_left =        cfg_controls.GetVector<int>("game", "left");
    // std::vector<int> cfg_ctrl_down =        cfg_controls.GetVector<int>("game", "down");
    // std::vector<int> cfg_ctrl_up =          cfg_controls.GetVector<int>("game", "up");
    // std::vector<int> cfg_ctrl_menu =        cfg_controls.GetVector<int>("game", "menu");
    // std::vector<int> cfg_ctrl_wake =        cfg_controls.GetVector<int>("game", "wake");
    // std::vector<int> cfg_ctrl_exam =        cfg_controls.GetVector<int>("game", "exam");
    // std::vector<int> cfg_ctrl_remove_effect = cfg_controls.GetVector<int>("game", "remove_effect");
    // std::vector<int> cfg_ctrl_menu_right =  cfg_controls.GetVector<int>("menu", "menu_right");
    // std::vector<int> cfg_ctrl_menu_left =   cfg_controls.GetVector<int>("menu", "menu_left");
    // std::vector<int> cfg_ctrl_menu_down =   cfg_controls.GetVector<int>("menu", "menu_down");
    // std::vector<int> cfg_ctrl_menu_up =     cfg_controls.GetVector<int>("menu", "menu_up");
    // std::vector<int> cfg_ctrl_menu_select = cfg_controls.GetVector<int>("menu", "menu_select");
    // std::vector<int> cfg_ctrl_menu_back =   cfg_controls.GetVector<int>("menu", "menu_back");

        /**
         * Init window
        */
        
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
    
        /**
         * Load game
        */
    
    game_->load_target();
    
        /**
         * Load debug elements
        */
    
    if (cfg_flag_debug) {
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
            if (cfg_flag_debug)
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
