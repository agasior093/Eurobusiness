#include "../include/Button.h"

 sf::Sprite& view::Button::getSprite() {
	return m_sprite;
}

 bool view::Button::isEnabled() const {
	return m_enabled;
}

void view::Button::setTextures(std::string enabledFilePath, std::string disabledFilePath) {
	m_enabledTexture.loadFromFile(enabledFilePath);
	m_disabledTexture.loadFromFile(disabledFilePath);
}

void view::Button::enable() {
	m_enabled = true;
	m_sprite.setTexture(m_enabledTexture);
}

void view::Button::disable() {
	m_enabled = false;
	m_sprite.setTexture(m_disabledTexture);
}

