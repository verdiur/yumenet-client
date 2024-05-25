#pragma once
#include <raylib.h>

#include <utils/types.hh>


/// @brief Calculates destination vector from a departure pos and a direction.
/// @param dir direction
/// @param from position vector
/// @return destination vector
Vector2 dir_to_pos(const DirEnum dir, const Vector2 from);
