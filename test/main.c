#define CTEST_MAIN
#define CTEST_COLOR_OK
#include <ctest.h>
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
}st;

void FormatWord(int kol, char word[], char* format_word)
{
    int i;
    format_word[0] = word[0];
    format_word[kol - 1] = word[kol - 1];
    for (i = 1; i < kol - 1; i++) {
        format_word[i] ='*';
        if (word[i] == word[0])
            format_word[i] = word[0];
        else if (word[i] == word[kol - 1])
            format_word[i] = word[kol - 1];
    }
}

unsigned int CategoryCheck(int n)
{
    unsigned int f = 1;
    switch (n) {
    case 1: {
        if (st.geo > 59)
            f = 0;
        break;
    }
    case 2: {
        if (st.phys > 59)
            f = 0;
        break;
    }
    case 3: {
        if (st.math > 59)
            f = 0;
        break;
    }
    case 4: {
        if (st.bio > 59)
            f = 0;
        break;
    }
    case 5: {
        if (st.stuff > 59)
            f = 0;
        break;
    }
    case 6: {
        if (st.food > 59)
            f = 0;
        break;
    }
    case 7: {
        if (st.sport > 59)
            f = 0;
        break;
    }
    }
    return f;
}

unsigned int inttostr(unsigned short n, char buf[])
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

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
CTEST(inttostr_1, result_test)
{
    unsigned short n = 7;
    char buf[3]={0,0,0};
    
    unsigned int result =inttostr(n, buf);

    unsigned int expected = 0;
    ASSERT_EQUAL_U(expected, result);
    char exp[3]="7";
    inttostr(n, buf);
    ASSERT_STR(exp, buf);
}
CTEST(inttostr_2, result_test)
{
    unsigned short n = 0;
    char buf[3]={0,0,0};
    
    unsigned int result =inttostr(n, buf);

    unsigned int expected = 0;
    ASSERT_EQUAL_U(expected, result);
    char exp[3]="0";
    inttostr(n, buf);
    ASSERT_STR(exp, buf);
}
CTEST(inttostr_3, result_test)
{
    unsigned short n = 421;
    char buf[3]={0,0,0};
    
    unsigned int result =inttostr(n, buf);

    unsigned int expected = 1;
    ASSERT_EQUAL_U(expected, result);
}
CTEST(inttostr_4, result_test)
{
    unsigned short n = 420;
    char buf[4]="419\0";
    
    unsigned int result =inttostr(n, buf);
    
    unsigned int expected = 0;
    ASSERT_EQUAL_U(expected, result);
    
    char exp[4]="420\0";
    inttostr(n, buf);
    ASSERT_STR(exp, buf);
}
CTEST(inttostr_5, result_test)
{
    unsigned short n = 20;
    char buf[4]="19\0";
    
    unsigned int result =inttostr(n, buf);
    
    unsigned int expected = 0;
    ASSERT_EQUAL_U(expected, result);
    
    char exp[4]="20\0";
    inttostr(n, buf);
    ASSERT_STR(exp, buf);
}
CTEST(inttostr_6, result_test)
{
    unsigned short n = 34;
    char buf[4]="33\0";
    
    unsigned int result =inttostr(n, buf);
    
    unsigned int expected = 0;
    ASSERT_EQUAL_U(expected, result);
    
    char exp[4]="34\0";
    inttostr(n, buf);
    ASSERT_STR(exp, buf);
}
CTEST(inttostr_7, result_test)
{
    unsigned short n = 7;
    char buf[4]="6\0";
    
    unsigned int result =inttostr(n, buf);
    
    unsigned int expected = 0;
    ASSERT_EQUAL_U(expected, result);
    
    char exp[4]="7\0";
    inttostr(n, buf);
    ASSERT_STR(exp, buf);
}
CTEST(inttostr_8, result_test)
{
    unsigned short n = 376;
    char buf[4]="375\0";
    
    unsigned int result =inttostr(n, buf);
    
    unsigned int expected = 0;
    ASSERT_EQUAL_U(expected, result);
    
    char exp[4]="376\0";
    inttostr(n, buf);
    ASSERT_STR(exp, buf);
}
CTEST(CategoryCheck_1, result_test)
{
    st.geo=59;
    st.phys=23;
    st.math=59;
    st.bio=59;
    st.stuff=59;
    st.food=59;
    st.sport=59;
    int n = 1;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 1;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_2, result_test)
{
    st.geo=20;
    st.phys=59;
    st.math=59;
    st.bio=59;
    st.stuff=59;
    st.food=59;
    st.sport=59;
    int n = 2;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 1;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_3, result_test)
{
    st.geo=20;
    st.phys=59;
    st.math=59;
    st.bio=53;
    st.stuff=9;
    st.food=59;
    st.sport=59;
    int n = 3;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 1;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_4, result_test)
{
    st.geo=20;
    st.phys=59;
    st.math=59;
    st.bio=53;
    st.stuff=9;
    st.food=59;
    st.sport=59;
    int n = 4;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 1;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_5, result_test)
{
    st.geo=20;
    st.phys=59;
    st.math=59;
    st.bio=53;
    st.stuff=9;
    st.food=59;
    st.sport=59;
    int n = 5;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 1;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_6, result_test)
{
    st.geo=20;
    st.phys=59;
    st.math=59;
    st.bio=53;
    st.stuff=9;
    st.food=59;
    st.sport=59;
    int n = 6;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 1;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_7, result_test)
{
    st.geo=20;
    st.phys=59;
    st.math=59;
    st.bio=53;
    st.stuff=9;
    st.food=59;
    st.sport=59;
    int n = 7;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 1;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_8, result_test)
{
    st.geo=60;
    st.phys=23;
    st.math=59;
    st.bio=59;
    st.stuff=59;
    st.food=59;
    st.sport=59;
    int n = 1;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 0;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_9, result_test)
{
    st.geo=6;
    st.phys=60;
    st.math=59;
    st.bio=59;
    st.stuff=59;
    st.food=59;
    st.sport=59;
    int n = 2;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 0;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_10, result_test)
{
    st.geo=6;
    st.phys=60;
    st.math=60;
    st.bio=50;
    st.stuff=59;
    st.food=59;
    st.sport=59;
    int n = 3;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 0;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_11, result_test)
{
    st.geo=6;
    st.phys=60;
    st.math=59;
    st.bio=60;
    st.stuff=59;
    st.food=59;
    st.sport=59;
    int n = 4;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 0;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_12, result_test)
{
    st.geo=6;
    st.phys=60;
    st.math=2;
    st.bio=5;
    st.stuff=60;
    st.food=60;
    st.sport=59;
    int n = 5;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 0;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_13, result_test)
{
    st.geo=6;
    st.phys=60;
    st.math=0;
    st.bio=5;
    st.stuff=9;
    st.food=60;
    st.sport=60;
    int n = 6;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 0;
    ASSERT_EQUAL(expected, result); 
}
CTEST(CategoryCheck_14, result_test)
{
    st.geo=6;
    st.phys=60;
    st.math=0;
    st.bio=5;
    st.stuff=9;
    st.food=60;
    st.sport=60;
    int n = 7;
    
    int result = CategoryCheck(n);
    
    unsigned int expected = 0;
    ASSERT_EQUAL(expected, result); 
}
CTEST(FormatWord_1, result_test)
{   
    int n = 3;
    char word[4]="tor\0";
    char format_word[5]="\0";
    FormatWord(n,word,format_word);
    
    char exp[4]="t*r\0";
 
    ASSERT_STR(exp, format_word);
}
CTEST(FormatWord_2, result_test)
{
    int n = 20;
    char word[21]="torftorftorftorftorf\0";
    char format_word[21]="\0";
    FormatWord(n,word,format_word);
    
    char exp[21]="t**ft**ft**ft**ft**f\0";
 
    ASSERT_STR(exp, format_word);
}
CTEST(FormatWord_3, result_test)
{
    int n = 7;
    char word[8]="torftom\0";
    char format_word[21]="\0";
    FormatWord(n,word,format_word);
    
    char exp[8]="t***t*m\0";
 
    ASSERT_STR(exp, format_word);
}
CTEST(FormatWord_4, result_test)
{
    int n = 4;
    char word[5]="tort\0";
    char format_word[5]="\0";
    FormatWord(n,word,format_word);
    
    char exp[5]="t**t\0";
 
    ASSERT_STR(exp, format_word);
}
