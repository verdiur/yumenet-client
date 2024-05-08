#pragma once
#include <string>

#include <raylib.h>

#include <core/game.hh>


/// @brief App container.
class App
{
private:

    const char *window_title;
    int window_width;
    int window_height;
    int window_fps;
    Game *game;

private:

    /// @brief Utility function that draws the game on the window.
    void drawGame(float scale);

public:

    /// @brief Instance constructor.
    /// @param window_title_ title of the window
    /// @param window_width_ width of the window
    /// @param window_height_ height of the window
    /// @param window_fps_ fps to target
    /// @param game_ pointer to `Game` instance
    App(const char *window_title_,  int window_width_, int window_height_, int window_fps_, Game *game_);

    /// @brief App instances cannot be copied.
    App(const App&) = delete;

    /// @brief Initializes, runs, unloads and closes the app.
    void run();
};
