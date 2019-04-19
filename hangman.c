#include <SFML/Graphics.hpp>
#include <stdio.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Hangman");
    sf::Sprite sprite1;
    sf::Texture texture1;
    if (!texture1.loadFromFile("src/img/mainmenu.png")) {
        printf("Can't open the texture!\n");
    }
    sprite1.setTexture(texture1);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite1);
        window.display();
    }

    return 0;
}
