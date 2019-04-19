all:
	g++ -c hangman.c
	g++ hangman.o -o hangman.exe -lsfml-graphics -lsfml-window -lsfml-system

