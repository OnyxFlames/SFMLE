#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFMLE/System/Vector2.hpp>

namespace sfe
{
	template <typename T>
	struct PolarVector2
	{
		T radius;
		T angle;

		PolarVector2() = default;

		PolarVector2(T rad, T ang) 
			: radius(rad)
			, angle(ang)
		{ }

		PolarVector2(const sf::Vector2<T>& vec);

		operator sf::Vector2<T>() const;
	};

	template <typename T>
	inline PolarVector2<T>::PolarVector2(const sf::Vector2<T>& vec)
		: radius(sfe::Vector2::LengthSquared<T>(vec))
		, angle(vec == sf::Vector2<T>() ? 0.f : sfe::Math::RadToDeg<T>(std::atan2(vec.y, vec.x)))
	{

	}


	template<typename T>
	inline PolarVector2<T>::operator sf::Vector2<T>() const
	{
		return sf::Vector2<T>
		{
			radius * std::cos(sfe::Math::DegToRad<T>(angle)),
			radius * std::sin(sfe::Math::DegToRad<T>(angle))
		};
	}

	typedef PolarVector2<float> PolarVector2f;

}

