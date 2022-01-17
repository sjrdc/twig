run: twig
	bazel run :twig --cxxopt="-std=c++17"

.PHONY: all test clean twig

twig: test
	bazel build :twig --cxxopt="-std=c++17"

test:
	bazel test //... --test_env QT_QPA_PLATFORM=offscreen --cxxopt="-std=c++17"

all: test twig
	@echo "Success, all tests passed."
