#include "Engine.h"


int main()
{
    Engine::init();

    while (Engine::running())
    {
        Engine::handle_events();
        Engine::render();
    }

    //system("pause");
    return 0;
}
// 2869 11/06/2020
// 4321 01/07/2020