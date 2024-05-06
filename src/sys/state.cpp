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

#include <utils/rng.hpp>
#include <utils/dir_to_pos.hpp>

#include <comp/coord/direction.hpp>
#include <comp/coord/position.hpp>
#include <comp/move.hpp>
#include <comp/tags.hpp>

#include <core/consts.hpp>

#include <sys/state.hpp>


namespace
{
    void randomMoveControl(
        IsMoving &is_moving, 
        TilePosition &current, 
        MoveFromTile &from, 
        MoveToTile &to, 
        CharacterDirection direction
    ) {
        if (Rng::move(Rng::gen) < MOVE_PROBABILITY && is_moving.answer == false)
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


void updateMoveNpc(entt::registry &reg)
{
    auto view = reg.view<Npc, IsMoving, TilePosition, MoveFromTile, MoveToTile, CharacterDirection>();
    for (auto [entity, is_moving, current, from, to, direction]: view.each())
    {
        randomMoveControl(is_moving, current, from, to, direction);
    }
}

