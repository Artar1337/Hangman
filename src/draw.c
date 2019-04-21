#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
sf::RenderWindow window(sf::VideoMode(1280, 720), "Hangman");
void MainMenu()
{
    sf::Sprite sprite1, buttonstart, buttonexit, buttondevelopers,
            buttonsettings;
    sf::Texture texture1, tex_but_start, tex_but_exit, tex_but_developers,
            tex_but_settings;

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
    sf::Sprite spriteback, buttonfriend, buttonmainmenu, buttoncomp;
    sf::Texture textureback, tex_but_friend, tex_but_mainmenu, tex_but_comp;

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
    sf::Sprite spriteback, buttonsound, buttonprogress, buttonmainmenu;
    sf::Texture textureback, tex_but_sound, tex_but_progress, tex_but_mainmenu;

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
    sf::Sprite spriteback, buttonmainmenu;
    sf::Texture textureback, tex_but_mainmenu;

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
        }

        window.clear();
        window.draw(spriteback);
        window.draw(buttonmainmenu);
        window.display();
    }
}

void CategoryMenu()
{
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
    sf::Sprite spriteback, buttoncontinue, buttonmainmenu;
    sf::Texture textureback, tex_but_mainmenu, tex_but_cont;

    textureback.loadFromFile("src/img/gameback.png");
    tex_but_mainmenu.loadFromFile("src/img/buttonmainmenu.png");
    tex_but_cont.loadFromFile("src/img/buttoncont.png");
    sf::Font font;
    font.loadFromFile("src/pricedown.ttf");
    sf::Text text1, text2;

    text1.setFont(font);
    text2.setFont(font);
    text1.setString(L"ИГРОК 1:");
    text2.setString(L"ИГРОК 2:");

    text2.setCharacterSize(100);
    text1.setCharacterSize(100);
    text1.setFillColor(sf::Color::Red);
    text2.setFillColor(sf::Color::Red);

    spriteback.setTexture(textureback);
    buttonmainmenu.setTexture(tex_but_mainmenu);
    buttoncontinue.setTexture(tex_but_cont);
    text1.setPosition(20, 20);
    text2.setPosition(20, 240);
    buttonmainmenu.setPosition(1, 559);
    buttoncontinue.setPosition(679, 559);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(spriteback);
        window.draw(text1);
        window.draw(text2);
        window.draw(buttonmainmenu);
        window.draw(buttoncontinue);
        window.display();
    }
}
void FriendWordMenu()
{
    sf::Sprite spriteback, buttoncontinue;
    sf::Texture textureback, tex_but_cont;

    textureback.loadFromFile("src/img/gameback.png");
    tex_but_cont.loadFromFile("src/img/buttoncont.png");
    sf::Font font;
    font.loadFromFile("src/pricedown.ttf");
    sf::Text text1;

    text1.setFont(font);
    text1.setString(L"ВВЕДИТЕ СЛОВО:");
    text1.setCharacterSize(100);
    text1.setFillColor(sf::Color::Red);
    spriteback.setTexture(textureback);
    buttoncontinue.setTexture(tex_but_cont);
    text1.setPosition(340, 20);
    buttoncontinue.setPosition(340, 559);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(spriteback);
        window.draw(buttoncontinue);
        window.draw(text1);
        window.display();
    }
}
