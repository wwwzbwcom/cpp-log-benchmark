package(default_visibility = ["//visibility:public"])

cc_library(
    name = "easyloggingpp",
    hdrs = glob([
        "src/**/*.h",
    ]),
    includes = ["src"],
    defines = ["ELPP_THREAD_SAFE"],
    srcs = glob([
        "src/**/*.cc",
        "src/**/*.h"
    ]),
)
