CC = gcc
CFLAGS = -ansi -Wall -g

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
HEAD = $(SRC:.c=.h)

INC = -I.

.PHONY: all
all: test_caesar

# Create executable files
caesar-cipher: caesar-cipher.o caesar.o
	$(CC) -o $@ $^

test_caesar: test_caesar.o caesar.o
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
	-rm -f caesar-cipher
	-rm -f test_caesar
