#pragma once
#include <memory>
#include <string>

#include <raylib.h>
#include <core/game.hh>


/// @brief App container.
/// @brief Pretty much contains everything.
class App
{
private:

    const char *window_title;
    int window_width;
    int window_height;
    int window_fps;
    std::unique_ptr<Game> game;

private:

    /// @brief Utility function that draws the game on the window.
    void drawGame(float scale);

    /// @brief Calculate game scale factor.
    /// @return Factor to scale game render target
    int calcGameScaleFactor();

    /// @brief Update window dimensions. Useful in case of window resizing.
    void updateWindowDimensions();

public:

    /// @brief Instance constructor.
    /// @param window_title_ title of the window
    /// @param window_width_ width of the window
    /// @param window_height_ height of the window
    /// @param window_fps_ fps to target
    /// @param game_ pointer to `Game` instance
    App(const char *window_title_,  int window_width_, int window_height_, int window_fps_);

    /// @brief Initializes, runs, unloads and closes the app.
    void run();
};
