#pragma once
#include <string>
#include <SFML/Window/Keyboard.hpp>

#include <unordered_map>
#include <cassert>

namespace sfe
{
	namespace priv
	{
		static const std::unordered_map<std::string, sf::Keyboard::Key> BuildKeyNameTable();
		static const std::unordered_map<std::string, sf::Keyboard::Scancode> BuildScancodeNameTable();

		static const std::unordered_map<std::string, sf::Keyboard::Key> keyNameMap = BuildKeyNameTable();
		static const std::unordered_map<std::string, sf::Keyboard::Scancode> scancodeNameMap = BuildScancodeNameTable();
	}

	struct Keyboard
	{
	public:
		//static const std::string ToString(sf::Keyboard::Key key);
		//static const sf::Keyboard::Key FromString(const std::string& key);

		struct Key
		{
			static const std::string ToString(sf::Keyboard::Key key)
			{
				switch (key)
				{
				case sf::Keyboard::A: return "A";
				case sf::Keyboard::B: return "B";
				case sf::Keyboard::C: return "C";
				case sf::Keyboard::D: return "D";
				case sf::Keyboard::E: return "E";
				case sf::Keyboard::F: return "F";
				case sf::Keyboard::G: return "G";
				case sf::Keyboard::H: return "H";
				case sf::Keyboard::I: return "I";
				case sf::Keyboard::J: return "J";
				case sf::Keyboard::K: return "K";
				case sf::Keyboard::L: return "L";
				case sf::Keyboard::M: return "M";
				case sf::Keyboard::N: return "N";
				case sf::Keyboard::O: return "O";
				case sf::Keyboard::P: return "P";
				case sf::Keyboard::Q: return "Q";
				case sf::Keyboard::R: return "R";
				case sf::Keyboard::S: return "S";
				case sf::Keyboard::T: return "T";
				case sf::Keyboard::U: return "U";
				case sf::Keyboard::V: return "V";
				case sf::Keyboard::W: return "W";
				case sf::Keyboard::X: return "X";
				case sf::Keyboard::Y: return "Y";
				case sf::Keyboard::Z: return "Z";
				case sf::Keyboard::Num0: return "Num0";
				case sf::Keyboard::Num1: return "Num1";
				case sf::Keyboard::Num2: return "Num2";
				case sf::Keyboard::Num3: return "Num3";
				case sf::Keyboard::Num4: return "Num4";
				case sf::Keyboard::Num5: return "Num5";
				case sf::Keyboard::Num6: return "Num6";
				case sf::Keyboard::Num7: return "Num7";
				case sf::Keyboard::Num8: return "Num8";
				case sf::Keyboard::Num9: return "Num9";
				case sf::Keyboard::Escape: return "Escape";
				case sf::Keyboard::LControl: return "LControl";
				case sf::Keyboard::LShift: return "LShift";
				case sf::Keyboard::LAlt: return "LAlt";
				case sf::Keyboard::LSystem: return "LSystem";
				case sf::Keyboard::RControl: return "RControl";
				case sf::Keyboard::RShift: return "RShift";
				case sf::Keyboard::RAlt: return "RAlt";
				case sf::Keyboard::RSystem: return "RSystem";
				case sf::Keyboard::Menu: return "Menu";
				case sf::Keyboard::LBracket: return "LBracket";
				case sf::Keyboard::RBracket: return "RBracket";
				case sf::Keyboard::Semicolon: return "Semicolon";
				case sf::Keyboard::Comma: return "Comma";
				case sf::Keyboard::Period: return "Period";
				case sf::Keyboard::Quote: return "Quote";
				case sf::Keyboard::Slash: return "Slash";
				case sf::Keyboard::Backslash: return "Backslash";
				case sf::Keyboard::Tilde: return "Tilde";
				case sf::Keyboard::Equal: return "Equal";
				case sf::Keyboard::Hyphen: return "Hyphen";
				case sf::Keyboard::Space: return "Space";
				case sf::Keyboard::Enter: return "Enter";
				case sf::Keyboard::Backspace: return "Backspace";
				case sf::Keyboard::Tab: return "Tab";
				case sf::Keyboard::PageUp: return "PageUp";
				case sf::Keyboard::PageDown: return "PageDown";
				case sf::Keyboard::End: return "End";
				case sf::Keyboard::Home: return "Home";
				case sf::Keyboard::Insert: return "Insert";
				case sf::Keyboard::Delete: return "Delete";
				case sf::Keyboard::Add: return "Add";
				case sf::Keyboard::Subtract: return "Subtract";
				case sf::Keyboard::Multiply: return "Multiply";
				case sf::Keyboard::Divide: return "Divide";
				case sf::Keyboard::Left: return "Left";
				case sf::Keyboard::Right: return "Right";
				case sf::Keyboard::Up: return "Up";
				case sf::Keyboard::Down: return "Down";
				case sf::Keyboard::Numpad0: return "Numpad0";
				case sf::Keyboard::Numpad1: return "Numpad1";
				case sf::Keyboard::Numpad2: return "Numpad2";
				case sf::Keyboard::Numpad3: return "Numpad3";
				case sf::Keyboard::Numpad4: return "Numpad4";
				case sf::Keyboard::Numpad5: return "Numpad5";
				case sf::Keyboard::Numpad6: return "Numpad6";
				case sf::Keyboard::Numpad7: return "Numpad7";
				case sf::Keyboard::Numpad8: return "Numpad8";
				case sf::Keyboard::Numpad9: return "Numpad9";
				case sf::Keyboard::F1: return "F1";
				case sf::Keyboard::F2: return "F2";
				case sf::Keyboard::F3: return "F3";
				case sf::Keyboard::F4: return "F4";
				case sf::Keyboard::F5: return "F5";
				case sf::Keyboard::F6: return "F6";
				case sf::Keyboard::F7: return "F7";
				case sf::Keyboard::F8: return "F8";
				case sf::Keyboard::F9: return "F9";
				case sf::Keyboard::F10: return "F10";
				case sf::Keyboard::F11: return "F11";
				case sf::Keyboard::F12: return "F12";
				case sf::Keyboard::F13: return "F13";
				case sf::Keyboard::F14: return "F14";
				case sf::Keyboard::F15: return "F15";
				case sf::Keyboard::Pause: return "Pause";
				default: return "Unknown";
				}
			}

