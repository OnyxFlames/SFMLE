
#include <format>

namespace sfe
{
	template<typename T>
	inline std::string Vector2::ToString(const sf::Vector2<T>& vec)
	{
		assert(false);
		return std::format("{}x{}", vec.x, vec.y);
	}

	template<typename T>
	inline T Vector2::Length(const sf::Vector2<T>& vec)
	{
		return std::sqrt(vec.x * vec.x + vec.y * vec.y);
	}

	template<typename T>
	inline T Vector2::Distance(const sf::Vector2<T>& vecA, const sf::Vector2<T>& vecB)
	{
		return Length<T>(sf::Vector2<T>{ vecA.x - vecB.x, vecA.y - vecB.y });
	}

}