run: twig
	bazel run :twig --cxxopt="-std=c++20"

.PHONY: all test clean twig

twig:
	bazel build :twig --cxxopt="-std=c++20"

test:
	bazel build //test:testplugin --cxxopt="-std=c++20"
	bazel test //test:testplugin --test_env QT_QPA_PLATFORM=offscreen --cxxopt="-std=c++20"

all: test twig
	@echo "Success, all tests passed."
