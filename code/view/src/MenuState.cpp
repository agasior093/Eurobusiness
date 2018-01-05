#include "../include/MenuState.h"

view::MenuState::MenuState(std::shared_ptr<ApplicationData> data) 
	: m_data(data) 
{ }

void view::MenuState::initialise() {
	loadTextures();
	m_background.setTexture(this->m_data->resourceManager.getTexture("Background"));
	createButtons();
}

void view::MenuState::handleUserInput() {
	sf::Event evnt;
	while (this->m_data->window.pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed) {
			this->m_data->window.close();
		}
	}
}

void view::MenuState::update(sf::Time dt) {

}

void view::MenuState::draw() {
	this->m_data->window.clear();
	this->m_data->window.draw(m_background);
	this->m_data->window.draw(m_newGameButton.getSprite());
	this->m_data->window.display();
}

void view::MenuState::loadTextures() {
	this->m_data->resourceManager.loadTexture("Background", MENU_VIEW_BACKGROUND_FILE);
	this->m_data->resourceManager.loadTexture("New Game Button", NEW_GAME_BUTTON_FILE);
}

void view::MenuState::createButtons() {
	//New game button
	this->m_newGameButton.setTextures(NEW_GAME_BUTTON_FILE, NEW_GAME_BUTTON_FILE);
	this->m_newGameButton.getSprite().setTexture(this->m_data->resourceManager.getTexture("New Game Button"));
	this->m_newGameButton.getSprite().setPosition(40, 20);
}