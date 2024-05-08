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
 * PRIVATE UTILS 
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


/************************************************************************************************** 
 * METHODS 
*/


void App::run()
{
    /* INIT */

    InitWindow(window_width, window_height, "yumenet");
    SetTargetFPS(window_fps);

    game->loadGame();

    /* GAME LOOP */

    while (!WindowShouldClose())
    {
        // update game
        // TODO:
        
        // render game on target
        game->placeholderRender();

        // draw on window
        BeginDrawing();
            ClearBackground(BLACK);
            drawGame(1);
            DrawFPS(10, 10);
        EndDrawing();
    }

    /* DE-INIT */

    game->unloadGame();
    CloseWindow();
}
