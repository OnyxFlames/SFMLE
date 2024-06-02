#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace sfe
{
	class FadingText : public sf::Drawable
	{
	private:
		sf::Text mText;

		sf::Time mFadeTime = sf::seconds(0.f);
		sf::Time mElapsed = sf::Time::Zero;
	public:
		FadingText() = default;
		explicit FadingText(sf::Text& text) : mText(text)
		{ }

		void reset()
		{
			mElapsed = sf::Time::Zero;
		}

		void setFadeTime(const sf::Time fadeTime)
		{
			mFadeTime = fadeTime;
		}

		void update(const sf::Time delta)
		{
			sf::Color color = mText.getFillColor();
			if (color.a > 0) color.a--;
			mText.setFillColor(color);
		}

		// Inherited via Drawable
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override
		{
			target.draw(mText, states);
		}

	};
}