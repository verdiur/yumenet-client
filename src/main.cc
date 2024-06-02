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

#include <fstream>
#include <iostream>
#include <json/json.hpp>
#include <raylib.h>

#include <core/app.hh>
#include <core/game.hh>


int main(void)
{
    // load config
    json cfg;
    try {
        std::ifstream cfg_f("../config/config.json");
        cfg = json::parse(cfg_f);
    }
    catch (std::ifstream::failure &e) {
        std::cout << "failed to open config file" << std::endl;
        return 1;
    }
    catch (json::parse_error &e) {
        std::cout << "failed to parse config file" << std::endl;
        return 1;
    }
    
    // read config
    int sw, sh, fps;
    try {
        sw = cfg["window"]["width"];
        sh = cfg["window"]["height"];
        fps = cfg["window"]["fps"];
    }
    catch (json::type_error) {
        std::cout << "failed to read config file: type error" << std::endl;
        return 1;
    }
    catch (json::other_error) {
        std::cout << "failed to read config file: unknown error" << std::endl;
        return 1;
    }
    
    // run app
    App app("yumenet", sw, sh, fps);
    app.run(cfg);

    return 0;
}
