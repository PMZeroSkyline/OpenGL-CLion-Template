#include <iostream>
#include "window.h"
GLFWwindow* window;
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void EventStart()
{
}
void EventTick()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    EventTickWindow(window);
}
void EventStop()
{
    EventCloseWindow();
}
// ================ Main ================
int main()
{
    window = CreateWindow("OpenGL_CLion_Template", SCR_WIDTH, SCR_HEIGHT);
    EventStart();
    while (IsRunning(window))
    {
        EventTick();
    }
    EventStop();
    return 0;
}
