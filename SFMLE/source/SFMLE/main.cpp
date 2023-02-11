#include <SFML/Graphics.hpp>
#include <SFMLE/Graphics/Color.hpp>
#include <SFMLE/Window/Camera.hpp>
#include <iostream>

#include <SFMLE/System/Vector2.hpp>
#include <SFMLE/System/Rect.hpp>
#include <SFMLE/System/Math.hpp>

template <typename T>
void PrintRect(sf::Rect<T>& rect)
{
    printf("X: %.f Y: %.f %.fx%.f\n", rect.left, rect.top, rect.width, rect.height);
}

int main()
{
    srand(0);

    for (int i = 0; i < 16; ++i)
    {
        sf::Vector2f vector
        {
            (float)(rand() % (16 * 16 * (i + 1))),
            (float)(rand() % (16 * 16 * (i + 1))),
        };
        std::cout << sfe::Vector2::ToString(sfe::Vector2::SnapTo(vector, {16, 16})) << '\n';
    }


    return 0;
}