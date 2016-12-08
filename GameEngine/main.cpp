#include <iostream>
#include "core/graphics/window.h"

int main() {

    Window window(800, 600, "Game Engine");

    while (!window.isClosed())
    {
        window.update();
    }
    return 0;
}