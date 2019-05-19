#ifndef DRAW_GUARD
#define DRAW_GUARD
void MainMenu();
void StartGameMenu();
void SettingsMenu();
void DevelopersMenu();
void CategoryMenu();
void FriendNameMenu();
void FriendWordMenu(wchar_t name1[], wchar_t name2[]);
int ComputerGame(
        wchar_t word[],
        wchar_t format_word[],
        int* rand_print,
        int t,
        char* wordnum);
int FriendGame(
        wchar_t word[],
        wchar_t format_word[],
        int t,
        wchar_t name1[],
        wchar_t name2[],
        int* flag_name);
#endif
