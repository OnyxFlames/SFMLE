#pragma once

#include <utility>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/String.hpp>
#include <format>

namespace sfe
{
	class RichText : public sf::Drawable, public sf::Transformable
	{
	public:
		class Line : public sf::Drawable, public sf::Transformable
		{
			friend class RichText;
		private:
			mutable sf::FloatRect mBounds;
			mutable std::vector<sf::Text> mTexts;

			void updateBounds();
			void updateBounds(sf::Text& text);
		public:

			void addText(sf::Text& text);
			std::vector<sf::Text>& getTexts() { return mTexts; }
			void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

			sf::FloatRect getLocalBounds() const;
			sf::FloatRect getGlobalBounds() const;
		};
	private:
		sf::Font* mFont;
		std::vector<Line> mLines;

		sf::FloatRect mBounds;

		unsigned int mCharacterSize = 30;

		struct TextStroke
		{
			sf::Text::Style style = sf::Text::Regular;
			float outline = 0.f;
			sf::Color fcolor = sf::Color::White;
			sf::Color ocolor = sf::Color::White;
		} mCurrentStroke;


		void updateBounds();

		void handleAttribute(const sf::String& attr)
		{
			const static auto Contains = [&](const sf::String& string, const sf::String& substring)
			{
				return string.find(substring) != sf::String::InvalidPos;
			};

			// TODO: character size, outline color, underline, etc
			if (attr == "bold")		mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style | sf::Text::Bold);
			else if (attr == "/bold") mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style & (~sf::Text::Bold));
			else if (attr == "italic")		mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style | sf::Text::Italic);
			else if (attr == "/italic") mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style & (~sf::Text::Italic));
			else if (attr == "underline")	mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style | sf::Text::Underlined);
			else if (attr == "/underline") mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style & (~sf::Text::Underlined));
			else if (attr == "strike")		mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style | sf::Text::StrikeThrough);
			else if (attr == "/strike") mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style & (~sf::Text::StrikeThrough));
			else if (attr == "regular")		mCurrentStroke.style = sf::Text::Regular;
			else if (Contains(attr, "fcolor"))
			{
				size_t idx = attr.find("=#");
				if (idx == attr.InvalidPos) return;
				else
				{
					mCurrentStroke.fcolor = sf::Color(std::strtoul(attr.toAnsiString().c_str() + idx + 2, nullptr, 16));
				}
			}
			else if (Contains(attr, "ocolor"))
			{
				size_t idx = attr.find("=#");
				if (idx == attr.InvalidPos) return;
				else
				{
					mCurrentStroke.ocolor = sf::Color(std::strtoul(attr.toAnsiString().c_str() + idx + 2, nullptr, 16));
				}
			}
			else if (Contains(attr, "outline"))
			{
				size_t idx = attr.find("=");
				if (idx == attr.InvalidPos) return;
				else
				{
					mCurrentStroke.outline = std::strtof(attr.toAnsiString().c_str() + idx + 1, nullptr);
				}
			}
			//else if (attr[0] == '#') // TODO: add <fcolor=#XXXXXXXX> and <ocolor=#XXXXXXXX>
			//{
			//	size_t ptr = 0;
			//	const auto colorBuffer = attr.substring(1, attr.getSize() - 0).toAnsiString();
			//	mCurrentStroke.fcolor = sf::Color(std::strtoul(colorBuffer.c_str(), nullptr, 16));
			//}
		}

		sf::Text createText(const sf::String& string)
		{
			sf::Text text;

			text.setFont(*mFont);
			text.setStyle(mCurrentStroke.style);
			text.setString(string);
			text.setFillColor(mCurrentStroke.fcolor);
			text.setOutlineColor(mCurrentStroke.ocolor);
			text.setOutlineThickness(mCurrentStroke.outline);
			text.setCharacterSize(mCharacterSize);

			return text;
		}
	public:
		RichText() : mFont(nullptr) { }
		RichText(sf::Font& font) : mFont(&font)
		{
		}

		void setString(const sf::String& string);
		void setCharacterSize(unsigned int size);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};


}

