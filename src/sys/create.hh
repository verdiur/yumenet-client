#pragma once
#include <entt/entt.hpp>


/// @brief Create player entity
void create_player(entt::registry &reg, float x, float y);

/// @brief Create passive NPC entity
void create_passive_npc(entt::registry &reg, float x, float y);

/// @brief Create chaser NPC entity
void create_chaser_npc(entt::registry &reg, float x, float y, bool is_hurt);
