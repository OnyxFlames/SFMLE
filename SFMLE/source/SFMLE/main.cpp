#include <SFML/Graphics.hpp>
#include <SFMLE/Graphics/Color.hpp>
#include <SFMLE/Window/Camera.hpp>
#include <iostream>

#include <SFMLE/System/Vector2.hpp>
#include <SFMLE/System/Rect.hpp>
#include <SFMLE/System/Math.hpp>

#include <SFMLE/System/PolarVector2.hpp>

#include <SFMLE/Graphics/RichText.hpp>

template <typename T>
void PrintRect(sf::Rect<T>& rect)
{
    printf("X: %.f Y: %.f %.fx%.f\n", rect.left, rect.top, rect.width, rect.height);
}

int main()
{
    
    sfe::PolarVector2<float> pvec(sf::Vector2f{1.f, 1.f});

    std::cout << sfe::Vector2::ToString<float>(pvec);

    return 0;
}