			static const sf::Keyboard::Key FromString(const std::string& key)
			{
				if (!priv::keyNameMap.contains(key)) sf::Keyboard::Unknown;

				return priv::keyNameMap.at(key);
			}
		};

		struct Scancode
		{
			static const std::string ToString(sf::Keyboard::Scancode scancode)
			{
				using enum sf::Keyboard::Scancode;
				switch (scancode)
				{
					case A: return "A";
					case B: return "B";
					case C: return "C";
					case D: return "D";
					case E: return "E";
					case F: return "F";
					case G: return "G";
					case H: return "H";
					case I: return "I";
					case J: return "J";
					case K: return "K";
					case L: return "L";
					case M: return "M";
					case N: return "N";
					case O: return "O";
					case P: return "P";
					case Q: return "Q";
					case R: return "R";
					case S: return "S";
					case T: return "T";
					case U: return "U";
					case V: return "V";
					case W: return "W";
					case X: return "X";
					case Y: return "Y";
					case Z: return "Z";
					case Num0: return "Num0";
					case Num1: return "Num1";
					case Num2: return "Num2";
					case Num3: return "Num3";
					case Num4: return "Num4";
					case Num5: return "Num5";
					case Num6: return "Num6";
					case Num7: return "Num7";
					case Num8: return "Num8";
					case Num9: return "Num9";
					case Enter: return "Enter";
					case Escape: return "Escape";
					case Backspace: return "Backspace";
					case Tab: return "Tab";
					case Space: return "Space";
					case Hyphen: return "Hyphen";
					case Equal: return "Equal";
					case LBracket: return "LBracket";
					case RBracket: return "RBracket";
					case Backslash: return "Backslash";
					case Semicolon: return "Semicolon";
					case Apostrophe: return "Apostrophe";
					case Grave: return "Grave";
					case Comma: return "Comma";
					case Period: return "Period";
					case Slash: return "Slash";
					case F1: return "F1";
					case F2: return "F2";
					case F3: return "F3";
					case F4: return "F4";
					case F5: return "F5";
					case F6: return "F6";
					case F7: return "F7";
					case F8: return "F8";
					case F9: return "F9";
					case F10: return "F10";
					case F11: return "F11";
					case F12: return "F12";
					case F13: return "F13";
					case F14: return "F14";
					case F15: return "F15";
					case F16: return "F16";
					case F17: return "F17";
					case F18: return "F18";
					case F19: return "F19";
					case F20: return "F20";
					case F21: return "F21";
					case F22: return "F22";
					case F23: return "F23";
					case F24: return "F24";
					case CapsLock: return "CapsLock";
					case PrintScreen: return "PrintScreen";
					case ScrollLock: return "ScrollLock";
					case Pause: return "Pause";
					case Insert: return "Insert";
					case Home: return "Home";
					case PageUp: return "PageUp";
					case Delete: return "Delete";
					case End: return "End";
					case PageDown: return "PageDown";
					case Right: return "Right";
					case Left: return "Left";
					case Down: return "Down";
					case Up: return "Up";
					case NumLock: return "NumLock";
					case NumpadDivide: return "NumpadDivide";
					case NumpadMultiply: return "NumpadMultiply";
					case NumpadMinus: return "NumpadMinus";
					case NumpadPlus: return "NumpadPlus";
					case NumpadEqual: return "NumpadEqual";
					case NumpadEnter: return "NumpadEnter";
					case NumpadDecimal: return "NumpadDecimal";
					case Numpad1: return "Numpad1";
					case Numpad2: return "Numpad2";
					case Numpad3: return "Numpad3";
					case Numpad4: return "Numpad4";
					case Numpad5: return "Numpad5";
					case Numpad6: return "Numpad6";
					case Numpad7: return "Numpad7";
					case Numpad8: return "Numpad8";
					case Numpad9: return "Numpad9";
					case Numpad0: return "Numpad0";

					default: return "Unknown";

				}
			}
			static const sf::Keyboard::Scancode FromString(const std::string& scancode)
			{
				if (!priv::scancodeNameMap.contains(scancode)) sf::Keyboard::Scan::Unknown;

				return priv::scancodeNameMap.at(scancode);
			}
		};
	};

	namespace priv
	{
		static const std::unordered_map<std::string, sf::Keyboard::Key> BuildKeyNameTable()
		{
			std::unordered_map<std::string, sf::Keyboard::Key> table;

			for (size_t i = 0; i < sf::Keyboard::Key::KeyCount; ++i) table[sfe::Keyboard::Key::ToString(static_cast<sf::Keyboard::Key>(i))] = static_cast<sf::Keyboard::Key>(i);

			return table;
		}

		static const std::unordered_map<std::string, sf::Keyboard::Scancode> BuildScancodeNameTable()
		{
			std::unordered_map<std::string, sf::Keyboard::Scancode> table;

			for (size_t i = 0; i < sf::Keyboard::Scancode::ScancodeCount; ++i) table[sfe::Keyboard::Scancode::ToString(static_cast<sf::Keyboard::Scancode>(i))] = static_cast<sf::Keyboard::Scancode>(i);

			return table;
		}
	}
}