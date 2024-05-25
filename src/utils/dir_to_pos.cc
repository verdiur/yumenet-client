#include <raylib.h>

#include <utils/types.hh>
#include <utils/dir_to_pos.hh> 


Vector2 dir_to_pos(const DirEnum dir, const Vector2 from)
{
    switch (dir) {
        case DirEnum::RIGHT:    return Vector2{ from.x + 2.f, from.y };
        case DirEnum::LEFT:     return Vector2{ from.x - 2.f, from.y };
        case DirEnum::DOWN:     return Vector2{ from.x, from.y + 2.f };
        case DirEnum::UP:       return Vector2{ from.x, from.y - 2.f };
        default:                return from;
    }
}
