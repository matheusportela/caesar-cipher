CC = gcc
CFLAGS = -ansi -Wall -g

INC = -I.

.PHONY: all
all: caesar_cipher test_caesar

# Create executable files
caesar_cipher: caesar_cipher.o caesar.o
	$(CC) -o $@ $^

test_caesar: test_caesar.o caesar.o
	$(CC) -o $@ $^

# Create object files
.c.o:
	$(CC) $(CFLAGS) $(INC) -c $<

# Clean object files
.PHONY: clean
clean:
	-rm -f *.o
	-rm -f caesar_cipher
	-rm -f test_caesar
