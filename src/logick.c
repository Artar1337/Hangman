#include "logick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

struct scores {
    unsigned short all;
    unsigned char geo;
    unsigned char phys;
    unsigned char math;
    unsigned char bio;
    unsigned char stuff;
    unsigned char food;
    unsigned char sport;
} S, st;

bool CategoryCheck(int n)
{
    FILE* fb;
    bool f = false;
    fb = fopen("scores.dat", "rb");
    fread(&st, sizeof(scores), 1, fb);
    fclose(fb);
    switch (n) {
    case 1: {
        if (st.geo > 59)
            f = true;
        break;
    }
    case 2: {
        if (st.phys > 59)
            f = true;
        break;
    }
    case 3: {
        if (st.math > 59)
            f = true;
        break;
    }
    case 4: {
        if (st.bio > 59)
            f = true;
        break;
    }
    case 5: {
        if (st.stuff > 59)
            f = true;
        break;
    }
    case 6: {
        if (st.food > 59)
            f = true;
        break;
    }
    case 7: {
        if (st.sport > 59)
            f = true;
        break;
    }
    }
    return f;
}

void FreeW(wchar_t mas[])
{
    int i;
    for (i = 0; i < 100; i++)
        mas[i] = L'\0';
}

void DelWord(char cat, char num)
{
    FILE *f, *tf;
    char i = 0;
    wchar_t ch;
    switch (cat) {
    case 1: {
        f = fopen("src/TXT/geography.txt", "rt+");
        tf = fopen("src/TXT/geography.tmp", "wt+");
        break;
    }
    case 2: {
        f = fopen("src/TXT/physics.txt", "rt+");
        tf = fopen("src/TXT/physics.tmp", "wt+");
        break;
    }
    case 3: {
        f = fopen("src/TXT/maths.txt", "rt+");
        tf = fopen("src/TXT/maths.tmp", "wt+");
        break;
    }
    case 4: {
        f = fopen("src/TXT/biology.txt", "rt+");
        tf = fopen("src/TXT/biology.tmp", "wt+");
        break;
    }
    case 5: {
        f = fopen("src/TXT/houseware.txt", "rt+");
        tf = fopen("src/TXT/houseware.tmp", "wt+");
        break;
    }
    case 6: {
        f = fopen("src/TXT/food.txt", "rt+");
        tf = fopen("src/TXT/food.tmp", "wt+");
        break;
    }
    case 7: {
        f = fopen("src/TXT/sport.txt", "rt+");
        tf = fopen("src/TXT/sport.tmp", "wt+");
        break;
    }
    }
    while (1) {
        ch = getc(f);
        if (i < num) {
            putc(ch, tf);
            if (ch == '\n')
                i++;
        } else if (i == num) {
            if (ch == '\n')
                i++;
        } else {
            putc(ch, tf);
            if (ch == '\\') {
                putc('0', tf);
                break;
            }
        }
    }
    fclose(tf);
    fclose(f);
    switch (cat) {
    case 1: {
        if (remove("src/TXT/geography.txt"))
            printf("ERROR, can't remove!\n");
        rename("src/TXT/geography.tmp", "src/TXT/geography.txt");
        break;
    }
    case 2: {
        if (remove("src/TXT/physics.txt"))
            printf("ERROR, can't remove!\n");
        rename("src/TXT/physics.tmp", "src/TXT/physics.txt");
        break;
    }
    case 3: {
        if (remove("src/TXT/maths.txt"))
            printf("ERROR, can't remove!\n");
        rename("src/TXT/maths.tmp", "src/TXT/maths.txt");
        break;
    }
    case 4: {
        if (remove("src/TXT/biology.txt"))
            printf("ERROR, can't remove!\n");
        rename("src/TXT/biology.tmp", "src/TXT/biology.txt");
        break;
    }
    case 5: {
        if (remove("src/TXT/houseware.txt"))
            printf("ERROR, can't remove!\n");
        rename("src/TXT/houseware.tmp", "src/TXT/houseware.txt");
        break;
    }
    case 6: {
        if (remove("src/TXT/food.txt"))
            printf("ERROR, can't remove!\n");
        rename("src/TXT/food.tmp", "src/TXT/food.txt");
        break;
    }
    case 7: {
        if (remove("src/TXT/sport.txt"))
            printf("ERROR, can't remove!\n");
        rename("src/TXT/sport.tmp", "src/TXT/sport.txt");
        break;
    }
    }
}

