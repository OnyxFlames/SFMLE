#pragma once

#include <cassert>
#include <cstdint>

#include <SFML/Graphics/Color.hpp>


namespace sfe
{
	struct Color
	{
		// TODO: Add extended colors (3 from each color type)
		// from https://htmlcolorcodes.com/color-names/

		static inline sf::Color Blend(const sf::Color& colorA, const sf::Color& colorB, float factor = 0.5f);
	};
}

#include <SFMLE/Graphics/Color.inl>