#include "std_lib_facilities.h"
#include "AnimationWindow.h"

int main() {

    AnimationWindow window;

    window.draw_circle({200, 100}, 500);
    window.draw_rectangle({300, 300}, 100, 50);
    window.draw_quad({100, 100}, {200, 100}, {300, 200}, {100, 300});
    window.draw_line({100, 100}, {200, 200});
    window.draw_triangle({100, 100}, {200, 100}, {150, 200});
    window.draw_text({100, 100}, "Hello, World!", Color::red, 80);

    window.wait_for_close();

    return 0;
}