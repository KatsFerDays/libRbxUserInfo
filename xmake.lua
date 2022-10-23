set_project("libRbxUserInfo")
set_version("1.0.0")
add_rules("mode.debug", "mode.release")
set_languages("c++20")

add_requires("cpr", "nlohmann_json")

target("libRbxUserInfo")
    set_kind("$(kind)")
    add_packages("cpr", "nlohmann_json")
    add_includedirs("include")
    add_files("src/libRbxUserInfo.cpp")
    add_headerfiles("include/*")
    set_prefixname("")