workspace(name = "x")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_justbuchanan_rules_qt",
    remote = "https://github.com/justbuchanan/bazel_rules_qt.git",
    branch = "master", )

load("@com_justbuchanan_rules_qt//:qt_configure.bzl", "qt_configure")

qt_configure()

load("@local_config_qt//:local_qt.bzl", "local_qt_path")

new_local_repository( name = "qt", build_file =
    "@com_justbuchanan_rules_qt//:qt.BUILD", path = local_qt_path(), )

load("@com_justbuchanan_rules_qt//tools:qt_toolchain.bzl", "register_qt_toolchains")

register_qt_toolchains()

git_repository(
    name = "gtest",
    remote = "https://github.com/google/googletest",
    tag = "release-1.11.0",
)
