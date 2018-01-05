#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>

namespace view {
	class ResourceManager {
		std::map<std::string, sf::Texture> m_textures;
		std::map<std::string, sf::Font> m_fonts;
		std::map<std::string, sf::SoundBuffer> m_soundBuffers;

	public:
		void loadTexture(std::string name, std::string fileName);
		sf::Texture& getTexture(std::string name);

		void loadFont(std::string name, std::string fileName);
		sf::Font& getFont(std::string name);

		void loadSoundBuffer(std::string name, std::string fileName);
		sf::SoundBuffer& getSoundBuffer(std::string name);
	};
}