void Winner(int cat, char num)
{
    FILE* f;
    f = fopen("scores.dat", "rb");
    fread(&st, sizeof(scores), 1, f);
    fclose(f);
    switch (cat) {
    case 1: {
        st.geo++;
        DelWord(1, num);
        break;
    }
    case 2: {
        st.phys++;
        DelWord(2, num);
        break;
    }
    case 3: {
        st.math++;
        DelWord(3, num);
        break;
    }
    case 4: {
        st.bio++;
        DelWord(4, num);
        break;
    }
    case 5: {
        st.stuff++;
        DelWord(5, num);
        break;
    }
    case 6: {
        st.food++;
        DelWord(6, num);
        break;
    }
    case 7: {
        st.sport++;
        DelWord(7, num);
        break;
    }
    }
    st.all = st.bio + st.stuff + st.food + st.sport + st.math + st.phys + st.geo;
    f = fopen("scores.dat", "wb+");
    fwrite(&st, sizeof(scores), 1, f);
    fclose(f);
}

void ResetProgress()
{
    FILE *f, *fr;
    wchar_t ch;
    f = fopen("scores.dat", "wb+");
    S.all = S.geo = S.phys = S.math = S.bio = S.stuff = S.food = S.sport = 0;
    fwrite(&S, sizeof(scores), 1, f);
    fclose(f);
    f = fopen("src/TXT/backup.txt", "rt");
    fr = fopen("src/TXT/biology.txt", "wt+");
    while (1) {
        ch = getc(f);
        if (ch == '*')
            break;
        putc(ch, fr);
    }
    putc('\\', fr);
    putc('0', fr);
    ch = getc(f);
    fclose(fr);
    fr = fopen("src/TXT/food.txt", "wt+");
    while (1) {
        ch = getc(f);
        if (ch == '*')
            break;
        putc(ch, fr);
    }
    putc('\\', fr);
    putc('0', fr);
    ch = getc(f);
    fclose(fr);
    fr = fopen("src/TXT/geography.txt", "wt+");
    while (1) {
        ch = getc(f);
        if (ch == '*')
            break;
        putc(ch, fr);
    }
    putc('\\', fr);
    putc('0', fr);
    ch = getc(f);
    fclose(fr);
    fr = fopen("src/TXT/houseware.txt", "wt+");
    while (1) {
        ch = getc(f);
        if (ch == '*')
            break;
        putc(ch, fr);
    }
    putc('\\', fr);
    putc('0', fr);
    ch = getc(f);
    fclose(fr);
    fr = fopen("src/TXT/maths.txt", "wt+");
    while (1) {
        ch = getc(f);
        if (ch == '*')
            break;
        putc(ch, fr);
    }
    putc('\\', fr);
    putc('0', fr);
    ch = getc(f);
    fclose(fr);
    fr = fopen("src/TXT/physics.txt", "wt+");
    while (1) {
        ch = getc(f);
        if (ch == '*')
            break;
        putc(ch, fr);
    }
    putc('\\', fr);
    putc('0', fr);
    ch = getc(f);
    fclose(fr);
    fr = fopen("src/TXT/sport.txt", "wt+");
    while (1) {
        ch = getc(f);
        if (ch == '*')
            break;
        putc(ch, fr);
    }
    putc('\\', fr);
    putc('0', fr);
    ch = getc(f);
    fclose(fr);
    fclose(f);
}
bool inttostr(unsigned short n, char buf[])
{
    unsigned short i = n % 10, temp;
    if (n > 420)
        return 1;
    if (i == 0)
        buf[1] = '0';
    else if (i == 1)
        buf[1] = '1';
    else if (i == 2)
        buf[1] = '2';
    else if (i == 3)
        buf[1] = '3';
    else if (i == 4)
        buf[1] = '4';
    else if (i == 5)
        buf[1] = '5';
    else if (i == 6)
        buf[1] = '6';
    else if (i == 7)
        buf[1] = '7';
    else if (i == 8)
        buf[1] = '8';
    else if (i == 9)
        buf[1] = '9';
    i = n / 10;
    i = i % 10;
    if (i == 0) {
        buf[0] = buf[1];
        buf[1] = '\0';
    } else if (i == 1)
        buf[0] = '1';
    else if (i == 2)
        buf[0] = '2';
    else if (i == 3)
        buf[0] = '3';
    else if (i == 4)
        buf[0] = '4';
    else if (i == 5)
        buf[0] = '5';
    else if (i == 6)
        buf[0] = '6';
    else if (i == 7)
        buf[0] = '7';
    else if (i == 8)
        buf[0] = '8';
    else if (i == 9)
        buf[0] = '9';
    if (n / 100) {
        i = n / 100;
        i = i % 10;
        if (i == 1)
            buf[2] = '1';
        else if (i == 2)
            buf[2] = '2';
        else if (i == 3)
            buf[2] = '3';
        else if (i == 4)
            buf[2] = '4';
        temp = buf[0];
        buf[0] = buf[2];
        buf[2] = temp;
        temp = buf[1];
        buf[1] = buf[2];
        buf[2] = temp;
        buf[3] = '\0';
    } else
        buf[2] = '\0';
    return 0;
}

