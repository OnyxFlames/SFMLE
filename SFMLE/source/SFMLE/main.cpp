#include <SFML/Graphics.hpp>
#include <SFMLE/Graphics/Color.hpp>
#include <SFMLE/Window/Camera.hpp>
#include <iostream>

#include <SFMLE/System/Vector2.hpp>
#include <SFMLE/System/Rect.hpp>
#include <SFMLE/System/Math.hpp>

#include <SFMLE/Graphics/RichText.hpp>

template <typename T>
void PrintRect(sf::Rect<T>& rect)
{
    printf("X: %.f Y: %.f %.fx%.f\n", rect.left, rect.top, rect.width, rect.height);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFMLE");

    sf::Font font;
    assert(font.loadFromFile("C:/Windows/Fonts/Consola.ttf"));

    sfe::RichText text(font);
    text.setString("<bold><italic><strike>Sunken</bold> </strike>Chamber");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}