set_project("libRbxUserInfo")
set_version("1.0.0")

add_requires("cpr", "nlohmann_json")

target("RbxUserInfo")
    set_kind("$(kind)")
    add_files("src/libRbxUserInfo.cpp")
    add_packages("cpr", "nlohmann_json")