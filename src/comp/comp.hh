#pragma once
#include <raylib.h>


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

struct TilePos  {   float x;    float y;    };
struct PixelPos {   float x;    float y;    };
struct Origin   {   float x;    float y;    };
struct Rotation {   float amt;  };
struct Scale    {   float amt;  };


/**************************************************************************************************
 * MOVEMENT
*/

struct CanMove      {   bool val;   };
struct IsMoving     {   bool val;   };
struct FromTilePos  {   float x;    float y;    };
struct ToTilePos    {   float x;    float y;    };

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
