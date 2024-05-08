#pragma once

#include <raylib.h>


class Game
{
private:

    int width;
    int height;
    RenderTexture target;

public:

    /// @brief Instance constructor. Does not initialize the render target;
    /// @brief you have to load it after initializing the app (constructing a RenderTexture requires an OpenGL context)
    /// @param width_ 
    /// @param height_ 
    Game(int width_, int height_);

    /// @brief Game instances cannot be copied. 
    Game(const Game&) = delete;

    /// @brief Load game.
    void loadGame();

    /// @brief Unload game.
    void unloadGame();

    /// @brief Get the instance's render target.
    /// @return Render target
    RenderTexture &getTarget();

    void placeholderRender();
};
