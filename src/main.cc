#include <raylib.h>

#include <core/app.hh>
#include <core/game.hh>


int main(void)
{
    int sw = 640+101;
    int sh = 480+101;
    int fps = 60;

    Game game(640, 480);
    App app("yumenet", sw, sh, fps, &game);

    app.run();
}
