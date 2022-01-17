load("@com_justbuchanan_rules_qt//:qt.bzl", "qt_cc_library")

qt_cc_library(
    name = "twigui",
    srcs = [
        "mainwindow.cpp",
	"settings.cpp",
	"settings.h",
    ],
    hdrs = [
        "mainwindow.h",
    ],
    deps = ["@qt//:qt_widgets", "//datamodel:twigdatamodel"],
    visibility = ["//:__pkg__"]
)
