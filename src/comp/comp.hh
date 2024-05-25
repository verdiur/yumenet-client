#pragma once
#include <raylib.h>

#include <utils/types.hh>


/**
 * comp.hh
 * This file includes all component declarations.
*/


/**************************************************************************************************
 * TAGS
*/

struct Player {};
struct Chaser {};


/**************************************************************************************************
 * TRANSFORM
*/

struct TilePos  {   Vector2 pos;    };
struct PixelPos {   Vector2 pos;    };
struct Origin   {   Vector2 pos;    };
struct Rotation {   float amt;  };
struct Scale    {   float amt;  };

struct Direction    {   DirEnum dir;    };

/**************************************************************************************************
 * MOVEMENT
*/

struct CanMove      {   bool val;   };
struct IsMoving     {   bool val;   };
struct FromTilePos  {   Vector2 pos;    };
struct ToTilePos    {   Vector2 pos;    };

/// @brief Movement progression component. `amt` should be between 0 and 1.
struct MoveProgress {   float amt;  };


/**************************************************************************************************
 * STATE
*/

    /** Hurt States */

struct IsHurt   {   bool val;   };
struct IsDead   {   bool val;   };


/**************************************************************************************************
 * DRAW
*/

struct DebugRec     {   float width;    float height;   };
struct DebugColor   {   Color color;    };
