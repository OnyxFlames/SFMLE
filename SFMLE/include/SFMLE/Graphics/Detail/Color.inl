namespace sfe
{
	sf::Color Color::Blend(const sf::Color& colorA, const sf::Color& colorB, float factor)
	{
		assert(factor >= 0.f && factor <= 1.f);
		const float other = 1.f - factor;

		return sf::Color
		(
			static_cast<uint8_t>(colorA.r * factor) + static_cast<uint8_t>(colorB.r * other),
			static_cast<uint8_t>(colorA.g * factor) + static_cast<uint8_t>(colorB.g * other),
			static_cast<uint8_t>(colorA.b * factor) + static_cast<uint8_t>(colorB.b * other),
			static_cast<uint8_t>(colorA.a * factor) + static_cast<uint8_t>(colorB.a * other)
		);
	}

	inline sf::Color Color::Darken(const sf::Color& color, float factor)
	{
		auto hsl = HSL(color);
		if (hsl.l < factor) hsl.l = 0.f;
		else hsl.l -= factor;
		const auto newColor = HSL::ToColor(hsl);
		return sf::Color(newColor.r, newColor.g, newColor.b, color.a);
	}

	inline sf::Color Color::Lighten(const sf::Color& color, float factor)
	{
		auto hsl = HSL(color);
		if (hsl.l + factor > 1.f) hsl.l = 1.f;
		else hsl.l += factor;
		const auto newColor = HSL::ToColor(hsl);
		return sf::Color(newColor.r, newColor.g, newColor.b, color.a);
	}

	inline sf::Color sfe::HSL::ToColor(const HSL& hsl)
	{
		const auto HueToRGB = [](float v1, float v2, float vH)
		{
			if (vH < 0) vH += 1.f;

			if (vH > 1.f) vH -= 1.f;

			if ((6 * vH) < 1) return (v1 + (v2 - v1) * 6 * vH);

			if ((2 * vH) < 1) return v2;

			if ((3 * vH) < 2) return (v1 + (v2 - v1) * ((2.f / 3) - vH) * 6);

			return v1;
		};

		uint8_t r = 0;
		uint8_t g = 0;
		uint8_t b = 0;

		if (hsl.s == 0)
		{
			r = g = b = (uint8_t)(hsl.l * 255.f);
		}
		else
		{
			float v1, v2;
			float hue = hsl.h / 360.f;

			v2 = (hsl.l < 0.5f) ? (hsl.l * (1 + hsl.s)) : (hsl.l + hsl.s) - (hsl.l * hsl.s);
			v1 = 2 * hsl.l - v2;

			r = (uint8_t)(255.f * HueToRGB(v1, v2, hue + (1.f / 3)));
			g = (uint8_t)(255.f * HueToRGB(v1, v2, hue));
			b = (uint8_t)(255.f * HueToRGB(v1, v2, hue - (1.f / 3)));
		}

		return sf::Color(r, g, b, 255);
	}

	inline HSL sfe::HSL::FromColor(const sf::Color& color)
	{
		const float r = color.r / 255.f;
		const float g = color.g / 255.f;
		const float b = color.b / 255.f;

		const float min = std::min(std::min(r, g), b);
		const float max = std::max(std::max(r, g), b);
		const float delta = max - min;

		HSL hsl;

		hsl.l = (max + min) / 2.f;

		if (delta == 0)
		{
			hsl.h = 0;
			hsl.s = 0.f;
		}
		else
		{
			hsl.s = (hsl.l <= 0.5f) ? (delta / (max + min)) : (delta / (2 - max - min));

			float hue;

			if (r == max) hue = ((g - b) / 6) / delta;
			else if (g == max) hue = (1.f / 3) + ((b - r) / 6) / delta;
			else hue = (2.f / 3) + ((r - g) / 6) / delta;

			if (hue < 0) hue += 1.f;
			if (hue > 1) hue -= 1.f;

			hsl.h = (int)(hue * 360.f);
		}

		return hsl;
	}
}