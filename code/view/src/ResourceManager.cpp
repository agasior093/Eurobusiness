#include "../include/ResourceManager.h"

void view::ResourceManager::loadTexture(std::string name, std::string fileName) {
	sf::Texture texture;
	if (texture.loadFromFile(fileName)) {
		this->m_textures[name] = texture;
	}
	else {
		std::cout << "Cant load texture\n";
	}
}

void view::ResourceManager::loadFont(std::string name, std::string fileName) {
	sf::Font font;
	if (font.loadFromFile(fileName)) {
		this->m_fonts[name] = font;
	}
	else {
		std::cout << "Cant load font\n";
	}
}

void view::ResourceManager::loadSoundBuffer(std::string name, std::string fileName) {
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile(fileName)) {
		this->m_soundBuffers[name] = buffer;
	}
	else {
		std::cout << "Cant load font\n";
	}
}

sf::Texture& view::ResourceManager::getTexture(std::string name) {
	return this->m_textures.at(name); 
}

sf::Font& view::ResourceManager::getFont(std::string name) {
	return this->m_fonts.at(name);
}

sf::SoundBuffer& view::ResourceManager::getSoundBuffer(std::string name) {
	return this->m_soundBuffers.at(name);
}