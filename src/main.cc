/**
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
