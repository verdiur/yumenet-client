#pragma once
#include <entt/entt.hpp>
#include <raylib.h>


/// @brief Create player entity
void create_player(entt::registry &reg, const Vector2 pos);

/// @brief Create passive NPC entity
void create_passive_npc(entt::registry &reg, const Vector2 pos);

/// @brief Create chaser NPC entity
void create_chaser_npc(entt::registry &reg, const Vector2 pos, bool is_hurt);
