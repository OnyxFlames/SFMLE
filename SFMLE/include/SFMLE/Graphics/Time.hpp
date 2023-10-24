#pragma once

#include <string>
#include <format>

#include <SFML/System/Time.hpp>

namespace sfe
{
	struct Time
	{
		enum struct Format
		{
			Default,
			Microseconds,
			Milliseconds,
			Seconds,
			MinutesOnly,
			Hours,
			DigitalClock,
			DigitalClockSeconds,

			FormatCount,
		};

		static inline std::string ToString(const sf::Time& time, Format format = Format::Default)
		{
			using enum Format;
			switch (format)
			{

			case Microseconds:	return std::format("{}us", time.asMicroseconds());
			case Milliseconds:	return std::format("{}ms", time.asMilliseconds());
			case Seconds:		return std::format("{}s", time.asSeconds());
			case MinutesOnly:	return std::format("{} minutes", (int32_t)(time.asSeconds() / 60.f));
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

				return std::format("{:02}:{:02}", hours, minutes);
			}
			case DigitalClockSeconds:
			{
				int32_t hours = 0;
				int32_t minutes = 0;
				int32_t seconds = 0;

				auto asMillis = time.asMilliseconds();
				constexpr auto hour = (1000 * 60 * 60);
				constexpr auto minute = (1000 * 60);
				constexpr auto second = (1000);

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

				while (asMillis >= second)
				{
					asMillis -= second;
					++seconds;
				}

				return std::format("{:02}:{:02}:{:02}", hours, minutes, seconds);
			}
			default:
				if (time.asSeconds() > 1.0f) return ToString(time, Format::Seconds);
				if (time.asMilliseconds() > 1) return ToString(time, Format::Milliseconds);

				return ToString(time, Format::Microseconds);
				break;
			}
		}
	};

	inline sf::Time minutes(const float minutes)
	{
		return sf::seconds(60.f * minutes);
	}

	inline sf::Time hours(const float hours)
	{
		return sfe::minutes(60.f * hours);
	}
}