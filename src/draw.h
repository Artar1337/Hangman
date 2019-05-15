#ifndef DRAW_GUARD
#define DRAW_GUARD
void MainMenu();
void StartGameMenu();
void SettingsMenu();
void DevelopersMenu();
void CategoryMenu();
void FriendNameMenu();
void FriendWordMenu();
int ComputerGame(
        wchar_t word[],
        wchar_t format_word[],
        int* rand_print,
        int t,
        char* wordnum);
#endif
