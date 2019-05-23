.PHONY:all clean
CC = g++
CFLAGS = -Wall -Werror
SD = src/
OD = build/
SFMLFIX = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXECUTABLE = bin/hangman.exe
all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OD)hangman.o $(OD)draw.o $(OD)logick.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OD)hangman.o $(OD)draw.o $(OD)logick.o $(SFMLFIX)
$(OD)hangman.o: $(SD)hangman.c
	$(CC) $(CFLAGS) -c -o $(OD)hangman.o $(SD)hangman.c $(SFMLFIX)
$(OD)draw.o: $(SD)draw.c
	$(CC) $(CFLAGS) -c -o $(OD)draw.o $(SD)draw.c $(SFMLFIX)
$(OD)logick.o: $(SD)logick.c
	 $(CC) $(CFLAGS) -c -o $(OD)logick.o $(SD)logick.c
clean:
	rm -rf $(EXECUTABLE) $(OD)*.o
