/* Joe
 * 2022
 */

#ifndef MOTD
#define MOTD ""
#endif

#include <chrono>
#include <cmath>
#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#include <termox/termox.hpp>

using namespace ox;

class App : public Widget
{
    auto paint_event(Painter &p) -> bool override
    {
        auto text = U"╔═Hello═World═╝" | fg(Color::Green) | Trait::Bold;
        p.put(text, {10, 5});
        return Widget::paint_event(p);
    }
};

int main() { return System{}.run<App>(); }