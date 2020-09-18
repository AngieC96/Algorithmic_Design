EXE  = strassen_test.x
CC  = gcc
CFLAGS = -std=c11 -g -O4 -Wall -Wextra -I ./ $(EXTRA_CFLAGS)
SRC  = main.c test.c matrix.c strassen.c
OBJ  = $(SRC:.c=.o)
INC  = ./
DIST = README.md \
       Makefile \
	   CMakeLists.txt

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .c .o

all: $(EXE)

.PHONY: all

$(EXE): $(OBJ)
	$(CC) $^ -o $(EXE) $(EXTRA_CFLAGS)

%.o : %.c
	$(CC) -c $< -o $@ $(CFLAGS)


clean:
	rm -rf $(OBJ) $(EXE) *~ doc/

.PHONY: clean

doc: Doxyfile
	doxygen $^

.PHONY: doc

main.o: main.c

format: $(SRC) $(INC)
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this commands"

.PHONY: format
