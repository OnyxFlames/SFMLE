#pragma once
#include <string>

#include <SFML/Window/Event.hpp>
#include <unordered_map>

namespace sfe
{
	namespace priv
	{
		static const std::unordered_map<std::string, sf::Event::EventType> BuildEventTypeNameTable();

		static const std::unordered_map<std::string, sf::Event::EventType> eventNameMap = BuildEventTypeNameTable();
	}

	struct Event
	{
		struct EventType
		{
			static std::string ToString(const sf::Event::EventType &type)
			{
				using enum sf::Event::EventType;
				switch (type)
				{
				case Closed: return "Closed";
				case Resized: return "Resized";
				case LostFocus: return "LostFocus";
				case GainedFocus: return "GainedFocus";
				case TextEntered: return "TextEntered";
				case KeyPressed: return "KeyPressed";
				case KeyReleased: return "KeyReleased";
				case MouseWheelMoved: return "MouseWheelMoved";
				case MouseWheelScrolled: return "MouseWheelScrolled";
				case MouseButtonPressed: return "MouseButtonPressed";
				case MouseButtonReleased: return "MouseButtonReleased";
				case MouseMoved: return "MouseMoved";
				case MouseEntered: return "MouseEntered";
				case MouseLeft: return "MouseLeft";
				case JoystickButtonPressed: return "JoystickButtonPressed";
				case JoystickButtonReleased: return "JoystickButtonReleased";
				case JoystickMoved: return "JoystickMoved";
				case JoystickConnected: return "JoystickConnected";
				case JoystickDisconnected: return "JoystickDisconnected";
				case TouchBegan: return "TouchBegan";
				case TouchMoved: return "TouchMoved";
				case TouchEnded: return "TouchEnded";
				case SensorChanged: return "SensorChanged";
				default: return "Unknown";
				}
			}

			static const sf::Event::EventType FromString(const std::string& scancode)
			{
				if (!priv::eventNameMap.contains(scancode)) return sf::Event::EventType::Count;

				return priv::eventNameMap.at(scancode);
			}
		};
	};

	namespace priv
	{
		static const std::unordered_map<std::string, sf::Event::EventType> BuildEventTypeNameTable()
		{
			std::unordered_map<std::string, sf::Event::EventType> table;

			for (size_t i = 0; i < sf::Event::EventType::Count; ++i) table[sfe::Event::EventType::ToString(static_cast<sf::Event::EventType>(i))] = static_cast<sf::Event::EventType>(i);

			return table;
		}
	}
}