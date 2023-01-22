#pragma once

#include <string>

#include <SFML/System/Vector2.hpp>

namespace sfe
{
	struct Vector2
	{
		template <typename T>
		static std::string ToString(const sf::Vector2<T>& vec);

		// NOTE: These functions will be removed when SFML adds support for these functions natively

		// TODO: Add template metaprogramming to only enable when T is float/double
		template <typename T>
		static T Length(const sf::Vector2<T>& vec);
		// TODO: Add template metaprogramming to only enable when T is float/double
		template <typename T>
		static T Distance(const sf::Vector2<T>& vecA, const sf::Vector2<T>& vecB);
	};
}

#include <SFMLE/System/Detail/Vector2.inl>