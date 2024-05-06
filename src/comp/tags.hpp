/**
 * This file is part of yumenet.
 *
 * yumenet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * yumenet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with yumenet. If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

/**
 * This file stores all entity tags. These type components allow to differentiate entities when
 * all other components fail to do so.
*/


/// @brief Tile component.
struct Tile {};


/// @brief Player component.
struct Player {};


/// @brief NPC component.
struct Npc {};


/// @brief Portal component.
/// @brief Portals allow the player to teleport to other worlds.
struct Portal {};
