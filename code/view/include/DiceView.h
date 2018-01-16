#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DEFINITIONS.h"
#include <iostream>

namespace view {
	class Dice {
		sf::Texture m_texture;
		sf::RectangleShape m_shape;
		sf::SoundBuffer m_buffer;
		sf::Sound m_sound;
	public:
		Dice();
		~Dice() = default;
				
		void changeTexture(int);
		void playSound();
		sf::RectangleShape& get();
	};
}