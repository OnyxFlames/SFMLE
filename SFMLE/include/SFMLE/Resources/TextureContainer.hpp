#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFMLE/Resources/ResourceContainer.hpp>

namespace sfe
{
	template <typename Identifier>
	using TextureContainer = ResourceContainer<sf::Texture, Identifier>;
}
