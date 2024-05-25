#pragma once
#include <entt/entt.hpp>


/// @brief World class.
/// @brief World size is determined by chunk amount in either direction.
/// @note `World` only handles update and render. Input handling is instead managed by `Game`.
class World
{
private:
    
    int max_chunk_x_;
    int max_chunk_y_;
    entt::registry reg_;

public:

    /// @brief Instance constructor.
    World(int max_chunk_x, int max_chunk_y);
    
    /// @brief Instance destructor.
    ~World();

    entt::registry &get_registry();

    /// @brief Update method called by `Game` instance.
    void update();

    /// @brief Render method called by `Game` instance.
    void render();

    /// @brief Load debug sprites and stuff...
    /// TODO: remove
    void debug_load();

    /// @brief Draw entities bounding boxes and origin as well as important info
    /// TODO: remove
    void debug_draw();
};
