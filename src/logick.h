#ifndef LOGICK_GUARD
#define LOGICK_GUARD
int logickGameComputer(int flag, wchar_t word[], int* rand_print, char* wordnum);
void FormatWord(int kol, wchar_t word[], wchar_t* format_word);
void ResetProgress();
bool inttostr(unsigned short n, char buf[]);
void Winner(int cat, char num);
void FreeW(wchar_t mas[]);
bool CategoryCheck(int n);
#endif
