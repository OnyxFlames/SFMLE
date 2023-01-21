
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
}