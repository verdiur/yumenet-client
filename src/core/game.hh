#pragma once
#include <memory>
#include <vector>
#include <raylib.h>

#include <core/world.hh>


class Game
{
private:

    int width_;
    int height_;
    RenderTexture target_;
    std::vector<std::unique_ptr<World>> world_vec_;

    bool debug_flag_;

public:

    /// @brief Instance constructor. Does not initialize the render target;
    /// @brief you have to load it after initializing the app (constructing a RenderTexture requires an OpenGL context)
    /// @param width 
    /// @param height 
    Game(int width, int height);

    /// @brief Get the instance's render target.
    /// @return Render target
    RenderTexture &get_target();

    /// @brief get the instance's debug flag.
    bool get_debug_flag() const;

    /// @brief set the instance's debug flag.
    void set_debug_flag(bool val);

    /// @brief Load game target.
    void load_target();

    /// @brief Unload game target.
    void unload_target();

    /// TODO: remove
    void load_debug_world();

    /// @brief Render the game instance on the `RenderTarget`.
    void render();
};
