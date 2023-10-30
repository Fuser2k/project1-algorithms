add_rules("mode.debug", "mode.release")
set_languages("c++20")

target("code")
    set_kind("binary")
    add_files("src/**.cpp")