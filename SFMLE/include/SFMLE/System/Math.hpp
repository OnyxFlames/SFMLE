#pragma once

#include <type_traits>

namespace sfe
{
	struct Math
	{
		template <typename T>
		static T Snapped(T value, T step)
		{
			static_assert(std::is_floating_point_v<T>, "T must be floating point.");

			if (step != static_cast<T>(0))
			{
				value = std::floor(value / step + static_cast<T>(0.5)) * step;
			}

			return value;
		}
		template <typename T>
		static T Lerp(T from, T to, T weight)
		{
			return from + (to - from) * weight;
		}
	};
}