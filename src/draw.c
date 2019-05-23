#include "draw.h"
#include "logick.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct scores {
    unsigned short all;
    unsigned char geo;
    unsigned char phys;
    unsigned char math;
    unsigned char bio;
    unsigned char stuff;
    unsigned char food;
    unsigned char sport;
} s;
sf::RenderWindow window(sf::VideoMode(1280, 720), "Hangman", sf::Style::Close);
sf::SoundBuffer buffer_button, buffer_cor, buffer_incor, buffer_win, buffer_lose, buffer_win2;
bool Flag_sound = 1;

void MainMenu()
{
    window.setTitle("Hangman");
    sf::Sprite sprite1, buttonstart, buttonexit, buttondevelopers, buttonsettings;
    sf::Texture texture1, tex_but_start, tex_but_exit, tex_but_developers, tex_but_settings;
    unsigned int x, y;
    buffer_button.loadFromFile("src/sound/button.ogg");
    buffer_cor.loadFromFile("src/sound/correct.ogg");
    buffer_incor.loadFromFile("src/sound/wrong.ogg");
    buffer_win.loadFromFile("src/sound/win_reserve.ogg");
    buffer_win2.loadFromFile("src/sound/win.ogg");
    buffer_lose.loadFromFile("src/sound/lose.ogg");
    sf::Sound sound;
    sound.setBuffer(buffer_button);
    sf::Vector2i mousexy;
    texture1.loadFromFile("src/img/mainmenu.png");
    tex_but_start.loadFromFile("src/img/buttonstart.png");
    tex_but_settings.loadFromFile("src/img/buttonsettings.png");
    tex_but_developers.loadFromFile("src/img/buttondevelopers.png");
    tex_but_exit.loadFromFile("src/img/buttonexit.png");

    sprite1.setTexture(texture1);
    buttonstart.setTexture(tex_but_start);
    buttondevelopers.setTexture(tex_but_developers);
    buttonsettings.setTexture(tex_but_settings);
    buttonexit.setTexture(tex_but_exit);
    buttonstart.setPosition(640, 20);
    buttonsettings.setPosition(640, 190);
    buttondevelopers.setPosition(640, 360);
    buttonexit.setPosition(640, 530);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 640 && x < 1240 && y > 20 && y < 160) {
                    if (Flag_sound)
                        sound.play();
                    StartGameMenu();
                    if (Flag_sound)
                        sound.play();
                    break;
                }
                if (x > 640 && x < 1240 && y > 190 && y < 330) {
                    if (Flag_sound)
                        sound.play();
                    SettingsMenu();
                    if (Flag_sound)
                        sound.play();
                    break;
                }
                if (x > 640 && x < 1240 && y > 360 && y < 500) {
                    if (Flag_sound)
                        sound.play();
                    DevelopersMenu();
                    if (Flag_sound)
                        sound.play();
                    break;
                }
                if (x > 640 && x < 1240 && y > 530 && y < 640) {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(sprite1);
        window.draw(buttonstart);
        window.draw(buttonsettings);
        window.draw(buttondevelopers);
        window.draw(buttonexit);
        window.display();
    }
}

void StartGameMenu()
{
    sf::Sound sound_button;
    sound_button.setBuffer(buffer_button);
    window.setTitle("Choose a gamemode");
    unsigned x, y;
    sf::Sprite spriteback, buttonfriend, buttonmainmenu, buttoncomp;
    sf::Texture textureback, tex_but_friend, tex_but_mainmenu, tex_but_comp;
    sf::Vector2i mousexy;
    textureback.loadFromFile("src/img/mainmenu.png");
    tex_but_comp.loadFromFile("src/img/buttoncomp.png");
    tex_but_friend.loadFromFile("src/img/buttonfriend.png");
    tex_but_mainmenu.loadFromFile("src/img/buttonmainmenu.png");

    spriteback.setTexture(textureback);
    buttoncomp.setTexture(tex_but_comp);
    buttonfriend.setTexture(tex_but_friend);
    buttonmainmenu.setTexture(tex_but_mainmenu);
    buttoncomp.setPosition(340, 30);
    buttonfriend.setPosition(340, 250);
    buttonmainmenu.setPosition(340, 470);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 340 && x < 940 && y > 30 && y < 230) {
                    if (Flag_sound)
                        sound_button.play();
                    CategoryMenu();
                    sound_button.play();

                    return;
                }
                if (x > 340 && x < 940 && y > 250 && y < 450) {
                    if (Flag_sound)
                        sound_button.play();
                    FriendNameMenu();
                    sound_button.play();
                    return;
                }
                if (x > 340 && x < 940 && y > 470 && y < 670) {
                    return;
                }
            }
        }

        window.clear();
        window.draw(spriteback);
        window.draw(buttoncomp);
        window.draw(buttonfriend);
        window.draw(buttonmainmenu);
        window.display();
    }
}

void SettingsMenu()
{
    sf::Sound sound_button;
    sound_button.setBuffer(buffer_button);
    window.setTitle("Settings");
    unsigned int x, y;
    sf::Sprite spriteback, buttonsound, buttonsound2, buttonprogress, buttonmainmenu;
    sf::Texture textureback, tex_but_sound, tex_but_sound2, tex_but_progress, tex_but_mainmenu;
    sf::Vector2i mousexy;
    textureback.loadFromFile("src/img/settings.png");
    tex_but_sound.loadFromFile("src/img/buttonsoundON.png");
    tex_but_progress.loadFromFile("src/img/buttonprogress.png");
    tex_but_mainmenu.loadFromFile("src/img/buttonmainmenu.png");
    tex_but_sound2.loadFromFile("src/img/buttonsoundOFF.png");
    spriteback.setTexture(textureback);
    buttonsound.setTexture(tex_but_sound);
    buttonsound2.setTexture(tex_but_sound2);
    buttonprogress.setTexture(tex_but_progress);
    buttonmainmenu.setTexture(tex_but_mainmenu);
    buttonsound.setPosition(340, 30);
    buttonsound2.setPosition(340, 30);
    buttonprogress.setPosition(340, 250);
    buttonmainmenu.setPosition(340, 470);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 340 && x < 940 && y > 30 && y < 230) {
                    sound_button.play();
                    if (Flag_sound)
                        Flag_sound = 0;
                    else
                        Flag_sound = 1;
                }
                if (x > 340 && x < 940 && y > 250 && y < 450) {
                    if (Flag_sound)
                        sound_button.play();
                    ResetProgress();
                }
                if (x > 340 && x < 940 && y > 470 && y < 670) {
                    return;
                }
            }
        }

        window.clear();
        window.draw(spriteback);
        if (Flag_sound)
            window.draw(buttonsound);
        else
            window.draw(buttonsound2);
        window.draw(buttonprogress);
        window.draw(buttonmainmenu);
        window.display();
    }
}

void DevelopersMenu()
{
    sf::Sound sound_button;
    sound_button.setBuffer(buffer_button);
    window.setTitle("Developers");
    unsigned int x, y;
    sf::Sprite spriteback, buttonmainmenu;
    sf::Texture textureback, tex_but_mainmenu;
    sf::Vector2i mousexy;
    textureback.loadFromFile("src/img/gameback.png");
    tex_but_mainmenu.loadFromFile("src/img/buttonmainmenu.png");
    spriteback.setTexture(textureback);
    buttonmainmenu.setTexture(tex_but_mainmenu);
    buttonmainmenu.setPosition(679, 579);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 679 && x < 1279 && y > 579 && y < 719) {
                    return;
                }
            }
        }

        window.clear();
        window.draw(spriteback);
        window.draw(buttonmainmenu);
        window.display();
    }
}

