package(default_visibility = ["//visibility:public"])

cc_library(
    name = "spdlog",
    hdrs = glob([
        "include/**/*.h",
    ]),
    includes = ["include"],
    defines = ["SPDLOG_COMPILED_LIB"],
    srcs = glob([
        "src/**/*.cpp",
    ]),
)
