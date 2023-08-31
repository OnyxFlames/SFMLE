#include "SFMLE/Graphics/RichText.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

namespace sfe
{
	void RichText::setString(const sf::String& string)
	{
		parseString(string);
	}
	void RichText::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		sf::Vector2f pos;
		for (auto& text : mTexts)
		{
			text.second.setPosition(text.first);

			target.draw(text.second);
			//pos.x += text.getLocalBounds().width;
		}
	}
}