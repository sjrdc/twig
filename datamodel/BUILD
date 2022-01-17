load("@com_justbuchanan_rules_qt//:qt.bzl", "qt_cc_library")

qt_cc_library(
    name = "twigdatamodel",
    srcs = [
        "gitgraph.cpp",
    ],
    hdrs = [
        "gitgraph.h",
    ],
    visibility = ["//ui:__pkg__"],
    deps = ["@qt//:qt_core",
            ]
)

cc_test(
    name = "testdatamodel",
    srcs = ["testdatamodel.cpp"],
    timeout = "short",
    deps = ["@qt//:qt_core", "@gtest//:gtest", "@gtest//:gtest_main", "twigdatamodel"],
)
