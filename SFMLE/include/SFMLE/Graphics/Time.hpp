#pragma once

#include <string>
#include <format>

#include <SFML/System/Time.hpp>

namespace sfe
{
	struct Time
	{
		enum struct TimeFormat
		{
			Microseconds,
			Milliseconds,
			Seconds,
			DigitalClock,

			FormatCount,
		};

		static inline std::string ToString(const sf::Time& time, TimeFormat format = TimeFormat::Microseconds)
		{
			using enum TimeFormat;
			switch (format)
			{
			case Microseconds:	return std::format("{}us", time.asMicroseconds());
			case Milliseconds:	return std::format("{}ms", time.asMilliseconds());
			case Seconds:		return std::format("{}s", time.asSeconds());
			case DigitalClock:
			{
				int32_t hours = 0;
				int32_t minutes = 0;

				auto asMillis = time.asMilliseconds();
				constexpr auto hour = (1000 * 60 * 60);
				constexpr auto minute = (1000 * 60);

				while (asMillis >= hour)
				{
					asMillis -= hour;
					++hours;
				}

				while (asMillis >= minute)
				{
					asMillis -= minute;
					++minutes;
				}

				return std::format("{}:{}", hours, minutes);
			}

			}
		}
	};
}