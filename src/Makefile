CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17
EXE_SRCS = *.cpp
LIB_SRCS = lib/*.cpp
EXE = main_exe

.PHONY: all run clean format check valgrind leaks sanitize debug

all: run

run: $(EXE)
	./$(EXE)

$(EXE): libcurves.so
	$(CC) -L./ -Wl,-rpath=./ $(CFLAGS) -o $(EXE) $(EXE_SRCS) -lcurves
	rm -f *.o

libcurves.so: curves.o
	$(CC) -shared -o $@ $?

curves.o: $(LIB_SRCS)
	$(CC) $(CFLAGS) -fPIC -c -o $@ $?

clean:
	rm -f *.o *.so $(EXE)
	cd lib && make clean

format:
	clang-format -style=google -i *.h *.cpp **/*.cpp **/*.h

check:
	clang-format -style=google -n *.h *.cpp **/*.cpp **/*.h
	cppcheck --enable=all --suppress=missingIncludeSystem --inline-suppr \
	--language=c++ --std=c++17 *.h *.cpp **/*.cpp **/*.h

valgrind: clean $(EXE)
	CK_FORK=no valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose ./$(EXE)

leaks: clean $(EXE)
	leaks -atExit -- ./$(EXE)

sanitize: CFLAGS += -g -fsanitize=address
sanitize: clean run

debug: CFLAGS += -g
debug: clean run



