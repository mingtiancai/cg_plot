#include <GLFW/glfw3.h>
#include <iostream>
#include <GL/gl.h>
#include "Vector3d.h"

int main()
{
    Vector3d v1(1.0, 2.0, 3.0);
    std::cout << v1 << std::endl;

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(640, 480, "GLFW Window", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        // 设置背景色为深蓝色
        glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 画几条线
        glColor3f(1.0f, 1.0f, 0.0f); // 黄色
        glBegin(GL_LINES);
        glVertex2f(-0.8f, -0.8f);
        glVertex2f(0.8f, 0.8f);
        glVertex2f(-0.8f, 0.8f);
        glVertex2f(0.8f, -0.8f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.0f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}