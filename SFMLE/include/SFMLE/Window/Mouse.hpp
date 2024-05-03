#pragma once
#include <string>
#include <SFML/Window/Mouse.hpp>
#include <unordered_map>

namespace sfe
{
	struct Mouse
	{
		struct Button
		{
			static std::string ToString(const sf::Mouse::Button button)
			{
				switch (button)
				{
				case sf::Mouse::Left: return "LMouse";
				case sf::Mouse::Right: return "RMouse";
				case sf::Mouse::Middle: return "MMouse";
				case sf::Mouse::XButton1: return "XButton1";
				case sf::Mouse::XButton2: return "XButton2";
				default: return "Unknown";
				}
			}

			static sf::Mouse::Button FromString(const std::string& button)
			{
				static std::unordered_map<std::string, sf::Mouse::Button> buttonNameMap
				{
					{ "LMouse", sf::Mouse::Left },
					{ "RMouse", sf::Mouse::Right },
					{ "MMouse", sf::Mouse::Middle },
					{ "XButton1", sf::Mouse::XButton1 },
					{ "XButton2", sf::Mouse::XButton2 },
				};

				if (!buttonNameMap.contains(button)) return sf::Mouse::ButtonCount;

				return buttonNameMap[button];
			}
		};


	};
}
