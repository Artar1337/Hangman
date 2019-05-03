#include "logick.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
void logickGameComputer(int flag, char word[])
{
    int choose;
    FILE* pf;
    Null(word);
    srand(time(0));
    choose = rand() % 60;
    if (flag == 1) {
        pf = fopen("TXT//geography.txt", "r");
    }
    while (choose >= 0) {
        choose--;
        fgets(word, 20, pf);
    }
    fclose(pf);
}
void Null(char A[])
{
    int i;
    for (i = 0; i < 20; i++)
        A[i] = 0;
}

