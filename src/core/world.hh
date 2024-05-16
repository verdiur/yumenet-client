#pragma once
#include <entt/entt.hpp>

/// @brief World class.
/// @brief World size is determined by chunk amount in either direction.
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
};
