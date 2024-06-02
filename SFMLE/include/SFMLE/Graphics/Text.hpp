#pragma once
#include <SFML/Graphics/Text.hpp>

namespace sfe
{
	struct Text
	{
		static void CenterOrigin(sf::Text& text)
		{
			auto GetMaxTextHeight = [&]()
			{
				const auto charSize = text.getCharacterSize();
				auto font = text.getFont();
				const auto& string = text.getString().toAnsiString();
				const bool bold = text.getStyle() & sf::Text::Bold;
				float max = 0.f;

				for (size_t i = 0; i < string.length(); ++i)
				{
					sf::Uint32 character = string[i];
					const auto& glyph = font->getGlyph(character, charSize, bold);
					const auto height = glyph.bounds.height;
					if (height <= max) continue;
					max = height;
				}

				return max;
			};

			sf::FloatRect rect = text.getLocalBounds();
			auto maxHeight = GetMaxTextHeight();
			text.setOrigin(
			{ 
				rect.left + (rect.width / 2.f), 
				rect.top + ((maxHeight >= rect.height ? maxHeight / 2.f : rect.height / 2.f)) 
			});
		}
	};
}