#pragma once
#include <vector>
#include <entt/entt.hpp>

#include <utils/types.hh>


/// @brief Check if player is moving
bool is_player_moving(entt::registry &reg);

/// @brief Initialize player movement.
void init_move_player(entt::registry &reg, DirEnum dir);

/// @brief Advance movement of characters.
void move_characters(entt::registry &reg);
