.PHONY: all clean

# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Executable name
EXEC = StrList

# Source files and object files
SRC = StrList.c Main.c
OBJ = $(SRC:.c=.o)

# Targets
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c

main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c


clean:
	@rm -f $(EXEC) $(OBJ)