int logickGameComputer(int flag, wchar_t word[], int* rand_print, char* wordnum)
{
    char choose;
    int i = 0, c = 0, flg = 1, k;
    wchar_t ch_1, ch_2;
    FILE* pf;
    srand(time(0));
    pf = fopen("scores.dat", "rb");
    fread(&st, sizeof(scores), 1, pf);
    fclose(pf);
    if (flag == 8) {
        while (1) {
            flag = rand() % 7 + 1;
            if (flag == 1 && 60 - st.geo > 0)
                break;
            else if (flag == 2 && 60 - st.phys > 0)
                break;
            else if (flag == 3 && 60 - st.math > 0)
                break;
            else if (flag == 4 && 60 - st.bio > 0)
                break;
            else if (flag == 5 && 60 - st.stuff > 0)
                break;
            else if (flag == 6 && 60 - st.food > 0)
                break;
            else if (flag == 7 && 60 - st.sport > 0)
                break;
        }
        *rand_print = flag;
    }
    if (flag == 1) {
        pf = fopen("src/TXT/geography.txt", "r");
        *rand_print = flag;
        k = 60 - st.geo;
    } else if (flag == 2) {
        pf = fopen("src/TXT/physics.txt", "r");
        *rand_print = flag;
        k = 60 - st.phys;
    } else if (flag == 3) {
        pf = fopen("src/TXT/maths.txt", "r");
        *rand_print = flag;
        k = 60 - st.math;
    } else if (flag == 4) {
        pf = fopen("src/TXT/biology.txt", "r");
        *rand_print = flag;
        k = 60 - st.bio;
    } else if (flag == 5) {
        pf = fopen("src/TXT/houseware.txt", "r");
        *rand_print = flag;
        k = 60 - st.stuff;
    } else if (flag == 6) {
        pf = fopen("src/TXT/food.txt", "r");
        *rand_print = flag;
        k = 60 - st.food;
    } else if (flag == 7) {
        pf = fopen("src/TXT/sport.txt", "r");
        *rand_print = flag;
        k = 60 - st.sport;
    }
    *wordnum = choose = rand() % k;
    while (1) {
        if (flg)
            ch_1 = getc(pf);
        ch_2 = getc(pf);
        flg = 1;
        if (ch_1 == L'\n') {
            c++;
            ch_1 = ch_2;
            flg = 0;
        } else if (ch_2 == L'\n') {
            c++;
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
    return i;
}

void FormatWord(int kol, wchar_t word[], wchar_t* format_word)
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
