
#include <format>
#include "Vector2.hpp"

namespace sfe
{
	template<typename T>
	inline std::string Vector2::ToString(const sf::Vector2<T>& vec)
	{
		return std::format("({}, {})", vec.x, vec.y);
	}

	template<typename T>
	inline sf::Vector2<T> Vector2::Lerp(const sf::Vector2<T>& from, const sf::Vector2<T>& to, const T weight)
	{
		return sf::Vector2<T>
		{
			Math::Lerp(from.x, to.x, weight),
			Math::Lerp(from.y, to.y, weight)
		};
	}

	template<typename T>
	inline T Vector2::Dot(const sf::Vector2<T>& vec1, const sf::Vector2<T>& vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y;
	}

	template<typename T>
	inline T Vector2::Cross(const sf::Vector2<T>& vec1, const sf::Vector2<T>& vec2)
	{
		return vec1.x * vec2.y + vec1.y * vec2.x;
	}

	template<typename T>
	inline T Vector2::Length(const sf::Vector2<T>& vec)
	{
		return vec.x * vec.x + vec.y * vec.y;
	}

	template<typename T>
	inline T Vector2::LengthSquared(const sf::Vector2<T>& vec)
	{
		return std::sqrt(vec.x * vec.x + vec.y * vec.y);
	}

	template<typename T>
	inline sf::Vector2<T> Vector2::Normalized(const sf::Vector2<T>& vec)
	{
		auto l = Length<T>(vec);

		if (l != static_cast<T>(0))
		{
			l = std::sqrt(l);
			return { vec.x / l, vec.y / l };
		}

		return vec;
	}

	template<typename T>
	inline sf::Vector2<T> Vector2::Rotated(const sf::Vector2<T>& vec, const T angle)
	{
		const T sine = std::sin(angle);
		const T cosine = std::cos(angle);

		return sf::Vector2<T>{ vec.x * cosine - vec.y * sine, vec.x * sine + vec.y * cosine };
	}

	template<typename T>
	inline T Vector2::Distance(const sf::Vector2<T>& vecA, const sf::Vector2<T>& vecB)
	{
		return LengthSquared<T>(sf::Vector2<T>{ vecA.x - vecB.x, vecA.y - vecB.y });
	}

}