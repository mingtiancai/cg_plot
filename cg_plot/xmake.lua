add_rules("mode.debug", "mode.release")

add_requires("glfw")

target("cg_plot")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")
    add_packages("glfw")

target("cg_plot_test")
    set_kind("binary")
    add_files("test/*.cpp")
    add_includedirs("include")