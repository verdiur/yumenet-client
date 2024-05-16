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

    const char *window_title_;
    int window_width_;
    int window_height_;
    int window_fps_;
    std::unique_ptr<Game> game_;

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
    /// @param window_title title of the window
    /// @param window_width width of the window
    /// @param window_height height of the window
    /// @param window_fps fps to target
    App(const char *window_title,  int window_width, int window_height, int window_fps);

    /// @brief Initializes, runs, unloads and closes the app.
    void run();
};
