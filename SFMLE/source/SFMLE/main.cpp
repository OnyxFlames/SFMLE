#include <SFML/Graphics.hpp>
#include <SFMLE/Graphics/Color.hpp>
#include <SFMLE/Window/Camera.hpp>
#include <iostream>
#include <SFMLE/System/Vector2.inl>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sfe::Color::Blend(sf::Color::Blue, sf::Color::Green));

    sfe::Camera camera(window);

    sf::Vector2i iVec{ 10, 20 };
    sf::Vector2f fVec{ 10.f, 20.f };

    std::cout << sfe::Vector2::Length(fVec);

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
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::PageUp:
                    camera.zoom(1.5f);
                    break;
                case sf::Keyboard::PageDown:
                    camera.zoom(1.f / 1.5f);
                    break;
                case sf::Keyboard::Home:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        camera.setZoom(0.5f);
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
                        camera.setZoom(1.5f);
                    else
                        camera.setZoom(1.f);
                    break;
                }
                break;
            }
        }

        window.clear();
        window.setView(camera);
        window.draw(shape);
        window.display();
    }

    return 0;
}