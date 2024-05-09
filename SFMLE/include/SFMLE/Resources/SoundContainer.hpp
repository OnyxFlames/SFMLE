#pragma once

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFMLE/Resources/ResourceContainer.hpp>


namespace sfe
{
	template <typename Identifier>
	using SoundContainer = ResourceContainer<sf::SoundBuffer, Identifier>;
}
