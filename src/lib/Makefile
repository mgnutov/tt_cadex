CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17
# CFLAGS += -pedantic
TFLAGS = -lgtest -pthread
TST_SRCS = tests/*.cpp
LIB_SRCS = *.cpp
EXE = test_exe

.PHONY: all clean test gcov_report format check valgrind leaks sanitize debug

all: clean test

test: $(EXE)
	./$? > $?.log

$(EXE): $(LIB_SRCS) $(TST_SRCS)
	$(CC) $(CFLAGS) -o $@ $? $(TFLAGS)

gcov_report: CFLAGS += -g --coverage
gcov_report: clean test
	lcov -t "coverage" -o coverage.info -c -d . --no-external
	lcov -r coverage.info $(shell pwd)/$(TST_SRCS) -o coverage.info
	genhtml -o report coverage.info
	rm -f *.gc* *.info
	open ./report/index.html

clean:
	rm -rf report
	rm -f *.gc* *.info $(EXE) *.log

format:
	clang-format -style=google -i *.h *.cpp **/*.cpp **/*.h

check:
	clang-format -style=google -n *.h *.cpp **/*.cpp **/*.h
	cppcheck --enable=all --suppress=missingIncludeSystem --inline-suppr \
	--language=c++ --std=c++17 *.h *.cpp **/*.cpp **/*.h

valgrind: clean $(EXE)
	CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	--verbose --log-file=$(EXE)_valgrind.log ./$(EXE) > $(EXE).log

leaks: clean $(EXE)
	leaks -atExit -- ./$(EXE) > $(EXE).log

sanitize: CFLAGS += -g -fsanitize=address
sanitize: clean test

debug: CFLAGS += -g
debug: clean test