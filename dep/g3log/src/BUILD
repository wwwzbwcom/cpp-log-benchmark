package(default_visibility = ["//visibility:public"])

cc_library(
    name = "g3log",
    hdrs = glob([
        "g3log/*.hpp",
    ]),
    includes = ["."],
    srcs = glob(
        [
            "**/*.cpp",
            "**/*.hpp",
            "**/*.ipp", 
        ], 
        exclude = ["crashhandler_windows.cpp", "stacktrace_windows.cpp"]
    ),
    copts = ['-std=c++17'],
)