void CategoryMenu()
{
    sf::Sound sound_button;
    sound_button.setBuffer(buffer_button);
    window.setTitle("Choose a category");
    unsigned int x, y, p;
    int t = 0;
    char buf[20], wordnum;
    int rand_print = 0;
    wchar_t word[100], format_word[100];
    FILE* f;
    sf::Sprite spriteback, buttonmainmenu, buttonphys, buttonmath, buttonfood, buttonbio, buttonsport, buttonstuff,
            buttongeo, buttonallthemes;
    sf::Texture textureback, tex_but_allthemes, tex_but_geo, tex_but_phys, tex_but_math, tex_but_bio, tex_but_stuff,
            tex_but_sport, tex_but_food, tex_but_mainmenu;
    sf::Text tall, tbio, tgeo, tmath, tphys, tstuff, tsport, tfood;
    sf::Font font;
    sf::Vector2i mousexy;
    font.loadFromFile("src/pricedown.ttf");
    textureback.loadFromFile("src/img/gameback.png");
    tex_but_allthemes.loadFromFile("src/img/allthemes.png");
    tex_but_food.loadFromFile("src/img/food.png");
    tex_but_geo.loadFromFile("src/img/geo.png");
    tex_but_phys.loadFromFile("src/img/phys.png");
    tex_but_math.loadFromFile("src/img/math.png");
    tex_but_bio.loadFromFile("src/img/bio.png");
    tex_but_stuff.loadFromFile("src/img/stuff.png");
    tex_but_sport.loadFromFile("src/img/sport.png");
    tex_but_mainmenu.loadFromFile("src/img/buttonmainmenu.png");

    spriteback.setTexture(textureback);
    buttonallthemes.setTexture(tex_but_allthemes);
    buttonfood.setTexture(tex_but_food);
    buttongeo.setTexture(tex_but_geo);
    buttonphys.setTexture(tex_but_phys);
    buttonmath.setTexture(tex_but_math);
    buttonbio.setTexture(tex_but_bio);
    buttonstuff.setTexture(tex_but_stuff);
    buttonsport.setTexture(tex_but_sport);
    buttonmainmenu.setTexture(tex_but_mainmenu);
    buttonallthemes.setPosition(10, 10);
    buttongeo.setPosition(10, 140);
    buttonphys.setPosition(10, 270);
    buttonmath.setPosition(10, 400);
    buttonbio.setPosition(690, 10);
    buttonstuff.setPosition(690, 140);
    buttonfood.setPosition(690, 270);
    buttonsport.setPosition(690, 400);
    buttonmainmenu.setPosition(340, 530);
    tall.setPosition(470, 34);
    tgeo.setPosition(500, 164);
    tmath.setPosition(500, 418);
    tphys.setPosition(500, 292);
    tbio.setPosition(1180, 34);
    tstuff.setPosition(1224, 164);
    tfood.setPosition(1180, 292);
    tsport.setPosition(1180, 418);
    tall.setCharacterSize(45);
    tbio.setCharacterSize(45);
    tgeo.setCharacterSize(45);
    tfood.setCharacterSize(45);
    tphys.setCharacterSize(45);
    tmath.setCharacterSize(45);
    tstuff.setCharacterSize(45);
    tsport.setCharacterSize(45);
    tall.setFont(font);
    tbio.setFont(font);
    tgeo.setFont(font);
    tmath.setFont(font);
    tphys.setFont(font);
    tfood.setFont(font);
    tstuff.setFont(font);
    tsport.setFont(font);
    f = fopen("scores.dat", "rb");
    fread(&s, sizeof(scores), 1, f);
    inttostr(s.all, buf);
    strcat(buf, "/420");
    tall.setString(buf);
    inttostr(s.geo, buf);
    strcat(buf, "/60");
    tgeo.setString(buf);
    inttostr(s.math, buf);
    strcat(buf, "/60");
    tmath.setString(buf);
    inttostr(s.phys, buf);
    strcat(buf, "/60");
    tphys.setString(buf);
    inttostr(s.bio, buf);
    strcat(buf, "/60");
    tbio.setString(buf);
    inttostr(s.stuff, buf);
    strcat(buf, "\n");
    strcat(buf, "/60");
    tstuff.setString(buf);
    inttostr(s.food, buf);
    strcat(buf, "/60");
    tfood.setString(buf);
    inttostr(s.sport, buf);
    strcat(buf, "/60");
    tsport.setString(buf);
    fclose(f);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 340 && x < 940 && y > 530 && y < 719) {
                    return;
                }
                if (x > 10 && x < 590 && y > 10 && y < 130 && s.all < 420) {
                    if (Flag_sound)
                        sound_button.play();
                    while (1) {
                        t = logickGameComputer(8, word, &rand_print, &wordnum);
                        FreeW(format_word);
                        FormatWord(t, word, format_word);
                        p = ComputerGame(word, format_word, &rand_print, t, &wordnum);

                        if (p == 0)
                            return;
                        else if (p == 1)
                            continue;
                        else if (p == 2) {
                            f = fopen("scores.dat", "rb");
                            fread(&s, sizeof(scores), 1, f);
                            fclose(f);
                            inttostr(s.all, buf);
                            strcat(buf, "/420");
                            tall.setString(buf);
                            inttostr(s.geo, buf);
                            strcat(buf, "/60");
                            tgeo.setString(buf);
                            inttostr(s.math, buf);
                            strcat(buf, "/60");
                            tmath.setString(buf);
                            inttostr(s.phys, buf);
                            strcat(buf, "/60");
                            tphys.setString(buf);
                            inttostr(s.bio, buf);
                            strcat(buf, "/60");
                            tbio.setString(buf);
                            inttostr(s.stuff, buf);
                            strcat(buf, "\n/60");
                            tstuff.setString(buf);
                            inttostr(s.food, buf);
                            strcat(buf, "/60");
                            tfood.setString(buf);
                            inttostr(s.sport, buf);
                            strcat(buf, "/60");
                            tsport.setString(buf);
                            break;
                        }
                    }
                    if (Flag_sound)
                        sound_button.play();
                }
                if (x > 10 && x < 590 && y > 140 && y < 260 && s.geo < 60) {
                    if (Flag_sound)
                        sound_button.play();
                    while (1) {
                        t = logickGameComputer(1, word, &rand_print, &wordnum);
                        FreeW(format_word);
                        FormatWord(t, word, format_word);
                        p = ComputerGame(word, format_word, &rand_print, t, &wordnum);
                        if (p == 0)
                            return;
                        else if (p == 1)
                            continue;
                        else if (p == 2) {
                            f = fopen("scores.dat", "rb");
                            fread(&s, sizeof(scores), 1, f);
                            inttostr(s.all, buf);
                            strcat(buf, "/420");
                            tall.setString(buf);
                            inttostr(s.geo, buf);
                            strcat(buf, "/60");
                            tgeo.setString(buf);
                            fclose(f);
                            break;
                        }
                    }
                    if (Flag_sound)
                        sound_button.play();
                }
                if (x > 10 && x < 590 && y > 270 && y < 390 && s.phys < 60) {
                    if (Flag_sound)
                        sound_button.play();
                    while (1) {
                        t = logickGameComputer(2, word, &rand_print, &wordnum);
                        FreeW(format_word);
                        FormatWord(t, word, format_word);
                        p = ComputerGame(word, format_word, &rand_print, t, &wordnum);

                        if (p == 0)
                            return;
                        else if (p == 1)
                            continue;
                        else if (p == 2) {
                            f = fopen("scores.dat", "rb");
                            fread(&s, sizeof(scores), 1, f);
                            inttostr(s.all, buf);
                            strcat(buf, "/420");
                            tall.setString(buf);
                            inttostr(s.phys, buf);
                            strcat(buf, "/60");
                            tphys.setString(buf);
                            fclose(f);
                            break;
                        }
                    }
                    if (Flag_sound)
                        sound_button.play();
                }
                if (x > 10 && x < 590 && y > 400 && y < 520 && s.math < 60) {
                    if (Flag_sound)
                        sound_button.play();
                    while (1) {
                        t = logickGameComputer(3, word, &rand_print, &wordnum);
                        FreeW(format_word);
                        FormatWord(t, word, format_word);
                        p = ComputerGame(word, format_word, &rand_print, t, &wordnum);
                        if (p == 0)
                            return;
                        else if (p == 1)
                            continue;
                        else if (p == 2) {
                            f = fopen("scores.dat", "rb");
                            fread(&s, sizeof(scores), 1, f);
                            inttostr(s.all, buf);
                            strcat(buf, "/420");
                            tall.setString(buf);
                            inttostr(s.math, buf);
                            strcat(buf, "/60");
                            tmath.setString(buf);
                            fclose(f);
                            break;
                        }
                    }
                    if (Flag_sound)
                        sound_button.play();
                }
                if (x > 690 && x < 1270 && y > 10 && y < 130 && s.bio < 60) {
                    if (Flag_sound)
                        sound_button.play();
                    while (1) {
                        t = logickGameComputer(4, word, &rand_print, &wordnum);
                        FreeW(format_word);
                        FormatWord(t, word, format_word);
                        p = ComputerGame(word, format_word, &rand_print, t, &wordnum);

                        if (p == 0)
                            return;
                        else if (p == 1)
                            continue;
                        else if (p == 2) {
                            f = fopen("scores.dat", "rb");
                            fread(&s, sizeof(scores), 1, f);
                            inttostr(s.all, buf);
                            strcat(buf, "/420");
                            tall.setString(buf);
                            inttostr(s.bio, buf);
                            strcat(buf, "/60");
                            tbio.setString(buf);
                            fclose(f);
                            break;
                        }
                    }
                    if (Flag_sound)
                        sound_button.play();
                }
                if (x > 690 && x < 1270 && y > 140 && y < 260 && s.stuff < 60) {
                    if (Flag_sound)
                        sound_button.play();
                    while (1) {
                        t = logickGameComputer(5, word, &rand_print, &wordnum);
                        FreeW(format_word);
                        FormatWord(t, word, format_word);
                        p = ComputerGame(word, format_word, &rand_print, t, &wordnum);

                        if (p == 0)
                            return;
                        else if (p == 1)
                            continue;
                        else if (p == 2) {
                            f = fopen("scores.dat", "rb");
                            fread(&s, sizeof(scores), 1, f);
                            inttostr(s.all, buf);
                            strcat(buf, "/420");
                            tall.setString(buf);
                            inttostr(s.stuff, buf);
                            strcat(buf, "/60");
                            tstuff.setString(buf);
                            fclose(f);
                            break;
                        }
                    }
                    if (Flag_sound)
                        sound_button.play();
                }
                if (x > 690 && x < 1270 && y > 270 && y < 390 && s.food < 60) {
                    if (Flag_sound)
                        sound_button.play();
                    while (1) {
                        t = logickGameComputer(6, word, &rand_print, &wordnum);
                        FreeW(format_word);
                        FormatWord(t, word, format_word);
                        p = ComputerGame(word, format_word, &rand_print, t, &wordnum);

                        if (p == 0)
                            return;
                        else if (p == 1)
                            continue;
                        else if (p == 2) {
                            f = fopen("scores.dat", "rb");
                            fread(&s, sizeof(scores), 1, f);
                            inttostr(s.all, buf);
                            strcat(buf, "/420");
                            tall.setString(buf);
                            inttostr(s.food, buf);
                            strcat(buf, "/60");
                            tfood.setString(buf);
                            fclose(f);
                            break;
                        }
                    }
                    if (Flag_sound)
                        sound_button.play();
                }
                if (x > 690 && x < 1270 && y > 400 && y < 520 && s.sport < 60) {
                    if (Flag_sound)
                        sound_button.play();
                    while (1) {
                        t = logickGameComputer(7, word, &rand_print, &wordnum);
                        FreeW(format_word);
                        FormatWord(t, word, format_word);
                        p = ComputerGame(word, format_word, &rand_print, t, &wordnum);

                        if (p == 0)
                            return;
                        else if (p == 1) {
                            if (Flag_sound)
                                sound_button.play();
                            continue;
                        } else if (p == 2) {
                            f = fopen("scores.dat", "rb");
                            fread(&s, sizeof(scores), 1, f);
                            inttostr(s.all, buf);
                            strcat(buf, "/420");
                            tall.setString(buf);
                            inttostr(s.sport, buf);
                            strcat(buf, "/60");
                            tsport.setString(buf);
                            fclose(f);
                            break;
                        }
                    }
                    if (Flag_sound)
                        sound_button.play();
                }
            }
        }

        window.clear();
        window.draw(spriteback);
        window.draw(buttonallthemes);
        window.draw(buttongeo);
        window.draw(buttonphys);
        window.draw(buttonmath);
        window.draw(buttonbio);
        window.draw(buttonstuff);
        window.draw(buttonsport);
        window.draw(buttonfood);
        window.draw(buttonmainmenu);
        window.draw(tall);
        window.draw(tbio);
        window.draw(tgeo);
        window.draw(tphys);
        window.draw(tmath);
        window.draw(tfood);
        window.draw(tstuff);
        window.draw(tsport);
        window.display();
    }
}

