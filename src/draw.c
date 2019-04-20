#include <SFML/Graphics.hpp>
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

