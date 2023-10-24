#include <SFML/Graphics.hpp>
#include <SFMLE/Graphics/Color.hpp>
#include <SFMLE/Window/Camera.hpp>
#include <iostream>

#include <SFMLE/System/Vector2.hpp>
#include <SFMLE/System/Rect.hpp>
#include <SFMLE/System/Math.hpp>

#include <SFMLE/System/PolarVector2.hpp>

#include <SFMLE/Graphics/RichText.hpp>

#include <SFMLE/Graphics/Time.hpp>


int main()
{
    auto hourAnd12Minutes = sfe::hours(1.f) + sfe::minutes(12);
    
    sf::Clock clock;

    while (hourAnd12Minutes > sf::milliseconds(0))
    {
        hourAnd12Minutes -= clock.restart();
        std::cout << sfe::Time::ToString(hourAnd12Minutes, sfe::Time::Format::MinutesOnly) << "\n";
    }



    return 0;
}