void FriendNameMenu()
{
    sf::Sound sound_button;
    sound_button.setBuffer(buffer_button);
    window.setTitle("Input your names");
    sf::Sprite spriteback, buttoncontinue, buttonmainmenu, friendback;
    sf::Texture textureback, tex_but_mainmenu, tex_but_cont, tex_friendback;
    unsigned char i1 = 0, i2 = 0, flag = 1, textfield1_pressed = 0, textfield2_pressed = 0;
    wchar_t st = L'0', st1[100], st2[100];
    unsigned int x, y;
    textureback.loadFromFile("src/img/gameback.png");
    tex_but_mainmenu.loadFromFile("src/img/buttonmainmenu.png");
    tex_but_cont.loadFromFile("src/img/buttoncont.png");
    tex_friendback.loadFromFile("src/img/friendback.png");
    sf::Font font;
    sf::Text name1, name2;
    sf::Vector2i mousexy;
    font.loadFromFile("src/pricedown.ttf");
    sf::RectangleShape textfield1(sf::Vector2f(800, 80));
    sf::RectangleShape textfield2(sf::Vector2f(800, 80));
    name1.setFont(font);
    name2.setFont(font);
    name1.setString(L"ИГРОК1");
    name2.setString(L"ИГРОК2");
    name1.setCharacterSize(100);
    name2.setCharacterSize(100);
    textfield1.setFillColor(sf::Color::Black);
    textfield2.setFillColor(sf::Color::Black);
    spriteback.setTexture(textureback);
    buttonmainmenu.setTexture(tex_but_mainmenu);
    buttoncontinue.setTexture(tex_but_cont);
    friendback.setTexture(tex_friendback);
    name1.setPosition(340, 25);
    name2.setPosition(340, 245);
    buttonmainmenu.setPosition(1, 559);
    buttoncontinue.setPosition(679, 559);
    textfield1.setPosition(340, 60);
    textfield2.setPosition(340, 280);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 340 && x < 1040 && y > 20 && y < 220) {
                    textfield1_pressed = 1;
                } else {
                    textfield1_pressed = 0;
                }
                if (x > 340 && x < 1040 && y > 240 && y < 440) {
                    textfield2_pressed = 1;
                } else {
                    ;
                    textfield2_pressed = 0;
                }
                if (x > 1 && x < 601 && y > 559 && y < 719)
                    return;
                if (x > 679 && x < 1279 && y > 559 && y < 719) {
                    if (i1 == 0) {
                        for (i1 = 0; i1 < 7; i1++) {
                            switch (i1) {
                            case 0: {
                                st1[i1] = L'И';
                                break;
                            }
                            case 1: {
                                st1[i1] = L'Г';
                                break;
                            }
                            case 2: {
                                st1[i1] = L'Р';
                                break;
                            }
                            case 3: {
                                st1[i1] = L'О';
                                break;
                            }
                            case 4: {
                                st1[i1] = L'К';
                                break;
                            }
                            case 5: {
                                st1[i1] = L'1';
                                break;
                            }
                            case 6: {
                                st1[i1] = L'\0';
                                break;
                            }
                            }
                        }
                    }
                    if (i2 == 0) {
                        for (i2 = 0; i2 < 7; i2++) {
                            switch (i2) {
                            case 0: {
                                st2[i2] = L'И';
                                break;
                            }
                            case 1: {
                                st2[i2] = L'Г';
                                break;
                            }
                            case 2: {
                                st2[i2] = L'Р';
                                break;
                            }
                            case 3: {
                                st2[i2] = L'О';
                                break;
                            }
                            case 4: {
                                st2[i2] = L'К';
                                break;
                            }
                            case 5: {
                                st2[i2] = L'2';
                                break;
                            }
                            case 6: {
                                st2[i2] = L'\0';
                                break;
                            }
                            }
                        }
                    }
                    if (Flag_sound)
                        sound_button.play();
                    FriendWordMenu(st1, st2);
                    return;
                }
            }
            if (textfield1_pressed || textfield2_pressed) {
                if (event.type == sf::Event::TextEntered) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                        st = L'Й';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                        st = L'Ц';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                        st = L'У';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                        st = L'К';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
                        st = L'Е';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                        st = L'Н';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
                        st = L'Г';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
                        st = L'Ш';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                        st = L'Щ';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                        st = L'З';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {
                        st = L'Х';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {
                        st = L'Ъ';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        st = L'Ф';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        st = L'Ы';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        st = L'В';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                        st = L'А';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                        st = L'П';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                        st = L'Р';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
                        st = L'О';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                        st = L'Л';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
                        st = L'Д';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon)) {
                        st = L'Ж';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) {
                        st = L'Э';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                        st = L'Я';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                        st = L'Ч';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                        st = L'С';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
                        st = L'М';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                        st = L'И';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                        st = L'Т';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                        st = L'Ь';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma)) {
                        st = L'Б';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {
                        st = L'Ю';
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                        st = L'\0';
                        flag = 2;
                    } else
                        flag = 0;
                    if (textfield1_pressed && flag) {
                        if (flag == 2 && i1) {
                            st1[i1 - 1] = L'\0';
                            i1--;
                        }
                        if (flag == 1 && i1 < 12) {
                            st1[i1] = st;
                            i1++;
                        }
                        name1.setString(st1);
                    }
                    if (textfield2_pressed && flag) {
                        if (flag == 2 && i2) {
                            st2[i2 - 1] = L'\0';
                            i2--;
                        }
                        if (flag == 1 && i2 < 12) {
                            st2[i2] = st;
                            i2++;
                        }
                        name2.setString(st2);
                    }
                    flag = 1;
                }
            }
        }

        window.clear();
        window.draw(spriteback);
        window.draw(friendback);
        window.draw(textfield1);
        window.draw(textfield2);
        window.draw(name1);
        window.draw(name2);
        window.draw(buttonmainmenu);
        window.draw(buttoncontinue);
        window.display();
    }
}
void FriendWordMenu(wchar_t name1[], wchar_t name2[])
{
    sf::Sound sound_button;
    sound_button.setBuffer(buffer_button);
    window.setTitle("Input a word");
    sf::Sprite spriteback, buttoncontinue, wordback;
    sf::Texture textureback, tex_but_cont, tex_wordback;
    sf::RectangleShape textfield(sf::Vector2f(1050, 80)), errorfield(sf::Vector2f(1050, 80)),
            greetingfield(sf::Vector2f(1220, 80));
    sf::Text word, word_error, text_greeting, gamer;
    sf::Font font;
    unsigned char flag = 1;
    unsigned int x, y, i = 0, c;
    bool flag_error = 0;
    wchar_t st = L'\0', wrd[100], screenwrd[100];
    unsigned short number_points1 = 0, number_points2 = 0;
    int flag_name = 1, result = 4;
    char points1[3] = {0, 0, 0}, points2[3] = {0, 0, 0};
    wrd[0] = L'\0';
    screenwrd[0] = L'\0';
    sf::Vector2i mousexy;
    textureback.loadFromFile("src/img/gameback.png");
    tex_but_cont.loadFromFile("src/img/buttoncont.png");
    tex_wordback.loadFromFile("src/img/wordback.png");
    font.loadFromFile("src/pricedown.ttf");
    word.setFont(font);
    gamer.setFont(font);
    text_greeting.setFont(font);
    word_error.setFont(font);
    word.setString(L'\0');
    word_error.setString(L"ВВЕДИ СЛОВО МИНИМУМ ИЗ ТРЕХ БУКВ!");
    text_greeting.setString(L"ВВОДИТ СЛОВО");
    gamer.setString(name1);
    word.setCharacterSize(100);
    text_greeting.setCharacterSize(80);
    gamer.setCharacterSize(80);
    textfield.setFillColor(sf::Color::Black);
    greetingfield.setFillColor(sf::Color::Red);
    errorfield.setFillColor(sf::Color::Black);
    wordback.setTexture(tex_wordback);
    spriteback.setTexture(textureback);
    buttoncontinue.setTexture(tex_but_cont);
    word.setPosition(100, 120);
    text_greeting.setPosition(150, 7);
    gamer.setPosition(580, 7);
    buttoncontinue.setPosition(340, 559);
    textfield.setPosition(80, 155);
    greetingfield.setPosition(30, 20);
    errorfield.setPosition(80, 245);
    word_error.setPosition(80, 235);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 340 && x < 940 && y > 559 && y < 759) {
                    if (i <= 2) {
                        word_error.setCharacterSize(80);
                        flag_error = 1;
                        break;
                    } else if (i > 2)
                        flag_error = 0;
                    wrd[i] = L'\0';
                    screenwrd[i] = L'\0';
                    screenwrd[0] = wrd[0];
                    screenwrd[i - 1] = wrd[i - 1];

                    for (c = 0; c < i; c++)
                        printf("%d,", wrd[c]);
                    printf("\n");
                    for (c = 0; c < i; c++)
                        printf("%d,", screenwrd[c]);
                    printf("\n");
                    printf("%d,", i);
                    for (c = 1; c < i - 1; c++) {
                        if (wrd[c] == wrd[0])
                            screenwrd[c] = wrd[0];
                        else if (wrd[c] == wrd[i - 1])
                            screenwrd[c] = wrd[i - 1];
                    }
                    if (Flag_sound)
                        sound_button.play();
                    result = FriendGame(
                            wrd,
                            screenwrd,
                            i,
                            name1,
                            name2,
                            &flag_name,
                            points1,
                            points2,
                            &number_points1,
                            &number_points2);
                    if (Flag_sound)
                        sound_button.play();
                    for (c = 0; c < i; c++) {
                        wrd[c] = L'\0';
                        screenwrd[c] = L'\0';
                    }
                    if (flag_name == 1) {
                        gamer.setString(name1);
                    } else if (flag_name == 2) {
                        gamer.setString(name2);
                    }
                    word.setString(screenwrd);
                    i = 0;
                    if (result == 0)
                        return;
                }
            }
            if (event.type == sf::Event::TextEntered) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    st = L'Й';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    st = L'Ц';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                    st = L'У';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    st = L'К';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
                    st = L'Е';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    st = L'Н';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
                    st = L'Г';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
                    st = L'Ш';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                    st = L'Щ';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    st = L'З';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {
                    st = L'Х';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {
                    st = L'Ъ';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    st = L'Ф';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    st = L'Ы';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    st = L'В';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                    st = L'А';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                    st = L'П';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                    st = L'Р';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
                    st = L'О';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                    st = L'Л';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
                    st = L'Д';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon)) {
                    st = L'Ж';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) {
                    st = L'Э';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                    st = L'Я';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                    st = L'Ч';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                    st = L'С';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
                    st = L'М';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                    st = L'И';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                    st = L'Т';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                    st = L'Ь';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma)) {
                    st = L'Б';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {
                    st = L'Ю';
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                    st = L'\0';
                    flag = 2;
                } else
                    flag = 0;
                if (flag) {
                    if (flag == 2 && i) {
                        wrd[i - 1] = L'\0';
                        screenwrd[i - 1] = L'\0';
                        i--;
                    }
                    if (flag == 1 && i < 20) {
                        wrd[i] = st;
                        screenwrd[i] = '*';
                        i++;
                    }
                    word.setString(screenwrd);
                }
                flag = 1;
            }
        }

        window.clear();
        window.draw(spriteback);
        window.draw(wordback);
        window.draw(buttoncontinue);
        window.draw(greetingfield);
        window.draw(text_greeting);
        window.draw(textfield);
        window.draw(word);
        window.draw(gamer);
        if (flag_error) {
            window.draw(errorfield);
            window.draw(word_error);
        }
        window.display();
    }
    // printf("kek=%d",i);

    std::wcout << wrd << std::endl;
}
int ComputerGame(wchar_t word[], wchar_t format_word[], int* rand_print, int t, char* wordnum)
{
    sf::Sound sound_button, sound_cor, sound_incor, sound_win, sound_lose;
    sound_button.setBuffer(buffer_button);
    sound_cor.setBuffer(buffer_cor);
    sound_incor.setBuffer(buffer_incor);
    sound_win.setBuffer(buffer_win);
    sound_lose.setBuffer(buffer_lose);
    window.setTitle("Game with computer");
    unsigned int x, y, flag = 0, mistake = 0;
    int i, ans[32], win = 0;
    sf::Sprite spriteback, interface, hangman, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16,
            l17, l18, l19, l20, l21, l22, l23, l24, l25, l26, l27, l28, l29, l30, l31, l32, endgame;
    sf::Texture textureback, tex_interface, tex_0mistake, tex_1mistake, tex_2mistake, tex_3mistake, tex_4mistake,
            tex_5mistake, tex_6mistake, tex_incorrect, tex_correct, tex_win, tex_lose;
    sf::Vector2i mousexy;
    sf::Font font;
    sf::Text slovo, tema;
    sf::RectangleShape rectangle(sf::Vector2f(908, 231));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(372, 1);
    font.loadFromFile("src/pricedown.ttf");
    textureback.loadFromFile("src/img/gameback.png");
    tex_interface.loadFromFile("src/img/gamescreen.png");
    tex_correct.loadFromFile("src/img/correct.png");
    tex_incorrect.loadFromFile("src/img/incorrect.png");
    tex_0mistake.loadFromFile("src/img/0mistake.png");
    tex_1mistake.loadFromFile("src/img/1mistake.png");
    tex_2mistake.loadFromFile("src/img/2mistake.png");
    tex_3mistake.loadFromFile("src/img/3mistake.png");
    tex_4mistake.loadFromFile("src/img/4mistake.png");
    tex_5mistake.loadFromFile("src/img/5mistake.png");
    tex_6mistake.loadFromFile("src/img/6mistake.png");
    tex_win.loadFromFile("src/img/win.png");
    tex_lose.loadFromFile("src/img/lose.png");
    spriteback.setTexture(textureback);
    interface.setTexture(tex_interface);
    hangman.setTexture(tex_0mistake);
    hangman.setPosition(0, 237);
    l1.setPosition(410, 297);
    l2.setPosition(488, 297);
    l3.setPosition(566, 297);
    l4.setPosition(644, 297);
    l5.setPosition(722, 297);
    l6.setPosition(800, 297);
    l7.setPosition(878, 297);
    l8.setPosition(956, 297);
    l9.setPosition(1034, 297);
    l10.setPosition(1112, 297);
    l11.setPosition(1190, 297);
    l12.setPosition(410, 439);
    l13.setPosition(488, 439);
    l14.setPosition(566, 439);
    l15.setPosition(644, 439);
    l16.setPosition(722, 439);
    l17.setPosition(800, 439);
    l18.setPosition(878, 439);
    l19.setPosition(956, 439);
    l20.setPosition(1034, 439);
    l21.setPosition(1112, 439);
    l22.setPosition(1190, 439);
    l23.setPosition(410, 580);
    l24.setPosition(488, 580);
    l25.setPosition(566, 580);
    l26.setPosition(644, 580);
    l27.setPosition(722, 580);
    l28.setPosition(800, 580);
    l29.setPosition(878, 580);
    l30.setPosition(956, 580);
    l31.setPosition(1034, 580);
    l32.setPosition(1112, 580);
    endgame.setPosition(300, 200);
    slovo.setFont(font);
    tema.setFont(font);
    if (*rand_print == 1) {
        tema.setString(L"География");
        tema.setPosition(98, 150);
    }
    if (*rand_print == 2) {
        tema.setString(L"Физика");
        tema.setPosition(120, 150);
    }
    if (*rand_print == 3) {
        tema.setString(L"Математика");
        tema.setPosition(75, 150);
    }
    if (*rand_print == 4) {
        tema.setString(L"Биология");
        tema.setPosition(100, 150);
    }
    if (*rand_print == 5) {
        tema.setString(L"Предметы быта");
        tema.setPosition(49, 150);
    }
    if (*rand_print == 6) {
        tema.setString(L"Еда");
        tema.setPosition(150, 150);
    }
    if (*rand_print == 7) {
        tema.setString(L"Спорт");
        tema.setPosition(130, 150);
    }
    format_word[t] = '\0';
    slovo.setString(format_word);
    slovo.setCharacterSize(60);
    tema.setCharacterSize(45);
    slovo.setPosition(550, 100);
    for (i = 0; i < 32; i++)
        ans[i] = 0;
    ans[word[0] - 1072] = 1;
    ans[word[t - 1] - 1072] = 1;
    if (ans[0] > 0)
        l1.setTexture(tex_correct);
    else if (ans[0] < 0)
        l1.setTexture(tex_incorrect);
    if (ans[1] > 0)
        l2.setTexture(tex_correct);
    else if (ans[1] < 0)
        l2.setTexture(tex_incorrect);
    if (ans[2] > 0)
        l3.setTexture(tex_correct);
    else if (ans[2] < 0)
        l3.setTexture(tex_incorrect);
    if (ans[3] > 0)
        l4.setTexture(tex_correct);
    else if (ans[3] < 0)
        l4.setTexture(tex_incorrect);
    if (ans[4] > 0)
        l5.setTexture(tex_correct);
    else if (ans[4] < 0)
        l5.setTexture(tex_incorrect);
    if (ans[5] > 0)
        l6.setTexture(tex_correct);
    else if (ans[5] < 0)
        l6.setTexture(tex_incorrect);
    if (ans[6] > 0)
        l7.setTexture(tex_correct);
    else if (ans[6] < 0)
        l7.setTexture(tex_incorrect);
    if (ans[7] > 0)
        l8.setTexture(tex_correct);
    else if (ans[7] < 0)
        l8.setTexture(tex_incorrect);
    if (ans[8] > 0)
        l9.setTexture(tex_correct);
    else if (ans[8] < 0)
        l9.setTexture(tex_incorrect);
    if (ans[9] > 0)
        l10.setTexture(tex_correct);
    else if (ans[9] < 0)
        l10.setTexture(tex_incorrect);
    if (ans[10] > 0)
        l11.setTexture(tex_correct);
    else if (ans[10] < 0)
        l11.setTexture(tex_incorrect);
    if (ans[11] > 0)
        l12.setTexture(tex_correct);
    else if (ans[11] < 0)
        l12.setTexture(tex_incorrect);
    if (ans[12] > 0)
        l13.setTexture(tex_correct);
    else if (ans[12] < 0)
        l13.setTexture(tex_incorrect);
    if (ans[13] > 0)
        l14.setTexture(tex_correct);
    else if (ans[13] < 0)
        l14.setTexture(tex_incorrect);
    if (ans[14] > 0)
        l15.setTexture(tex_correct);
    else if (ans[14] < 0)
        l15.setTexture(tex_incorrect);
    if (ans[15] > 0)
        l16.setTexture(tex_correct);
    else if (ans[15] < 0)
        l16.setTexture(tex_incorrect);
    if (ans[16] > 0)
        l17.setTexture(tex_correct);
    else if (ans[16] < 0)
        l17.setTexture(tex_incorrect);
    if (ans[17] > 0)
        l18.setTexture(tex_correct);
    else if (ans[17] < 0)
        l18.setTexture(tex_incorrect);
    if (ans[18] > 0)
        l19.setTexture(tex_correct);
    else if (ans[18] < 0)
        l19.setTexture(tex_incorrect);
    if (ans[19] > 0)
        l20.setTexture(tex_correct);
    else if (ans[19] < 0)
        l20.setTexture(tex_incorrect);
    if (ans[20] > 0)
        l21.setTexture(tex_correct);
    else if (ans[20] < 0)
        l21.setTexture(tex_incorrect);
    if (ans[21] > 0)
        l22.setTexture(tex_correct);
    else if (ans[21] < 0)
        l22.setTexture(tex_incorrect);
    if (ans[22] > 0)
        l23.setTexture(tex_correct);
    else if (ans[22] < 0)
        l23.setTexture(tex_incorrect);
    if (ans[23] > 0)
        l24.setTexture(tex_correct);
    else if (ans[23] < 0)
        l24.setTexture(tex_incorrect);
    if (ans[24] > 0)
        l25.setTexture(tex_correct);
    else if (ans[24] < 0)
        l25.setTexture(tex_incorrect);
    if (ans[25] > 0)
        l26.setTexture(tex_correct);
    else if (ans[25] < 0)
        l26.setTexture(tex_incorrect);
    if (ans[26] > 0)
        l27.setTexture(tex_correct);
    else if (ans[26] < 0)
        l27.setTexture(tex_incorrect);
    if (ans[27] > 0)
        l28.setTexture(tex_correct);
    else if (ans[27] < 0)
        l28.setTexture(tex_incorrect);
    if (ans[28] > 0)
        l29.setTexture(tex_correct);
    else if (ans[28] < 0)
        l29.setTexture(tex_incorrect);
    if (ans[29] > 0)
        l30.setTexture(tex_correct);
    else if (ans[29] < 0)
        l30.setTexture(tex_incorrect);
    if (ans[30] > 0)
        l31.setTexture(tex_correct);
    else if (ans[30] < 0)
        l31.setTexture(tex_incorrect);
    if (ans[31] > 0)
        l32.setTexture(tex_correct);
    else if (ans[31] < 0)
        l32.setTexture(tex_incorrect);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 1 && x < 375 && y > 1 && y < 94) {
                    return 0;
                } else if (mistake < 6 && win == 0) {
                    if (x > 410 && x < 488 && y > 297 && y < 435 && !ans[0]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1072) {
                                format_word[i] = L'А';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[0] = 1;
                        else
                            ans[0] = -1;
                    } else if (x > 488 && x < 566 && y > 297 && y < 435 && !ans[1]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1073) {
                                format_word[i] = L'Б';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[1] = 1;
                        else
                            ans[1] = -1;
                    } else if (x > 566 && x < 644 && y > 297 && y < 435 && !ans[2]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1074) {
                                format_word[i] = L'В';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[2] = 1;
                        else
                            ans[2] = -1;
                    } else if (x > 644 && x < 722 && y > 297 && y < 435 && !ans[3]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1075) {
                                format_word[i] = L'Г';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[3] = 1;
                        else
                            ans[3] = -1;
                    } else if (x > 722 && x < 800 && y > 297 && y < 435 && !ans[4]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1076) {
                                format_word[i] = L'Д';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[4] = 1;
                        else
                            ans[4] = -1;
                    } else if (x > 800 && x < 878 && y > 297 && y < 435 && !ans[5]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1077) {
                                format_word[i] = L'Е';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[5] = 1;
                        else
                            ans[5] = -1;
                    } else if (x > 878 && x < 956 && y > 297 && y < 435 && !ans[6]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1078) {
                                format_word[i] = L'Ж';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[6] = 1;
                        else
                            ans[6] = -1;
                    } else if (x > 956 && x < 1034 && y > 297 && y < 435 && !ans[7]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1079) {
                                format_word[i] = L'З';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[7] = 1;
                        else
                            ans[7] = -1;
                    } else if (x > 1034 && x < 1112 && y > 297 && y < 435 && !ans[8]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1080) {
                                format_word[i] = L'И';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[8] = 1;
                        else
                            ans[8] = -1;
                    } else if (x > 1112 && x < 1190 && y > 297 && y < 435 && !ans[9]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1081) {
                                format_word[i] = L'Й';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[9] = 1;
                        else
                            ans[9] = -1;
                    } else if (x > 1190 && x < 1268 && y > 297 && y < 435 && !ans[10]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1082) {
                                format_word[i] = L'К';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[10] = 1;
                        else
                            ans[10] = -1;
                    } else if (x > 410 && x < 488 && y > 439 && y < 576 && !ans[11]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1083) {
                                format_word[i] = L'Л';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[11] = 1;
                        else
                            ans[11] = -1;
                    } else if (x > 488 && x < 566 && y > 439 && y < 576 && !ans[12]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1084) {
                                format_word[i] = L'М';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[12] = 1;
                        else
                            ans[12] = -1;
                    } else if (x > 566 && x < 644 && y > 439 && y < 576 && !ans[13]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1085) {
                                format_word[i] = L'Н';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[13] = 1;
                        else
                            ans[13] = -1;
                    } else if (x > 644 && x < 722 && y > 439 && y < 576 && !ans[14]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1086) {
                                format_word[i] = L'О';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[14] = 1;
                        else
                            ans[14] = -1;
                    } else if (x > 722 && x < 800 && y > 439 && y < 576 && !ans[15]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1087) {
                                format_word[i] = L'П';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[15] = 1;
                        else
                            ans[15] = -1;
                    } else if (x > 800 && x < 878 && y > 439 && y < 576 && !ans[16]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1088) {
                                format_word[i] = L'Р';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[16] = 1;
                        else
                            ans[16] = -1;
                    } else if (x > 878 && x < 956 && y > 439 && y < 576 && !ans[17]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1089) {
                                format_word[i] = L'С';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[17] = 1;
                        else
                            ans[17] = -1;
                    } else if (x > 956 && x < 1034 && y > 439 && y < 576 && !ans[18]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1090) {
                                format_word[i] = L'Т';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[18] = 1;
                        else
                            ans[18] = -1;
                    } else if (x > 1034 && x < 1112 && y > 439 && y < 576 && !ans[19]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1091) {
                                format_word[i] = L'У';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[19] = 1;
                        else
                            ans[19] = -1;
                    } else if (x > 1112 && x < 1190 && y > 439 && y < 576 && !ans[20]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1092) {
                                format_word[i] = L'Ф';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[20] = 1;
                        else
                            ans[20] = -1;
                    } else if (x > 1190 && x < 1268 && y > 439 && y < 576 && !ans[21]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1093) {
                                format_word[i] = L'Х';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[21] = 1;
                        else
                            ans[21] = -1;
                    } else if (x > 410 && x < 488 && y > 580 && y < 717 && !ans[22]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1094) {
                                format_word[i] = L'Ц';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[22] = 1;
                        else
                            ans[22] = -1;
                    } else if (x > 488 && x < 566 && y > 580 && y < 717 && !ans[23]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1095) {
                                format_word[i] = L'Ч';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[23] = 1;
                        else
                            ans[23] = -1;
                    } else if (x > 566 && x < 644 && y > 580 && y < 717 && !ans[24]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1096) {
                                format_word[i] = L'Ш';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[24] = 1;
                        else
                            ans[24] = -1;
                    } else if (x > 644 && x < 722 && y > 580 && y < 717 && !ans[25]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1097) {
                                format_word[i] = L'Щ';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[25] = 1;
                        else
                            ans[25] = -1;
                    } else if (x > 722 && x < 800 && y > 580 && y < 717 && !ans[26]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1098) {
                                format_word[i] = L'Ъ';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[26] = 1;
                        else
                            ans[26] = -1;
                    } else if (x > 800 && x < 878 && y > 580 && y < 717 && !ans[27]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1099) {
                                format_word[i] = L'Ы';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[27] = 1;
                        else
                            ans[27] = -1;
                    } else if (x > 878 && x < 956 && y > 580 && y < 717 && !ans[28]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1100) {
                                format_word[i] = L'Ь';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[28] = 1;
                        else
                            ans[28] = -1;
                    } else if (x > 956 && x < 1034 && y > 580 && y < 717 && !ans[29]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1101) {
                                format_word[i] = L'Э';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[29] = 1;
                        else
                            ans[29] = -1;

                    } else if (x > 1034 && x < 1112 && y > 580 && y < 717 && !ans[30]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1102) {
                                format_word[i] = L'Ю';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[30] = 1;
                        else
                            ans[30] = -1;

                    } else if (x > 1112 && x < 1190 && y > 580 && y < 717 && !ans[31]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1103) {
                                format_word[i] = L'Я';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[31] = 1;
                        else
                            ans[31] = -1;
                    } else
                        flag = -1;
                    slovo.setString(format_word);
                    for (i = 1; i < t - 1; i++)
                        if (format_word[i] == 42) {
                            win = 0;
                            break;
                        }
                    if (i == t - 1)
                        win = 1;
                    if (ans[0] > 0)
                        l1.setTexture(tex_correct);
                    else if (ans[0] < 0)
                        l1.setTexture(tex_incorrect);
                    if (ans[1] > 0)
                        l2.setTexture(tex_correct);
                    else if (ans[1] < 0)
                        l2.setTexture(tex_incorrect);
                    if (ans[2] > 0)
                        l3.setTexture(tex_correct);
                    else if (ans[2] < 0)
                        l3.setTexture(tex_incorrect);
                    if (ans[3] > 0)
                        l4.setTexture(tex_correct);
                    else if (ans[3] < 0)
                        l4.setTexture(tex_incorrect);
                    if (ans[4] > 0)
                        l5.setTexture(tex_correct);
                    else if (ans[4] < 0)
                        l5.setTexture(tex_incorrect);
                    if (ans[5] > 0)
                        l6.setTexture(tex_correct);
                    else if (ans[5] < 0)
                        l6.setTexture(tex_incorrect);
                    if (ans[6] > 0)
                        l7.setTexture(tex_correct);
                    else if (ans[6] < 0)
                        l7.setTexture(tex_incorrect);
                    if (ans[7] > 0)
                        l8.setTexture(tex_correct);
                    else if (ans[7] < 0)
                        l8.setTexture(tex_incorrect);
                    if (ans[8] > 0)
                        l9.setTexture(tex_correct);
                    else if (ans[8] < 0)
                        l9.setTexture(tex_incorrect);
                    if (ans[9] > 0)
                        l10.setTexture(tex_correct);
                    else if (ans[9] < 0)
                        l10.setTexture(tex_incorrect);
                    if (ans[10] > 0)
                        l11.setTexture(tex_correct);
                    else if (ans[10] < 0)
                        l11.setTexture(tex_incorrect);
                    if (ans[11] > 0)
                        l12.setTexture(tex_correct);
                    else if (ans[11] < 0)
                        l12.setTexture(tex_incorrect);
                    if (ans[12] > 0)
                        l13.setTexture(tex_correct);
                    else if (ans[12] < 0)
                        l13.setTexture(tex_incorrect);
                    if (ans[13] > 0)
                        l14.setTexture(tex_correct);
                    else if (ans[13] < 0)
                        l14.setTexture(tex_incorrect);
                    if (ans[14] > 0)
                        l15.setTexture(tex_correct);
                    else if (ans[14] < 0)
                        l15.setTexture(tex_incorrect);
                    if (ans[15] > 0)
                        l16.setTexture(tex_correct);
                    else if (ans[15] < 0)
                        l16.setTexture(tex_incorrect);
                    if (ans[16] > 0)
                        l17.setTexture(tex_correct);
                    else if (ans[16] < 0)
                        l17.setTexture(tex_incorrect);
                    if (ans[17] > 0)
                        l18.setTexture(tex_correct);
                    else if (ans[17] < 0)
                        l18.setTexture(tex_incorrect);
                    if (ans[18] > 0)
                        l19.setTexture(tex_correct);
                    else if (ans[18] < 0)
                        l19.setTexture(tex_incorrect);
                    if (ans[19] > 0)
                        l20.setTexture(tex_correct);
                    else if (ans[19] < 0)
                        l20.setTexture(tex_incorrect);
                    if (ans[20] > 0)
                        l21.setTexture(tex_correct);
                    else if (ans[20] < 0)
                        l21.setTexture(tex_incorrect);
                    if (ans[21] > 0)
                        l22.setTexture(tex_correct);
                    else if (ans[21] < 0)
                        l22.setTexture(tex_incorrect);
                    if (ans[22] > 0)
                        l23.setTexture(tex_correct);
                    else if (ans[22] < 0)
                        l23.setTexture(tex_incorrect);
                    if (ans[23] > 0)
                        l24.setTexture(tex_correct);
                    else if (ans[23] < 0)
                        l24.setTexture(tex_incorrect);
                    if (ans[24] > 0)
                        l25.setTexture(tex_correct);
                    else if (ans[24] < 0)
                        l25.setTexture(tex_incorrect);
                    if (ans[25] > 0)
                        l26.setTexture(tex_correct);
                    else if (ans[25] < 0)
                        l26.setTexture(tex_incorrect);
                    if (ans[26] > 0)
                        l27.setTexture(tex_correct);
                    else if (ans[26] < 0)
                        l27.setTexture(tex_incorrect);
                    if (ans[27] > 0)
                        l28.setTexture(tex_correct);
                    else if (ans[27] < 0)
                        l28.setTexture(tex_incorrect);
                    if (ans[28] > 0)
                        l29.setTexture(tex_correct);
                    else if (ans[28] < 0)
                        l29.setTexture(tex_incorrect);
                    if (ans[29] > 0)
                        l30.setTexture(tex_correct);
                    else if (ans[29] < 0)
                        l30.setTexture(tex_incorrect);
                    if (ans[30] > 0)
                        l31.setTexture(tex_correct);
                    else if (ans[30] < 0)
                        l31.setTexture(tex_incorrect);
                    if (ans[31] > 0)
                        l32.setTexture(tex_correct);
                    else if (ans[31] < 0)
                        l32.setTexture(tex_incorrect);
                    if (flag == 0)
                        mistake++;
                    switch (mistake) {
                    case 0: {
                        hangman.setTexture(tex_0mistake);
                        break;
                    }
                    case 1: {
                        hangman.setTexture(tex_1mistake);
                        break;
                    }
                    case 2: {
                        hangman.setTexture(tex_2mistake);
                        break;
                    }
                    case 3: {
                        hangman.setTexture(tex_3mistake);
                        break;
                    }
                    case 4: {
                        hangman.setTexture(tex_4mistake);
                        break;
                    }
                    case 5: {
                        hangman.setTexture(tex_5mistake);
                        break;
                    }
                    case 6: {
                        hangman.setTexture(tex_6mistake);
                        win = -1;
                        break;
                    }
                    }
                    if (flag == 1) {
                        if (Flag_sound)
                            sound_cor.play();
                    } else if (!flag) {
                        if (Flag_sound)
                            sound_incor.play();
                    }
                    flag = 0;
                    if (win == -1) {
                        if (Flag_sound)
                            sound_lose.play();
                        endgame.setTexture(tex_lose);
                    } else if (win == 1) {
                        if (Flag_sound)
                            sound_win.play();
                        endgame.setTexture(tex_win);
                    }
                } else if (win) {
                    if (x > 377 && x < 906 && y > 318 && y < 416) {
                        if (win == 1)
                            Winner(*rand_print, *wordnum);
                        if (CategoryCheck(*rand_print))
                            return 2;
                        return 1;
                    } // again
                    else if (x > 300 && x < 591 && y > 435 && y < 520) {
                        if (win == 1)
                            Winner(*rand_print, *wordnum);
                        return 2;

                    } // cat
                    if (x > 689 && x < 981 && y > 435 && y < 520) {
                        if (win == 1)
                            Winner(*rand_print, *wordnum);
                        return 0;
                    } // menu
                }
            }
        }
        window.clear();
        window.draw(spriteback);
        window.draw(interface);
        window.draw(hangman);
        window.draw(l1);
        window.draw(l2);
        window.draw(l3);
        window.draw(l4);
        window.draw(l5);
        window.draw(l6);
        window.draw(l7);
        window.draw(l8);
        window.draw(l9);
        window.draw(l10);
        window.draw(l11);
        window.draw(l12);
        window.draw(l13);
        window.draw(l14);
        window.draw(l15);
        window.draw(l16);
        window.draw(l17);
        window.draw(l18);
        window.draw(l19);
        window.draw(l20);
        window.draw(l21);
        window.draw(l22);
        window.draw(l23);
        window.draw(l24);
        window.draw(l25);
        window.draw(l26);
        window.draw(l27);
        window.draw(l28);
        window.draw(l29);
        window.draw(l30);
        window.draw(l31);
        window.draw(l32);
        window.draw(rectangle);
        window.draw(tema);
        window.draw(slovo);
        window.draw(endgame);
        window.display();
    }
    return 0;
}
int FriendGame(
        wchar_t word[],
        wchar_t format_word[],
        int t,
        wchar_t name1[],
        wchar_t name2[],
        int* flag_name,
        char points1[],
        char points2[],
        unsigned short* number_points1,
        unsigned short* number_points2)
{
    sf::Sound sound_button, sound_cor, sound_incor, sound_win;
    sound_win.setVolume(50);
    sound_button.setBuffer(buffer_button);
    sound_cor.setBuffer(buffer_cor);
    sound_incor.setBuffer(buffer_incor);
    sound_win.setBuffer(buffer_win2);
    window.setTitle("Game with friend");
    unsigned int x, y, flag = 0, mistake = 0;
    int i, ans[32], win = 0;
    unsigned short temp1, temp2;
    bool flag_text_win = 0;
    sf::Sprite spriteback, interface, hangman, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16,
            l17, l18, l19, l20, l21, l22, l23, l24, l25, l26, l27, l28, l29, l30, l31, l32, end;
    sf::Texture textureback, tex_interface, tex_0mistake, tex_1mistake, tex_2mistake, tex_3mistake, tex_4mistake,
            tex_5mistake, tex_6mistake, tex_incorrect, tex_correct, endgame;
    sf::Vector2i mousexy;
    sf::Font font;
    sf::Text slovo, responder, gamer_a, gamer_b, scores1_text, scores2_text, text_win, player_g, player_win,
            scores1_text_end, scores2_text_end, gamer_end1, gamer_end2;
    sf::RectangleShape rectangle(sf::Vector2f(908, 231));
    temp1 = *number_points1;
    temp2 = *number_points2;
    inttostr(temp1, points1);
    inttostr(temp2, points2);
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(372, 1);
    font.loadFromFile("src/pricedown.ttf");
    textureback.loadFromFile("src/img/gameback.png");
    tex_interface.loadFromFile("src/img/gamescreenfriend.png");
    tex_correct.loadFromFile("src/img/correct.png");
    tex_incorrect.loadFromFile("src/img/incorrect.png");
    tex_0mistake.loadFromFile("src/img/0mistake.png");
    tex_1mistake.loadFromFile("src/img/1mistake.png");
    tex_2mistake.loadFromFile("src/img/2mistake.png");
    tex_3mistake.loadFromFile("src/img/3mistake.png");
    tex_4mistake.loadFromFile("src/img/4mistake.png");
    tex_5mistake.loadFromFile("src/img/5mistake.png");
    tex_6mistake.loadFromFile("src/img/6mistake.png");
    endgame.loadFromFile("src/img/endgame.png");
    spriteback.setTexture(textureback);
    interface.setTexture(tex_interface);
    hangman.setTexture(tex_0mistake);
    hangman.setPosition(0, 237);
    l1.setPosition(410, 297);
    l2.setPosition(488, 297);
    l3.setPosition(566, 297);
    l4.setPosition(644, 297);
    l5.setPosition(722, 297);
    l6.setPosition(800, 297);
    l7.setPosition(878, 297);
    l8.setPosition(956, 297);
    l9.setPosition(1034, 297);
    l10.setPosition(1112, 297);
    l11.setPosition(1190, 297);
    l12.setPosition(410, 439);
    l13.setPosition(488, 439);
    l14.setPosition(566, 439);
    l15.setPosition(644, 439);
    l16.setPosition(722, 439);
    l17.setPosition(800, 439);
    l18.setPosition(878, 439);
    l19.setPosition(956, 439);
    l20.setPosition(1034, 439);
    l21.setPosition(1112, 439);
    l22.setPosition(1190, 439);
    l23.setPosition(410, 580);
    l24.setPosition(488, 580);
    l25.setPosition(566, 580);
    l26.setPosition(644, 580);
    l27.setPosition(722, 580);
    l28.setPosition(800, 580);
    l29.setPosition(878, 580);
    l30.setPosition(956, 580);
    l31.setPosition(1034, 580);
    l32.setPosition(1112, 580);
    end.setPosition(300, 200);
    gamer_end1.setFont(font);
    gamer_end2.setFont(font);
    scores1_text.setFont(font);
    scores2_text.setFont(font);
    slovo.setFont(font);
    player_win.setFont(font);
    player_g.setFont(font);
    gamer_a.setFont(font);
    gamer_b.setFont(font);
    text_win.setFont(font);
    responder.setFont(font);
    format_word[t] = '\0';
    slovo.setString(format_word);
    responder.setString(L"ОТВЕЧАЕТ:");
    text_win.setString(L"ВЫИГРАЛ:");
    scores1_text.setString(points1);
    scores2_text.setString(points2);
    slovo.setCharacterSize(60);
    player_g.setCharacterSize(60);
    scores1_text.setCharacterSize(35);
    scores2_text.setCharacterSize(35);
    gamer_a.setCharacterSize(35);
    gamer_b.setCharacterSize(35);
    responder.setCharacterSize(60);
    if (*flag_name == 2) {
        player_g.setString(name1);
        *flag_name = 1;
    } else if (*flag_name == 1) {
        player_g.setString(name2);
        *flag_name = 2;
    }
    gamer_a.setString(name1);
    gamer_b.setString(name2);
    gamer_end1.setString(name1);
    gamer_end2.setString(name2);
    scores1_text.setPosition(350, 100);
    scores2_text.setPosition(350, 150);
    player_g.setPosition(650, 15);
    gamer_a.setPosition(5, 100);
    gamer_b.setPosition(5, 150);
    gamer_end1.setPosition(305, 320);
    gamer_end2.setPosition(305, 370);
    slovo.setPosition(430, 100);
    responder.setPosition(400, 15);
    text_win.setPosition(310, 210);
    player_win.setPosition(490, 210);
    for (i = 0; i < 32; i++)
        ans[i] = 0;
    ans[word[0] - 1040] = 1;
    ans[word[t - 1] - 1040] = 1;
    if (ans[0] > 0)
        l1.setTexture(tex_correct);
    else if (ans[0] < 0)
        l1.setTexture(tex_incorrect);
    if (ans[1] > 0)
        l2.setTexture(tex_correct);
    else if (ans[1] < 0)
        l2.setTexture(tex_incorrect);
    if (ans[2] > 0)
        l3.setTexture(tex_correct);
    else if (ans[2] < 0)
        l3.setTexture(tex_incorrect);
    if (ans[3] > 0)
        l4.setTexture(tex_correct);
    else if (ans[3] < 0)
        l4.setTexture(tex_incorrect);
    if (ans[4] > 0)
        l5.setTexture(tex_correct);
    else if (ans[4] < 0)
        l5.setTexture(tex_incorrect);
    if (ans[5] > 0)
        l6.setTexture(tex_correct);
    else if (ans[5] < 0)
        l6.setTexture(tex_incorrect);
    if (ans[6] > 0)
        l7.setTexture(tex_correct);
    else if (ans[6] < 0)
        l7.setTexture(tex_incorrect);
    if (ans[7] > 0)
        l8.setTexture(tex_correct);
    else if (ans[7] < 0)
        l8.setTexture(tex_incorrect);
    if (ans[8] > 0)
        l9.setTexture(tex_correct);
    else if (ans[8] < 0)
        l9.setTexture(tex_incorrect);
    if (ans[9] > 0)
        l10.setTexture(tex_correct);
    else if (ans[9] < 0)
        l10.setTexture(tex_incorrect);
    if (ans[10] > 0)
        l11.setTexture(tex_correct);
    else if (ans[10] < 0)
        l11.setTexture(tex_incorrect);
    if (ans[11] > 0)
        l12.setTexture(tex_correct);
    else if (ans[11] < 0)
        l12.setTexture(tex_incorrect);
    if (ans[12] > 0)
        l13.setTexture(tex_correct);
    else if (ans[12] < 0)
        l13.setTexture(tex_incorrect);
    if (ans[13] > 0)
        l14.setTexture(tex_correct);
    else if (ans[13] < 0)
        l14.setTexture(tex_incorrect);
    if (ans[14] > 0)
        l15.setTexture(tex_correct);
    else if (ans[14] < 0)
        l15.setTexture(tex_incorrect);
    if (ans[15] > 0)
        l16.setTexture(tex_correct);
    else if (ans[15] < 0)
        l16.setTexture(tex_incorrect);
    if (ans[16] > 0)
        l17.setTexture(tex_correct);
    else if (ans[16] < 0)
        l17.setTexture(tex_incorrect);
    if (ans[17] > 0)
        l18.setTexture(tex_correct);
    else if (ans[17] < 0)
        l18.setTexture(tex_incorrect);
    if (ans[18] > 0)
        l19.setTexture(tex_correct);
    else if (ans[18] < 0)
        l19.setTexture(tex_incorrect);
    if (ans[19] > 0)
        l20.setTexture(tex_correct);
    else if (ans[19] < 0)
        l20.setTexture(tex_incorrect);
    if (ans[20] > 0)
        l21.setTexture(tex_correct);
    else if (ans[20] < 0)
        l21.setTexture(tex_incorrect);
    if (ans[21] > 0)
        l22.setTexture(tex_correct);
    else if (ans[21] < 0)
        l22.setTexture(tex_incorrect);
    if (ans[22] > 0)
        l23.setTexture(tex_correct);
    else if (ans[22] < 0)
        l23.setTexture(tex_incorrect);
    if (ans[23] > 0)
        l24.setTexture(tex_correct);
    else if (ans[23] < 0)
        l24.setTexture(tex_incorrect);
    if (ans[24] > 0)
        l25.setTexture(tex_correct);
    else if (ans[24] < 0)
        l25.setTexture(tex_incorrect);
    if (ans[25] > 0)
        l26.setTexture(tex_correct);
    else if (ans[25] < 0)
        l26.setTexture(tex_incorrect);
    if (ans[26] > 0)
        l27.setTexture(tex_correct);
    else if (ans[26] < 0)
        l27.setTexture(tex_incorrect);
    if (ans[27] > 0)
        l28.setTexture(tex_correct);
    else if (ans[27] < 0)
        l28.setTexture(tex_incorrect);
    if (ans[28] > 0)
        l29.setTexture(tex_correct);
    else if (ans[28] < 0)
        l29.setTexture(tex_incorrect);
    if (ans[29] > 0)
        l30.setTexture(tex_correct);
    else if (ans[29] < 0)
        l30.setTexture(tex_incorrect);
    if (ans[30] > 0)
        l31.setTexture(tex_correct);
    else if (ans[30] < 0)
        l31.setTexture(tex_incorrect);
    if (ans[31] > 0)
        l32.setTexture(tex_correct);
    else if (ans[31] < 0)
        l32.setTexture(tex_incorrect);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 1 && x < 375 && y > 1 && y < 94) {
                    return 0;
                } else if (mistake < 6 && win == 0) {
                    if (x > 410 && x < 488 && y > 297 && y < 435 && !ans[0]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1040) {
                                format_word[i] = L'А';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[0] = 1;
                        else
                            ans[0] = -1;
                    } else if (x > 488 && x < 566 && y > 297 && y < 435 && !ans[1]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1041) {
                                format_word[i] = L'Б';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[1] = 1;
                        else
                            ans[1] = -1;
                    } else if (x > 566 && x < 644 && y > 297 && y < 435 && !ans[2]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1042) {
                                format_word[i] = L'В';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[2] = 1;
                        else
                            ans[2] = -1;
                    } else if (x > 644 && x < 722 && y > 297 && y < 435 && !ans[3]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1043) {
                                format_word[i] = L'Г';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[3] = 1;
                        else
                            ans[3] = -1;
                    } else if (x > 722 && x < 800 && y > 297 && y < 435 && !ans[4]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1044) {
                                format_word[i] = L'Д';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[4] = 1;
                        else
                            ans[4] = -1;
                    } else if (x > 800 && x < 878 && y > 297 && y < 435 && !ans[5]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1045) {
                                format_word[i] = L'Е';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[5] = 1;
                        else
                            ans[5] = -1;
                    } else if (x > 878 && x < 956 && y > 297 && y < 435 && !ans[6]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1046) {
                                format_word[i] = L'Ж';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[6] = 1;
                        else
                            ans[6] = -1;
                    } else if (x > 956 && x < 1034 && y > 297 && y < 435 && !ans[7]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1047) {
                                format_word[i] = L'З';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[7] = 1;
                        else
                            ans[7] = -1;
                    } else if (x > 1034 && x < 1112 && y > 297 && y < 435 && !ans[8]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1048) {
                                format_word[i] = L'И';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[8] = 1;
                        else
                            ans[8] = -1;
                    } else if (x > 1112 && x < 1190 && y > 297 && y < 435 && !ans[9]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1049) {
                                format_word[i] = L'Й';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[9] = 1;
                        else
                            ans[9] = -1;
                    } else if (x > 1190 && x < 1268 && y > 297 && y < 435 && !ans[10]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1050) {
                                format_word[i] = L'К';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[10] = 1;
                        else
                            ans[10] = -1;
                    } else if (x > 410 && x < 488 && y > 439 && y < 576 && !ans[11]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1051) {
                                format_word[i] = L'Л';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[11] = 1;
                        else
                            ans[11] = -1;
                    } else if (x > 488 && x < 566 && y > 439 && y < 576 && !ans[12]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1052) {
                                format_word[i] = L'М';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[12] = 1;
                        else
                            ans[12] = -1;
                    } else if (x > 566 && x < 644 && y > 439 && y < 576 && !ans[13]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1053) {
                                format_word[i] = L'Н';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[13] = 1;
                        else
                            ans[13] = -1;
                    } else if (x > 644 && x < 722 && y > 439 && y < 576 && !ans[14]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1054) {
                                format_word[i] = L'О';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[14] = 1;
                        else
                            ans[14] = -1;
                    } else if (x > 722 && x < 800 && y > 439 && y < 576 && !ans[15]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1055) {
                                format_word[i] = L'П';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[15] = 1;
                        else
                            ans[15] = -1;
                    } else if (x > 800 && x < 878 && y > 439 && y < 576 && !ans[16]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1056) {
                                format_word[i] = L'Р';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[16] = 1;
                        else
                            ans[16] = -1;
                    } else if (x > 878 && x < 956 && y > 439 && y < 576 && !ans[17]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1057) {
                                format_word[i] = L'С';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[17] = 1;
                        else
                            ans[17] = -1;
                    } else if (x > 956 && x < 1034 && y > 439 && y < 576 && !ans[18]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1058) {
                                format_word[i] = L'Т';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[18] = 1;
                        else
                            ans[18] = -1;
                    } else if (x > 1034 && x < 1112 && y > 439 && y < 576 && !ans[19]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1059) {
                                format_word[i] = L'У';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[19] = 1;
                        else
                            ans[19] = -1;
                    } else if (x > 1112 && x < 1190 && y > 439 && y < 576 && !ans[20]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1060) {
                                format_word[i] = L'Ф';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[20] = 1;
                        else
                            ans[20] = -1;
                    } else if (x > 1190 && x < 1268 && y > 439 && y < 576 && !ans[21]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1061) {
                                format_word[i] = L'Х';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[21] = 1;
                        else
                            ans[21] = -1;
                    } else if (x > 410 && x < 488 && y > 580 && y < 717 && !ans[22]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1062) {
                                format_word[i] = L'Ц';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[22] = 1;
                        else
                            ans[22] = -1;
                    } else if (x > 488 && x < 566 && y > 580 && y < 717 && !ans[23]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1063) {
                                format_word[i] = L'Ч';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[23] = 1;
                        else
                            ans[23] = -1;
                    } else if (x > 566 && x < 644 && y > 580 && y < 717 && !ans[24]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1064) {
                                format_word[i] = L'Ш';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[24] = 1;
                        else
                            ans[24] = -1;
                    } else if (x > 644 && x < 722 && y > 580 && y < 717 && !ans[25]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1065) {
                                format_word[i] = L'Щ';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[25] = 1;
                        else
                            ans[25] = -1;
                    } else if (x > 722 && x < 800 && y > 580 && y < 717 && !ans[26]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1066) {
                                format_word[i] = L'Ъ';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[26] = 1;
                        else
                            ans[26] = -1;
                    } else if (x > 800 && x < 878 && y > 580 && y < 717 && !ans[27]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1067) {
                                format_word[i] = L'Ы';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[27] = 1;
                        else
                            ans[27] = -1;
                    } else if (x > 878 && x < 956 && y > 580 && y < 717 && !ans[28]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1068) {
                                format_word[i] = L'Ь';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[28] = 1;
                        else
                            ans[28] = -1;
                    } else if (x > 956 && x < 1034 && y > 580 && y < 717 && !ans[29]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1069) {
                                format_word[i] = L'Э';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[29] = 1;
                        else
                            ans[29] = -1;

                    } else if (x > 1034 && x < 1112 && y > 580 && y < 717 && !ans[30]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1070) {
                                format_word[i] = L'Ю';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[30] = 1;
                        else
                            ans[30] = -1;

                    } else if (x > 1112 && x < 1190 && y > 580 && y < 717 && !ans[31]) {
                        for (i = 0; i < t; i++) {
                            if (word[i] == 1071) {
                                format_word[i] = L'Я';
                                flag = 1;
                            }
                        }
                        if (flag)
                            ans[31] = 1;
                        else
                            ans[31] = -1;
                    } else
                        flag = -1;
                    slovo.setString(format_word);
                    for (i = 1; i < t - 1; i++)
                        if (format_word[i] == 42) {
                            win = 0;
                            break;
                        }
                    if (i == t - 1)
                        win = 1;
                    if (ans[0] > 0)
                        l1.setTexture(tex_correct);
                    else if (ans[0] < 0)
                        l1.setTexture(tex_incorrect);
                    if (ans[1] > 0)
                        l2.setTexture(tex_correct);
                    else if (ans[1] < 0)
                        l2.setTexture(tex_incorrect);
                    if (ans[2] > 0)
                        l3.setTexture(tex_correct);
                    else if (ans[2] < 0)
                        l3.setTexture(tex_incorrect);
                    if (ans[3] > 0)
                        l4.setTexture(tex_correct);
                    else if (ans[3] < 0)
                        l4.setTexture(tex_incorrect);
                    if (ans[4] > 0)
                        l5.setTexture(tex_correct);
                    else if (ans[4] < 0)
                        l5.setTexture(tex_incorrect);
                    if (ans[5] > 0)
                        l6.setTexture(tex_correct);
                    else if (ans[5] < 0)
                        l6.setTexture(tex_incorrect);
                    if (ans[6] > 0)
                        l7.setTexture(tex_correct);
                    else if (ans[6] < 0)
                        l7.setTexture(tex_incorrect);
                    if (ans[7] > 0)
                        l8.setTexture(tex_correct);
                    else if (ans[7] < 0)
                        l8.setTexture(tex_incorrect);
                    if (ans[8] > 0)
                        l9.setTexture(tex_correct);
                    else if (ans[8] < 0)
                        l9.setTexture(tex_incorrect);
                    if (ans[9] > 0)
                        l10.setTexture(tex_correct);
                    else if (ans[9] < 0)
                        l10.setTexture(tex_incorrect);
                    if (ans[10] > 0)
                        l11.setTexture(tex_correct);
                    else if (ans[10] < 0)
                        l11.setTexture(tex_incorrect);
                    if (ans[11] > 0)
                        l12.setTexture(tex_correct);
                    else if (ans[11] < 0)
                        l12.setTexture(tex_incorrect);
                    if (ans[12] > 0)
                        l13.setTexture(tex_correct);
                    else if (ans[12] < 0)
                        l13.setTexture(tex_incorrect);
                    if (ans[13] > 0)
                        l14.setTexture(tex_correct);
                    else if (ans[13] < 0)
                        l14.setTexture(tex_incorrect);
                    if (ans[14] > 0)
                        l15.setTexture(tex_correct);
                    else if (ans[14] < 0)
                        l15.setTexture(tex_incorrect);
                    if (ans[15] > 0)
                        l16.setTexture(tex_correct);
                    else if (ans[15] < 0)
                        l16.setTexture(tex_incorrect);
                    if (ans[16] > 0)
                        l17.setTexture(tex_correct);
                    else if (ans[16] < 0)
                        l17.setTexture(tex_incorrect);
                    if (ans[17] > 0)
                        l18.setTexture(tex_correct);
                    else if (ans[17] < 0)
                        l18.setTexture(tex_incorrect);
                    if (ans[18] > 0)
                        l19.setTexture(tex_correct);
                    else if (ans[18] < 0)
                        l19.setTexture(tex_incorrect);
                    if (ans[19] > 0)
                        l20.setTexture(tex_correct);
                    else if (ans[19] < 0)
                        l20.setTexture(tex_incorrect);
                    if (ans[20] > 0)
                        l21.setTexture(tex_correct);
                    else if (ans[20] < 0)
                        l21.setTexture(tex_incorrect);
                    if (ans[21] > 0)
                        l22.setTexture(tex_correct);
                    else if (ans[21] < 0)
                        l22.setTexture(tex_incorrect);
                    if (ans[22] > 0)
                        l23.setTexture(tex_correct);
                    else if (ans[22] < 0)
                        l23.setTexture(tex_incorrect);
                    if (ans[23] > 0)
                        l24.setTexture(tex_correct);
                    else if (ans[23] < 0)
                        l24.setTexture(tex_incorrect);
                    if (ans[24] > 0)
                        l25.setTexture(tex_correct);
                    else if (ans[24] < 0)
                        l25.setTexture(tex_incorrect);
                    if (ans[25] > 0)
                        l26.setTexture(tex_correct);
                    else if (ans[25] < 0)
                        l26.setTexture(tex_incorrect);
                    if (ans[26] > 0)
                        l27.setTexture(tex_correct);
                    else if (ans[26] < 0)
                        l27.setTexture(tex_incorrect);
                    if (ans[27] > 0)
                        l28.setTexture(tex_correct);
                    else if (ans[27] < 0)
                        l28.setTexture(tex_incorrect);
                    if (ans[28] > 0)
                        l29.setTexture(tex_correct);
                    else if (ans[28] < 0)
                        l29.setTexture(tex_incorrect);
                    if (ans[29] > 0)
                        l30.setTexture(tex_correct);
                    else if (ans[29] < 0)
                        l30.setTexture(tex_incorrect);
                    if (ans[30] > 0)
                        l31.setTexture(tex_correct);
                    else if (ans[30] < 0)
                        l31.setTexture(tex_incorrect);
                    if (ans[31] > 0)
                        l32.setTexture(tex_correct);
                    else if (ans[31] < 0)
                        l32.setTexture(tex_incorrect);
                    if (flag == 0)
                        mistake++;
                    switch (mistake) {
                    case 0: {
                        hangman.setTexture(tex_0mistake);
                        break;
                    }
                    case 1: {
                        hangman.setTexture(tex_1mistake);
                        break;
                    }
                    case 2: {
                        hangman.setTexture(tex_2mistake);
                        break;
                    }
                    case 3: {
                        hangman.setTexture(tex_3mistake);
                        break;
                    }
                    case 4: {
                        hangman.setTexture(tex_4mistake);
                        break;
                    }
                    case 5: {
                        hangman.setTexture(tex_5mistake);
                        break;
                    }
                    case 6: {
                        hangman.setTexture(tex_6mistake);
                        win = -1;
                        break;
                    }
                    }
                    if (flag == 1) {
                        if (Flag_sound)
                            sound_cor.play();
                    } else if (!flag) {
                        if (Flag_sound)
                            sound_incor.play();
                    }
                    flag = 0;
                    if (win == -1) {
                        if (Flag_sound)
                            sound_win.play();
                        end.setTexture(endgame);
                        if (*flag_name == 1) {
                            player_win.setString(name2);
                            *number_points2 += 1;
                            temp1 = *number_points1;
                            temp2 = *number_points2;
                            inttostr(temp1, points1);
                            inttostr(temp2, points2);
                            scores2_text_end.setFont(font);
                            scores1_text_end.setFont(font);
                            scores2_text_end.setString(points2);
                            scores1_text_end.setString(points1);
                            scores1_text_end.setCharacterSize(35);
                            scores2_text_end.setCharacterSize(35);
                            scores1_text_end.setPosition(560, 320);
                            scores2_text_end.setPosition(560, 370);
                        }
                        if (*flag_name == 2) {
                            player_win.setString(name1);
                            *number_points1 += 1;
                            temp1 = *number_points1;
                            temp2 = *number_points2;
                            inttostr(temp1, points1);
                            inttostr(temp2, points2);
                            scores2_text_end.setFont(font);
                            scores1_text_end.setFont(font);
                            scores2_text_end.setString(points2);
                            scores1_text_end.setString(points1);
                            scores1_text_end.setCharacterSize(35);
                            scores2_text_end.setCharacterSize(35);
                            scores1_text_end.setPosition(560, 320);
                            scores2_text_end.setPosition(560, 370);
                        }
                        text_win.setCharacterSize(50);
                        flag_text_win = 1;
                        player_win.setCharacterSize(50);
                    } else if (win == 1) {
                        if (Flag_sound)
                            sound_win.play();
                        end.setTexture(endgame);
                        if (*flag_name == 1) {
                            player_win.setString(name1);
                            *number_points1 += 1;
                            temp1 = *number_points1;
                            temp2 = *number_points2;
                            inttostr(temp1, points1);
                            inttostr(temp2, points2);
                            scores2_text_end.setFont(font);
                            scores1_text_end.setFont(font);
                            scores2_text_end.setString(points2);
                            scores1_text_end.setString(points1);
                            scores1_text_end.setCharacterSize(35);
                            scores2_text_end.setCharacterSize(35);
                            scores1_text_end.setPosition(560, 320);
                            scores2_text_end.setPosition(560, 370);
                        }
                        if (*flag_name == 2) {
                            player_win.setString(name2);
                            *number_points2 += 1;
                            temp1 = *number_points1;
                            temp2 = *number_points2;
                            inttostr(temp1, points1);
                            inttostr(temp2, points2);
                            scores2_text_end.setFont(font);
                            scores1_text_end.setFont(font);
                            scores2_text_end.setString(points2);
                            scores1_text_end.setString(points1);
                            scores1_text_end.setCharacterSize(35);
                            scores2_text_end.setCharacterSize(35);
                            scores1_text_end.setPosition(560, 320);
                            scores2_text_end.setPosition(560, 370);
                        }
                        text_win.setCharacterSize(50);
                        flag_text_win = 1;
                        player_win.setCharacterSize(50);
                    }

                } else if (win) {
                    if (x > 301 && x < 524 && y > 464 && y < 518) {
                        return 0;
                    } else if (x > 756 && x < 980 && y > 464 && y < 518) {
                        if (win == 1)
                            return 1;
                        if (win == -1)
                            return 2;
                    }
                }
            }
        }
        window.clear();
        window.draw(spriteback);
        window.draw(interface);
        window.draw(hangman);
        window.draw(l1);
        window.draw(l2);
        window.draw(l3);
        window.draw(l4);
        window.draw(l5);
        window.draw(l6);
        window.draw(l7);
        window.draw(l8);
        window.draw(l9);
        window.draw(l10);
        window.draw(l11);
        window.draw(l12);
        window.draw(l13);
        window.draw(l14);
        window.draw(l15);
        window.draw(l16);
        window.draw(l17);
        window.draw(l18);
        window.draw(l19);
        window.draw(l20);
        window.draw(l21);
        window.draw(l22);
        window.draw(l23);
        window.draw(l24);
        window.draw(l25);
        window.draw(l26);
        window.draw(l27);
        window.draw(l28);
        window.draw(l29);
        window.draw(l30);
        window.draw(l31);
        window.draw(l32);
        window.draw(scores1_text);
        window.draw(scores2_text);
        window.draw(rectangle);
        window.draw(gamer_a);
        window.draw(gamer_b);
        window.draw(player_g);
        window.draw(slovo);
        window.draw(responder);
        window.draw(end);
        if (flag_text_win) {
            window.draw(text_win);
            window.draw(gamer_end1);
            window.draw(gamer_end2);
            window.draw(scores1_text_end);
            window.draw(scores2_text_end);
        }
        window.draw(player_win);
        window.display();
    }
    return 0;
}
