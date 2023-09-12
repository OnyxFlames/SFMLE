#include "SFMLE/Graphics/RichText.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

namespace sfe
{
	namespace
	{
		inline std::vector<sf::String> split(const sf::String& string, sf::Uint32 delimiter)
		{
			if (string.isEmpty()) return {};

			std::vector<sf::String> results;
			sf::String buffer;
			for (auto c : string)
			{
				if (c == delimiter)
				{
					results.push_back(buffer);
					buffer.clear();
				}
				else
				{
					buffer += c;
				}
			}

			if (!buffer.isEmpty() || string[string.getSize() - 1] == delimiter) results.push_back(buffer);

			return results;
		}
	}

	void RichText::Line::updateBounds()
	{
		mBounds = {};
		for (auto& text : mTexts) updateBounds(text);
	}

	void RichText::Line::updateBounds(sf::Text& text)
	{
		text.setPosition(mBounds.width, 0.f);

		auto lineSpacing = std::floor(text.getFont()->getLineSpacing(text.getCharacterSize()));
		mBounds.height = std::max(mBounds.height, lineSpacing);
		mBounds.width += text.getGlobalBounds().width;
	}

	void RichText::Line::addText(sf::Text& text)
	{
		updateBounds(text);
		mTexts.push_back(text);
	}

	// TODO: maybe write all of the text to a RenderTexture to be more efficient?
	void RichText::Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		for (const auto& text : mTexts) target.draw(text, states);
	}

	sf::FloatRect RichText::Line::getLocalBounds() const
	{
		return mBounds;
	}

	sf::FloatRect RichText::Line::getGlobalBounds() const
	{
		const auto& transform = getTransform();
		return transform.transformRect(getLocalBounds());
	}

	inline void validateAttributes(const sf::String& string)
	{
		for (size_t i = 0; i < string.getSize(); ++i)
		{
			if (string[i] == '<')
			{
				while (string[i] != '>')
				{
					++i;
					if (string[i] == '\n') throw std::format_error("Attributes cannot contain newlines.");
				}
			}
		}
	}

	sf::String parseAttribute(sf::String::ConstIterator itr)
	{
		sf::String buffer;
		++itr;
		while (*itr != '>') buffer += *itr++;

		return buffer;
	}

	void RichText::updateBounds()
	{
		mBounds = {};
		for (auto& line : mLines)
		{
			line.updateBounds();
			line.setPosition(0.f, mBounds.height);
			mBounds.height += line.getGlobalBounds().height;
			mBounds.width = std::max(mBounds.width, line.getGlobalBounds().width);
		}
	}

	void RichText::setString(const sf::String& string)
	{
		if (string.isEmpty()) return;

		validateAttributes(string);

		auto strings = split(string, '\n');

		for (const auto& string : strings)
		{
			for (size_t i = 0; i < string.getSize();)
			{
				if (string[i] == '<' && !(i > 0 && string[i - 1] == '\\'))
				{
					//if (i > 0 && string[i - 1] == '\\') continue;
					sf::String attribute;
					while (string[i + 1] != '>') attribute += string[++i];
					i += 2;
					handleAttribute(attribute);
					
				}
				else
				{
					sf::String buffer;
					if (string[i] == '\\' && string[i + 1] == '<') { buffer += "<"; i += 2; }

					while (string[i] != '<' && i < string.getSize()) buffer += string[i++];

					auto text = createText(buffer);

					if (mLines.size() == 0) mLines.emplace_back();

					auto& line = mLines.back();
					mBounds.height -= line.getGlobalBounds().height;

					line.addText(text);
					mBounds.height += line.getGlobalBounds().height;
					mBounds.width = std::max(mBounds.width, line.getGlobalBounds().width);
				}
			}
			mLines.emplace_back();
			auto& line = mLines.back();
			line.setPosition(0.f, mBounds.height);
		}
	}

	void RichText::setCharacterSize(unsigned int size)
	{
		mCharacterSize = size;
		for (auto& line : mLines)
		{ 
			for (auto& text : line.getTexts())
			{
				text.setCharacterSize(mCharacterSize);
			}
		}

		updateBounds();
	}

	void RichText::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		for (auto& line : mLines) target.draw(line, states);
	}


}