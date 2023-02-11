#pragma once

#include <SFML/Graphics/Rect.hpp>

namespace sfe
{

	struct Rect
	{
		template <typename T>
		static sf::Rect<T> Combine(const sf::Rect<T>& left, const sf::Rect<T>& right)
		{
			sf::Rect<T> result;

			result.left = std::min(left.left, right.left);
			result.top = std::min(left.top, right.top);
			result.width = std::max(left.width, right.width);
			result.height = std::max(left.height, right.height);

			return result;
		}
	};
}