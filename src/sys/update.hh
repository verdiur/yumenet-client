#pragma once
#include <vector>
#include <memory>
#include <entt/entt.hpp>

#include <utils/types.hh>
#include <core/world.hh>


/// @brief Check if player is moving
bool is_player_moving(entt::registry &reg);

void set_direction_player(entt::registry &reg, DirEnum desired_dir);

/// @brief For now, only checks world boundaries.
/// @brief Will check for collisions later.
void set_can_move_player(entt::registry &reg, World *w);

/// @brief Begin player movement.
void init_move_player(entt::registry &reg);

/// @brief Advance movement of characters.
void move_characters(entt::registry &reg);
