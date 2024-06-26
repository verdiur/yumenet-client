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

    std::unique_ptr<World> &get_active_world();

    /// @brief Load game target.
    void load_target();

    /// @brief Unload game target.
    void unload_target();

    /// Load a debug world into the instance.
    void load_debug_world();

    /// @brief Input, Update and Render method.
    void update();
};
