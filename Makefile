.PHONY:all clean
CC = g++
CFLAGS = -Wall -Werror
SD = src/
OD = build/
SFMLFIX = -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE = bin/hangman.exe
all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OD)hangman.o $(OD)draw.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OD)hangman.o $(OD)draw.o $(SFMLFIX)
$(OD)hangman.o: $(SD)hangman.c
	$(CC) $(CFLAGS) -c -o $(OD)hangman.o $(SD)hangman.c $(SFMLFIX)
$(OD)draw.o: $(SD)draw.c
	$(CC) $(CFLAGS) -c -o $(OD)draw.o $(SD)draw.c $(SFMLFIX)
clean:
	rm -rf $(EXECUTABLE) $(OD)*.o
