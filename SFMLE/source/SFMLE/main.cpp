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
#include <SFMLE/Resources/ResourceContainer.hpp>

#include <SFMLE/Window/Mouse.hpp>
#include <SFMLE/Window/Keyboard.hpp>
#include <SFMLE/System/Angle.hpp>

int main()
{
    auto rad = 3.14159f;
    auto deg = sfe::Math::RadToDeg(rad);

    sfe::FloatAngle radAngle = sfe::radians(3.14159f);
    sfe::FloatAngle degAngle = sfe::degrees(180.f);

    radAngle = degAngle;


    //assert(radAngle.asDegrees() == deg);

    enum ResourceId
    {
        Texture,
    };
    sfe::ResourceContainer<sf::Texture, ResourceId> resources;

    auto str = sfe::Mouse::Button::ToString(sf::Mouse::Right);

    try
    {
        resources.load(Texture, "texture.png");

        auto& res = resources.require(Texture);
        resources.release(Texture);
    }
    catch (std::exception& ex)
    {
        printf("[EXCEPTION]: %s\n", ex.what());
    }
    

    return 0;
}