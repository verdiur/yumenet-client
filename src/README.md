# Implementation details

> temporary file. will maybe move this to a documentation service later.

## Repo organization

The `src/` directory is organized in this way :

- `utils/` contains utilities;
- `comp/` contains all components;
- `sys/` contains all systems;
- `core/` contains the actual game logic.

`main.cpp` is compiled into an executable at compile time.

<!-- # Styling

- Maximum line length is 100 characters, without counting EOLs.
- Use 2 EOLs between each class/function block.
- Pointers are written like so: `type *p_name`. References are styled the same.
- Include guards are made with `#pragma once`.
- All files must contain a GPLv3 mention.
- Consult this for more info: [https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines] -->

## App functioning

> There has to be a way to simplify this. Will look into refactoring later.

### `App`

An `App` instance contains the entire game through a `Game` instance and handles the rendering of the scaled `Game` screen. The `App` instance is run in the `main()` function with `App::run()`.

### `Game`

A `Game` instance contains the actual game. It handles rendering on a `RenderTexture` (which is then scaled and displayed on the window through the `App` container) as well as the game logic.

### `World`

An `World` instance represents a world, and contains a `entt::registry`.

### Rendering systems

The systems for rendering all entities are written inside of `src/sys/render.cpp`. These systems are then called by the `World` instance through the `World::render()` method.

### Behavior systems

> TBD

The behavior systems are called by the `World` instance through the `World::update()` method.
