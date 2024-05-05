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

#include <entt/entt.hpp>
#include <raylib.h>
#include <raymath.h>

#include <utils/rng.hpp>
#include <utils/dir_to_pos.hpp>
#include <comp/direction.hpp>
#include <comp/move.hpp>
#include <comp/position.hpp>
#include <comp/types.hpp>
#include <core/consts.hpp>
#include <sys/move.hpp>


/// @brief Utility functions
namespace
{
    void randomMoveControl(
        IsMoving &is_moving, 
        TilePosition &current, 
        FromTilePosition &from, 
        ToTilePosition &to, 
        CharacterDirection direction
    ) {
        if (Rng::move(Rng::gen) < MOVE_PROBABILITY)
        {
            // init movement
            is_moving.answer = true;
            // choose direction
            direction.direction = CharacterDirection::D(Rng::direction(Rng::gen));
            // set from and to
            from.position = current.position;
            to.position = characterDirToPos(from.position, direction.direction);
        }
    }
}


void controlMoveNpc(entt::registry &reg)
{
    auto view = reg.view<Npc, IsMoving, TilePosition, FromTilePosition, ToTilePosition, CharacterDirection>();
    for (auto [entity, is_moving, current, from, to, direction]: view.each())
    {
        randomMoveControl(is_moving, current, from, to, direction);
    }
}


void moveCharacter(entt::registry &reg)
{
    auto view = reg.view<Npc, IsMoving, TilePosition, FromTilePosition, ToTilePosition, MoveLerp, Speed>();
    for (auto [entity, is_moving, current, from, to, move_lerp, speed]: view.each())
    {
        if (is_moving.answer == true) 
        {
            move_lerp.amount += MOVE_TIME / GetFrameTime() * speed.speed;

            // check if movement is finished
            if (move_lerp.amount >= 0) 
            {
                // reset state variables
                is_moving.answer = false;         
                move_lerp.amount = 0;
                // update position markers
                current.position = to.position;
                from.position = to.position;
            } 
            else 
            {
                // update current position with lerp
                current.position = Vector2Lerp(from.position, to.position, move_lerp.amount);
            }
        }
    }
}
