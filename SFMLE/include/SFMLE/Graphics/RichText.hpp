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
		private:
			mutable sf::FloatRect mBounds;
			mutable std::vector<sf::Text> mTexts;

			void updateBounds(sf::Text& text);
		public:

			void addText(sf::Text& text);

			void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

			sf::FloatRect getLocalBounds() const;
			sf::FloatRect getGlobalBounds() const;
		};
	private:
		sf::Font* mFont;
		std::vector<Line> mLines;

		sf::FloatRect mBounds;

		struct TextStroke
		{
			sf::Text::Style style;
			sf::Color color = sf::Color::White;
		} mCurrentStroke;


		void handleAttribute(const sf::String& attr)
		{
			// TODO: character size, outline color, underline, etc
			const auto ansiString = attr.toAnsiString();
			printf("Attribute: '%s'\n", ansiString.c_str());
			if (attr == "bold") mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style | sf::Text::Bold);
			else if (attr == "italic") mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style | sf::Text::Italic);
			else if (attr == "underline") mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style | sf::Text::Underlined);
			else if (attr == "strike") mCurrentStroke.style = static_cast<sf::Text::Style>(mCurrentStroke.style | sf::Text::StrikeThrough);
			else if (attr == "regular") mCurrentStroke.style = sf::Text::Regular;
			else if (attr[0] == '#') // TODO: add <fcolor=#XXXXXXXX> and <ocolor=#XXXXXXXX>
			{
				size_t ptr = 0;
				const auto colorBuffer = attr.substring(1, attr.getSize() - 0).toAnsiString();
				mCurrentStroke.color = sf::Color(std::strtoul(colorBuffer.c_str(), nullptr, 16));
			}
		}

		sf::Text createText(const sf::String& string)
		{
			sf::Text text;

			text.setFont(*mFont);
			text.setStyle(mCurrentStroke.style);
			text.setString(string);
			text.setFillColor(mCurrentStroke.color);

			return text;
		}

		void parseString(const sf::String& string)
		{
			//const auto stringSize = string.getSize();
			//for (size_t i = 0; i < stringSize;)
			//{
			//	if (string[i] == '<')
			//	{
			//		sf::String attrBuffer;
			//		while (string[i] != '>' && i < stringSize) attrBuffer += string[++i];
			//		attrBuffer.erase(attrBuffer.getSize() - 1);
			//		const auto ansiString = attrBuffer.toAnsiString();
			//		handleAttribute(attrBuffer);
			//		if (string[i] != '>') throw std::format_error(std::format("Invalid tag {}", attrBuffer.toAnsiString()));
			//		++i;
			//	}
			//	else
			//	{
			//		sf::String textBuffer;

			//		while (string[i] != '<' && i < stringSize)
			//		{
			//			textBuffer += string[i++];
			//		}

			//		sf::Text text;
			//		text.setFont(*mFont);
			//		text.setStyle(mCurrentStroke.style);
			//		text.setFillColor(mCurrentStroke.color);
			//		text.setString(textBuffer);
			//		//text.setOrigin({ text.getLocalBounds().width, text.getLocalBounds().height });

			//		sf::Vector2f offset = mTexts.size() > 0 ? sf::Vector2f{ mTexts.back().first.x + mTexts.back().second.getLocalBounds().width, mTexts.back().first.y } : sf::Vector2f{};

			//		mTexts.emplace_back(offset, text);
			//	}
			//}
		}
	public:
		RichText() : mFont(nullptr) { }
		RichText(sf::Font& font) : mFont(&font)
		{
		}

		void setString(const sf::String& string);

		// Inherited via Drawable
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};


}

