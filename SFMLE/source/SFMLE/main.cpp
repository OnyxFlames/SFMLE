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


int main()
{
    enum ResourceId
    {
        Texture,
    };
    sfe::ResourceContainer<sf::Texture, ResourceId> resources;

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