#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// ================ Props ================

GLFWwindow* window;
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// ================ Functions ================
// window
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
void ProcessInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
GLFWwindow* CreateWindow(const char* title, int width, int height)
{
    // window Init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
}
// app
void Start()
{
    window = CreateWindow("OpenGL CLion", SCR_WIDTH, SCR_HEIGHT);
    // glad Init
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
}
void End()
{
    glfwTerminate();
}
// render
void RenderStart()
{
    ProcessInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
void RenderTick()
{

}
void RenderEnd()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}
bool IsRendering()
{
    return !glfwWindowShouldClose(window);
}
// ================ Main ================
int main()
{
    Start();

    while (IsRendering())
    {
        RenderStart();
        RenderTick();
        RenderEnd();
    }

    End();
    return 0;
}
