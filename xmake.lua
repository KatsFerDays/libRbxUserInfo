set_project("libRbxUserInfo")
set_version("1.0.0")

add_requires("cpr", "nlohmann_json")

target("libRbxUserInfo")
    set_kind("$(kind)")
    set_prefixname("")
    add_files("src/libRbxUserInfo.cpp")
    add_includedirs("include")
    add_packages("cpr", "nlohmann_json")
    add_headerfiles("include/*")