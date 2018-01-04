#include "../include/Button.h"

void Button::setTextures(std::string enabledFilePath, std::string disabledFilePath) {
	m_enabledTexture.loadFromFile(enabledFilePath);
	m_disabledTexture.loadFromFile(disabledFilePath);
}

void Button::enable() {
	m_enabled = true;
	m_sprite.setTexture(m_enabledTexture);
}

void Button::disable() {
	m_enabled = false;
	m_sprite.setTexture(m_disabledTexture);
}