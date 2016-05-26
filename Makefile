CC = gcc
CFLAGS = -ansi -Wall -g

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEAD = $(SRC:.c=.h)
EXEC = test_caesar

INC = -I.

.PHONY: all
all: $(SRC) $(EXEC)

# Create executable file
$(EXEC): $(OBJ)
	$(CC) -o $@ $^

# Create object files
.c.o:
	$(CC) $(CFLAGS) $(INC) -c $<

# Print Makefile's variables
.PHONY: print
print:
	@echo Sources: $(SRC)
	@echo Objects: $(OBJ)
	@echo Headers: $(HEAD)
	@echo Executable: $(EXEC)

# Clean object files
.PHONY: clean
clean:
	-rm -f $(EXEC) *.o
