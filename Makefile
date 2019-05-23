.PHONY:all clean test
CC = g++
CFLAGS = -Wall -Werror
C = gcc
SD = src/
OD = build/
SFMLFIX = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXECUTABLE = bin/hangman.exe
TEST = bin/testing

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
	rm -rf $(EXECUTABLE) $(TEST) $(OD)*.o $(OD)/test/*.o
test: $(OD)test $(TEST)
$(OD)test:
	mkdir build/test/ -p
$(TEST): $(OD)test/main.o $(OD)test/main.o
	$(C) $(CFLAGS) $(OD)/test/main.o -o $(TEST)
$(OD)test/main.o: test/main.c
	$(C) $(CFLAGS) -c -I thirdparty -I src test/main.c -o $(OD)test/main.o
