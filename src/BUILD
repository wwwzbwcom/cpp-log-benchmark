cc_binary(
    name = "glog",
    srcs = ["glog.cc"],
    deps = ["@com_github_google_glog//:glog", "@benchmark//:benchmark"],
)

cc_binary(
    name = "easyloggingpp",
    srcs = ["easyloggingpp.cc"],
    deps = ["@benchmark//:benchmark", "//dep/easyloggingpp:easyloggingpp"],
)
cc_binary(
    name = "spdlog",
    srcs = ["spdlog.cc"],
    deps = ["@benchmark//:benchmark", "//dep/spdlog:spdlog"],
)

cc_binary(
    name = "g3log",
    srcs = ["g3log.cc"],
    deps = ["@benchmark//:benchmark", "//dep/g3log/src:g3log"],
    copts = ['-std=c++17'],
)