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

#include <comp/coord/position.hpp>
#include <comp/move.hpp>
#include <comp/tags.hpp>

#include <core/consts.hpp>

#include <sys/move.hpp>


void moveCharacter(entt::registry &reg)
{
    auto view = reg.view<IsMoving, TilePosition, MoveFromTile, MoveToTile, MoveLerp, MoveSpeed>();
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
