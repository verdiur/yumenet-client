#pragma once
#include <entt/entt.hpp>


/// @brief World class.
/// @brief World size is determined by chunk amount in either direction.
/// @note `World` only handles update and render. Input handling is instead managed by `Game`.
class World
{
private:
    
    int chunk_width_;
    int chunk_height_;
    entt::registry reg_;

public:

    /// @brief Instance constructor.
    World(int chunk_width, int chunk_height);
    
    /// @brief Instance destructor.
    ~World();

    entt::registry &get_registry();
    int get_chunk_width() const;
    int get_chunk_height() const;

    /// @brief Input method called by `Game` instance
    void input();

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
