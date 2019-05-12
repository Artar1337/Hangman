#include "logick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
int logickGameComputer(int flag, wchar_t word[], int* rand_print)
{
    int choose, i = 0, c = 0, flg = 1;
    wchar_t ch_1, ch_2;
    FILE* pf;
    srand(time(0));
    choose = rand() % 60;
    //    printf("SLOVO N%d\n", 1 + choose);
    if (flag == 8) {
        flag = rand() % 7 + 1;
        *rand_print = flag;
    }
    if (flag == 1) {
        pf = fopen("src/TXT/geography.txt", "r");
        *rand_print = flag;
    }
    if (flag == 2) {
        pf = fopen("src/TXT/physics.txt", "r");
        *rand_print = flag;
    }
    if (flag == 3) {
        pf = fopen("src/TXT/maths.txt", "r");
        *rand_print = flag;
    }
    if (flag == 4) {
        pf = fopen("src/TXT/biology.txt", "r");
        *rand_print = flag;
    }
    if (flag == 5) {
        pf = fopen("src/TXT/houseware.txt", "r");
        *rand_print = flag;
    }
    if (flag == 6) {
        pf = fopen("src/TXT/food.txt", "r");
        *rand_print = flag;
    }
    if (flag == 7) {
        pf = fopen("src/TXT/sport.txt", "r");
        *rand_print = flag;
    }
    while (1) {
        if (flg)
            ch_1 = getc(pf);
        ch_2 = getc(pf);
        flg = 1;
        //        printf("%d,%d|", ch_1, ch_2);
        if (ch_1 == L'\n') {
            c++;
            //  printf("kek=%d|", c);
            ch_1 = ch_2;
            flg = 0;
        } else if (ch_2 == L'\n') {
            c++;
            //    printf("kek=%d|", c);
        }
        if (c == choose) {
            if (ch_1 == 208 && ch_2 == 176) {
                word[i] = L'а';
                i++;
            } else if (ch_1 == 208 && ch_2 == 177) {
                word[i] = L'б';
                i++;
            } else if (ch_1 == 208 && ch_2 == 178) {
                word[i] = L'в';
                i++;
            } else if (ch_1 == 208 && ch_2 == 179) {
                word[i] = L'г';
                i++;
            } else if (ch_1 == 208 && ch_2 == 180) {
                word[i] = L'д';
                i++;
            } else if (ch_1 == 208 && ch_2 == 181) {
                word[i] = L'е';
                i++;
            } else if (ch_1 == 208 && ch_2 == 182) {
                word[i] = L'ж';
                i++;
            } else if (ch_1 == 208 && ch_2 == 183) {
                word[i] = L'з';
                i++;
            } else if (ch_1 == 208 && ch_2 == 184) {
                word[i] = L'и';
                i++;
            } else if (ch_1 == 208 && ch_2 == 185) {
                word[i] = L'й';
                i++;
            } else if (ch_1 == 208 && ch_2 == 186) {
                word[i] = L'к';
                i++;
            } else if (ch_1 == 208 && ch_2 == 187) {
                word[i] = L'л';
                i++;
            } else if (ch_1 == 208 && ch_2 == 188) {
                word[i] = L'м';
                i++;
            } else if (ch_1 == 208 && ch_2 == 189) {
                word[i] = L'н';
                i++;
            } else if (ch_1 == 208 && ch_2 == 190) {
                word[i] = L'о';
                i++;
            } else if (ch_1 == 208 && ch_2 == 191) {
                word[i] = L'п';
                i++;
            } else if (ch_1 == 209 && ch_2 == 128) {
                word[i] = L'р';
                i++;
            } else if (ch_1 == 209 && ch_2 == 129) {
                word[i] = L'с';
                i++;
            } else if (ch_1 == 209 && ch_2 == 130) {
                word[i] = L'т';
                i++;
            } else if (ch_1 == 209 && ch_2 == 131) {
                word[i] = L'у';
                i++;
            } else if (ch_1 == 209 && ch_2 == 132) {
                word[i] = L'ф';
                i++;
            } else if (ch_1 == 209 && ch_2 == 133) {
                word[i] = L'х';
                i++;
            } else if (ch_1 == 209 && ch_2 == 134) {
                word[i] = L'ц';
                i++;
            } else if (ch_1 == 209 && ch_2 == 135) {
                word[i] = L'ч';
                i++;
            } else if (ch_1 == 209 && ch_2 == 136) {
                word[i] = L'ш';
                i++;
            } else if (ch_1 == 209 && ch_2 == 137) {
                word[i] = L'щ';
                i++;
            } else if (ch_1 == 209 && ch_2 == 138) {
                word[i] = L'ъ';
                i++;
            } else if (ch_1 == 209 && ch_2 == 139) {
                word[i] = L'ы';
                i++;
            } else if (ch_1 == 209 && ch_2 == 140) {
                word[i] = L'ь';
                i++;
            } else if (ch_1 == 209 && ch_2 == 141) {
                word[i] = L'э';
                i++;
            } else if (ch_1 == 209 && ch_2 == 142) {
                word[i] = L'ю';
                i++;
            } else if (ch_1 == 209 && ch_2 == 143) {
                word[i] = L'я';
                i++;
            }
        }
        if (c > choose)
            break;
    }
    fclose(pf);
    /*    for (c = 0; c < i; c++)
            printf("%d,", word[c]);
        printf("\n");*/
    return i;
}
void FormatWord(int kol, wchar_t word[], wchar_t format_word[])
{
    int i;
    format_word[0] = word[0] - 32;
    format_word[kol - 1] = word[kol - 1] - 32;
    for (i = 1; i < kol - 1; i++) {
        format_word[i] = L'*';
        if (word[i] == word[0])
            format_word[i] = word[0] - 32;
        else if (word[i] == word[kol - 1])
            format_word[i] = word[kol - 1] - 32;
    }
}
