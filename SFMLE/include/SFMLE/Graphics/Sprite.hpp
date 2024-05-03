#pragma once

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace sfe
{
	struct Sprite
	{
		static void CenterOrigin(sf::Sprite& sprite)
		{
			const sf::FloatRect bounds = sprite.getLocalBounds();
			sprite.setOrigin({ bounds.width / 2.f, bounds.height / 2.f });
		}
	};
}