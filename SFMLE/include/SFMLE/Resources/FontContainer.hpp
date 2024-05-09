#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFMLE/Resources/ResourceContainer.hpp>

namespace sfe
{
	template <typename Identifier>
	using FontContainer = ResourceContainer<sf::Font, Identifier>;
}
