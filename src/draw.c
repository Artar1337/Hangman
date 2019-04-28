#include "draw.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>
sf::RenderWindow window(sf::VideoMode(1280, 720), "Hangman");
void MainMenu()
{
    window.setTitle("Hangman");
    sf::Sprite sprite1, buttonstart, buttonexit, buttondevelopers,
            buttonsettings;
    sf::Texture texture1, tex_but_start, tex_but_exit, tex_but_developers,
            tex_but_settings;
    unsigned int x, y;
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

            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 640 && x < 1240 && y > 20 && y < 160) {
                    StartGameMenu();
                    break;
                }
                if (x > 640 && x < 1240 && y > 190 && y < 330) {
                    SettingsMenu();
                    break;
                }
                if (x > 640 && x < 1240 && y > 360 && y < 500) {
                    DevelopersMenu();
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
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 340 && x < 940 && y > 30 && y < 230) {
                    CategoryMenu();
                    break;
                }
                if (x > 340 && x < 940 && y > 250 && y < 450) {
                    FriendNameMenu();
                    break;
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
    window.setTitle("Settings");
    unsigned int x, y;
    sf::Sprite spriteback, buttonsound, buttonprogress, buttonmainmenu;
    sf::Texture textureback, tex_but_sound, tex_but_progress, tex_but_mainmenu;
    sf::Vector2i mousexy;
    textureback.loadFromFile("src/img/settings.png");
    tex_but_sound.loadFromFile("src/img/buttonsoundON.png");
    tex_but_progress.loadFromFile("src/img/buttonprogress.png");
    tex_but_mainmenu.loadFromFile("src/img/buttonmainmenu.png");

    spriteback.setTexture(textureback);
    buttonsound.setTexture(tex_but_sound);
    buttonprogress.setTexture(tex_but_progress);
    buttonmainmenu.setTexture(tex_but_mainmenu);

    buttonsound.setPosition(340, 30);
    buttonprogress.setPosition(340, 250);
    buttonmainmenu.setPosition(340, 470);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 340 && x < 940 && y > 30 && y < 230)
                    ;
                if (x > 340 && x < 940 && y > 250 && y < 450)
                    ;
                if (x > 340 && x < 940 && y > 470 && y < 670) {
                    return;
                }
            }
        }

        window.clear();
        window.draw(spriteback);
        window.draw(buttonsound);
        window.draw(buttonprogress);
        window.draw(buttonmainmenu);
        window.display();
    }
}

void DevelopersMenu()
{
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
            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
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
    window.setTitle("Choose a category");
    sf::Sprite spriteback, buttonmainmenu, buttonphys, buttonmath, buttonfood,
            buttonbio, buttonsport, buttonstuff, buttongeo, buttonallthemes;
    sf::Texture textureback, tex_but_allthemes, tex_but_geo, tex_but_phys,
            tex_but_math, tex_but_bio, tex_but_stuff, tex_but_sport,
            tex_but_food, tex_but_mainmenu;

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

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
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
        window.display();
    }
}

