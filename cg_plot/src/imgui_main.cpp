#include <GL/gl.h> 
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>

int main() {
    // 初始化GLFW
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW + ImGui Demo", nullptr, nullptr);
    if (!window) { glfwTerminate(); return -1; }
    glfwMakeContextCurrent(window);

    // 初始化ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // 主循环
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("New")) {
                    // 响应“新建”菜单项
                    std::cout << "New is clicked!" << std::endl;
                }
                if (ImGui::MenuItem("Open")) {
                    // 响应“打开”菜单项
                    std::cout << "Open is clicked!" << std::endl;
                }
                if (ImGui::MenuItem("Exit")) {
                    // 响应“退出”菜单项
                    glfwSetWindowShouldClose(window, GLFW_TRUE);
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Help")) {
                if (ImGui::MenuItem("About")) {
                    // 响应“关于”菜单项
                    ImGui::OpenPopup("AboutPopup");
                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        // ImGui窗口
        ImGui::Begin("Hello, ImGui!");
        ImGui::Text("This is a demo window.");
        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.2f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 画几条线
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1, 1, -1, 1, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glColor3f(1.0f, 1.0f, 0.0f); // 黄色
        glBegin(GL_LINES);
            glVertex2f(-0.8f, -0.8f); glVertex2f(0.8f, 0.8f);
            glVertex2f(-0.8f, 0.8f);  glVertex2f(0.8f, -0.8f);
            glVertex2f(-0.5f, 0.0f);  glVertex2f(0.5f, 0.0f);
            glVertex2f(0.0f, -0.5f);  glVertex2f(0.0f, 0.5f);
        glEnd();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // 清理
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}