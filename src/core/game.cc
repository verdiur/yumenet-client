#include <memory>

#include <utils/types.hh>
#include <sys/update.hh>
#include <core/world.hh>
#include <core/game.hh>

#include <sys/create.hh>


Game::Game(int width, int height):
    width_(width),
    height_(height),
    target_()
{}


RenderTexture &Game::get_target() {
    return target_;
}


std::unique_ptr<World> &Game::get_active_world() {
    return world_vec_[0];
}


void Game::load_target() {
    target_ = LoadRenderTexture(width_, height_);
}


void Game::unload_target() {
    UnloadRenderTexture(target_);
}


void Game::load_debug_world() {
    world_vec_.push_back(std::make_unique<World>(1, 1));
    world_vec_[0]->debug_load();
}


void Game::update()
{   
    /**
     * Input phase
    */

    if (!is_player_moving(world_vec_[0]->get_registry()))
    {
        if (IsKeyDown(KeyboardKey::KEY_RIGHT)) {
            init_move_player(world_vec_[0]->get_registry(), DirEnum::RIGHT);
        } 
        else if (IsKeyDown(KeyboardKey::KEY_LEFT)) {
            init_move_player(world_vec_[0]->get_registry(), DirEnum::LEFT);
        } 
        else if (IsKeyDown(KeyboardKey::KEY_DOWN)) {
            init_move_player(world_vec_[0]->get_registry(), DirEnum::DOWN);
        } 
        else if (IsKeyDown(KeyboardKey::KEY_UP)) {
            init_move_player(world_vec_[0]->get_registry(), DirEnum::UP);
        }
    }

    if (IsKeyPressed(KeyboardKey::KEY_KP_1)) {
        create_passive_npc(world_vec_[0]->get_registry(), {0, 0});
    }
        
    /**
     * Update phase
     * Simply calls active `World::update()` method.
    */

    world_vec_[0]->update();

    /**
     * Render on target
    */

    BeginTextureMode(target_);
        ClearBackground(BLACK);
        world_vec_[0]->debug_draw();
    EndTextureMode();
}