void FriendNameMenu()
{
    window.setTitle("Input your names");
    sf::Sprite spriteback, buttoncontinue, buttonmainmenu;
    sf::Texture textureback, tex_but_mainmenu, tex_but_cont;
    unsigned char i1 = 0, i2 = 0, flag = 1, textfield1_pressed = 0,
                  textfield2_pressed = 0;
    wchar_t st = L'0', st1[100] = L"\0", st2[100] = L"\0";
    unsigned int x, y;
    textureback.loadFromFile("src/img/gameback.png");
    tex_but_mainmenu.loadFromFile("src/img/buttonmainmenu.png");
    tex_but_cont.loadFromFile("src/img/buttoncont.png");
    sf::Font font;
    sf::Text text1, text2, name1, name2;
    sf::Vector2i mousexy;
    font.loadFromFile("src/pricedown.ttf");
    text1.setFont(font);
    text2.setFont(font);
    text1.setString(L"ИГРОК 1:");
    sf::RectangleShape textfield1(sf::Vector2f(700, 200));
    sf::RectangleShape textfield2(sf::Vector2f(700, 200));
    text2.setString(L"ИГРОК 2:");

    text2.setCharacterSize(100);
    text1.setCharacterSize(100);
    name1.setFont(font);
    name2.setFont(font);
    name1.setString(L"Игрок1");
    name2.setString(L"Игрок2");

    name1.setCharacterSize(100);
    name2.setCharacterSize(100);

    /*   text1.setFillColor(sf::Color::Red);
       text2.setFillColor(sf::Color::Red);
       name2.setFillColor(sf::Color::Black);
       name1.setFillColor(sf::Color::Black);
   */
    spriteback.setTexture(textureback);
    buttonmainmenu.setTexture(tex_but_mainmenu);
    buttoncontinue.setTexture(tex_but_cont);

    text1.setPosition(20, 20);
    text2.setPosition(20, 240);
    name1.setPosition(340, 25);
    name2.setPosition(340, 245);

    buttonmainmenu.setPosition(1, 559);
    buttoncontinue.setPosition(679, 559);
    textfield1.setPosition(340, 20);
    textfield2.setPosition(340, 240);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed
                && event.mouseButton.button == sf::Mouse::Left) {
                mousexy = sf::Mouse::getPosition(window);
                x = mousexy.x;
                y = mousexy.y;
                if (x > 340 && x < 1040 && y > 20 && y < 220)
                    textfield1_pressed = 1;
                else
                    textfield1_pressed = 0;
                if (x > 340 && x < 1040 && y > 240 && y < 440)
                    textfield2_pressed = 1;
                else
                    textfield2_pressed = 0;
                if (x > 1 && x < 601 && y > 559 && y < 719)
                    return;
                if (x > 679 && x < 1279 && y > 559 && y < 719) {
                    FriendWordMenu();
                    break;
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
                    } else if (sf::Keyboard::isKeyPressed(
                                       sf::Keyboard::LBracket)) {
                        st = L'Х';
                    } else if (sf::Keyboard::isKeyPressed(
                                       sf::Keyboard::RBracket)) {
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
                    } else if (sf::Keyboard::isKeyPressed(
                                       sf::Keyboard::SemiColon)) {
                        st = L'Ж';
                    } else if (sf::Keyboard::isKeyPressed(
                                       sf::Keyboard::Quote)) {
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
                    } else if (sf::Keyboard::isKeyPressed(
                                       sf::Keyboard::Comma)) {
                        st = L'Б';
                    } else if (sf::Keyboard::isKeyPressed(
                                       sf::Keyboard::Period)) {
                        st = L'Ю';
                    } else if (sf::Keyboard::isKeyPressed(
                                       sf::Keyboard::BackSpace)) {
                        st = L'\0';
                        flag = 2;
                    } else
                        flag = 0;
                    if (textfield1_pressed && flag) {
                        if (flag == 2 && i1) {
                            st1[i1 - 1] = L'\0';
                            i1--;
                        }
                        if (flag == 1 && i1 < 11) {
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
                        if (flag == 1 && i2 < 11) {
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
        window.draw(text1);
        window.draw(text2);
        window.draw(textfield1);
        window.draw(textfield2);
        window.draw(name1);
        window.draw(name2);
        window.draw(buttonmainmenu);
        window.draw(buttoncontinue);
        window.display();
    }
}
void FriendWordMenu()
{
    window.setTitle("Input a word");
    sf::Sprite spriteback, buttoncontinue;
    sf::Texture textureback, tex_but_cont;
    unsigned char i = 0, flag = 1;
    wchar_t st = L'\0', wrd[100], screenwrd[100];

    textureback.loadFromFile("src/img/gameback.png");
    tex_but_cont.loadFromFile("src/img/buttoncont.png");
    sf::Font font;
    font.loadFromFile("src/pricedown.ttf");
    sf::Text text1, word;

    text1.setFont(font);
    text1.setString(L"ВВЕДИТЕ СЛОВО:");
    text1.setCharacterSize(100);

    /*  word.setFillColor(sf::Color::Black);
      text1.setFillColor(sf::Color::Black);
  */
    word.setFont(font);
    word.setString(L'\0');
    word.setCharacterSize(100);

    spriteback.setTexture(textureback);
    buttoncontinue.setTexture(tex_but_cont);
    text1.setPosition(340, 20);
    word.setPosition(100, 120);
    buttoncontinue.setPosition(340, 559);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

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
                } else if (sf::Keyboard::isKeyPressed(
                                   sf::Keyboard::SemiColon)) {
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
                } else if (sf::Keyboard::isKeyPressed(
                                   sf::Keyboard::BackSpace)) {
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
                    if (flag == 1 && i < 32) {
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
        window.draw(buttoncontinue);
        window.draw(text1);
        window.draw(word);
        window.display();
    }
    std::wcout << wrd << std::endl;
}
