add_rules("mode.debug", "mode.release")
add_requires("glfw")

target("cg_plot")
    set_kind("binary")
    add_files("src/main.cpp")
    add_includedirs("include")
    add_packages("glfw", "imgui")

target("cg_plot_img")
    set_kind("binary")
    add_files("src/imgui_main.cpp")
    add_includedirs("include")
    add_packages("glfw", "imgui")

    add_files("3rdparty/imgui/imgui.cpp")
    add_files("3rdparty/imgui/imgui_draw.cpp")
    add_files("3rdparty/imgui/imgui_tables.cpp")
    add_files("3rdparty/imgui/imgui_widgets.cpp")
    add_files("3rdparty/imgui/imgui_demo.cpp") -- 可选
    add_files("3rdparty/imgui/backends/imgui_impl_glfw.cpp")
    add_files("3rdparty/imgui/backends/imgui_impl_opengl3.cpp")
    add_includedirs("include", "3rdparty/imgui", "3rdparty/imgui/backends")
    add_packages("glfw")

target("cg_plot_test")
    set_kind("binary")
    add_files("test/*.cpp")
    add_includedirs("include")