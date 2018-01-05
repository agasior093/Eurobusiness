#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DEFINITIONS.h"

namespace view {
	struct ApplicationData;

	class Dice {
		sf::Texture m_texture;
		sf::RectangleShape m_dice;
		sf::SoundBuffer m_buffer;
		sf::Sound m_sound;
	public:
		Dice();
		~Dice() = default;
		sf::RectangleShape& get();
		void setTexture(std::string);
		void changeTexture(unsigned);
		void playSound();
	};
}