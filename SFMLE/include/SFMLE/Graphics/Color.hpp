#pragma once

#include <cassert>
#include <cstdint>
#include <utility>
#include <algorithm>

#include <SFML/Graphics/Color.hpp>

namespace sfe
{
	struct Color
	{
		// TODO: Add extended colors (3 from each color type)
		// from https://htmlcolorcodes.com/color-names/

		static inline sf::Color Blend(const sf::Color colorA, const sf::Color colorB, float factor = 0.5f);
		static inline sf::Color Darken(const sf::Color color, float factor = 0.10f);
		static inline sf::Color Lighten(const sf::Color color, float factor = 0.10f);
		static inline sf::Color Highlight(const sf::Color color);
	};

	struct RGBA
	{
		float r;
		float g;
		float b;
		float a;

		RGBA(const sf::Color& color)
			: r(color.r / 255.f)
			, g(color.g / 255.f)
			, b(color.b / 255.f)
			, a(color.a / 255.f)
		{ }

		RGBA(float _r, float _g, float _b, float _a = 1.f)
			: r(std::clamp(_r, 0.f, 1.f))
			, g(std::clamp(_g, 0.f, 1.f))
			, b(std::clamp(_b, 0.f, 1.f))
			, a(std::clamp(_a, 0.f, 1.f))
		{ }

		operator sf::Color()
		{
			return sf::Color
			(
				static_cast<uint8_t>(255 * r),
				static_cast<uint8_t>(255 * g),
				static_cast<uint8_t>(255 * b),
				static_cast<uint8_t>(255 * a)
			);
		}
	};

	struct HSL
	{
		static inline sf::Color ToColor(const HSL& hsl);
		static inline HSL FromColor(const sf::Color& color);

		int32_t h;
		float s;
		float l;

		HSL()
			: h()
			, s()
			, l()
		{ }

		HSL(const sf::Color& color)
		{
			*this = HSL::FromColor(color);
		}

		HSL(int32_t _h, float _s, float _l)
			: h(_h)
			, s(_s)
			, l(_l)
		{ }

		operator sf::Color()
		{
			return HSL::ToColor(*this);
		}
	};
}

#include <SFMLE/Graphics/Detail/Color.inl>