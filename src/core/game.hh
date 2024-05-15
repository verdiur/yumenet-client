#pragma once
#include <memory>
#include <vector>
#include <raylib.h>

#include <core/world.hh>


class Game
{
private:

    int width;
    int height;
    RenderTexture target;
    std::vector<std::unique_ptr<World>> world_vec;

public:

    /// @brief Instance constructor. Does not initialize the render target;
    /// @brief you have to load it after initializing the app (constructing a RenderTexture requires an OpenGL context)
    /// @param width_ 
    /// @param height_ 
    Game(int width_, int height_);

    /// @brief Game instances cannot be copied. 
    Game(const Game&) = delete;

    /// @brief Get the instance's render target.
    /// @return Render target
    RenderTexture &getTarget();

    /// @brief Load game assets.
    void loadGameAssets();

    /// @brief Unload all assets loaded in App::loadGame().
    void unloadGameAssets();

    /// @brief Render the game instance on the `RenderTarget`.
    void render();
};
