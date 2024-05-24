#pragma once


/**
 * consts.hh
 * This file includes all game constants.
*/


/// @brief Game target width in px.
inline const int GAME_TARGET_WIDTH = 640;

/// @brief Game target height in px.
inline const int GAME_TARGET_HEIGHT = 480;

/// @brief Tile size on screen in pixels.
inline const float TILE_SIZE = 16;

/// @brief Tile texture size in pixels. The original Yume Nikki draws textures at twice their size.
inline const float TILE_TEXTURE_SIZE = TILE_SIZE / 2;

/// @brief World chunk width in tiles.
/// @see `World.hh`
inline const int WORLD_CHUNK_WIDTH = GAME_TARGET_WIDTH / TILE_SIZE;

/// @brief World chunk height in tiles.
/// @see `World.hh`
inline const int WORLD_CHUNK_HEIGHT = GAME_TARGET_HEIGHT / TILE_SIZE;

/// @brief DEBUG: Size of the origin circle
inline const int DEBUG_ORIGIN_SIZE = 3;

/// @brief DEBUG: Thickness of the line
inline const int DEBUG_LINE_THICK = 1;
