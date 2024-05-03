#pragma once
#include <string>
#include <SFML/Window/Keyboard.hpp>

namespace sfe
{
	struct Keyboard
	{
		static std::string ToString(sf::Keyboard::Key key);
		static sf::Keyboard::Key FromString(const std::string& key);

		struct Scancode
		{
			static std::string ToString(sf::Keyboard::Scancode scancode);
			static sf::Keyboard::Scancode FromString(const std::string& scancode);
		};
	};
}

