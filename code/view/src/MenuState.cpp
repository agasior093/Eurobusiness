#include "../include/MenuState.h"
#include "../include/GameState.h"

view::MenuState::MenuState(std::shared_ptr<ApplicationData> data)
	: m_data(data)	
{
	m_gui.setTarget(this->m_data->window);
}

void view::MenuState::initialise() {
	loadTextures();
	m_background.setTexture(this->m_data->resourceManager.getTexture("Background"));
	createButtons();
	
	auto textBox = tgui::TextBox::create();
	
	textBox->setRenderer(theme.getRenderer("Label"));
	textBox->setSize(100, 100);
	textBox->setPosition(100, 100);
	
	m_gui.add(textBox);
}

void view::MenuState::handleUserInput() {
	sf::Event evnt;
	while (this->m_data->window.pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed) {
			this->m_data->window.close();
		}
		if (this->m_data->inputManager.isSpriteClicked(this->m_newGameButton, evnt, this->m_data->window)) {
			m_data->stateManager.addState(std::unique_ptr<State>(new GameState(this->m_data)), true);
		}
	}
}

void view::MenuState::update(sf::Time dt) {

}

void view::MenuState::draw() {
	this->m_data->window.clear();
	this->m_data->window.draw(m_background);
	this->m_data->window.draw(m_newGameButton.getSprite());
	m_gui.draw();
	this->m_data->window.display();
}

void view::MenuState::loadTextures() {
	this->m_data->resourceManager.loadTexture("Background", MENU_STATE_BACKGROUND_FILE);
	this->m_data->resourceManager.loadTexture("New Game Button", NEW_GAME_BUTTON_FILE);
}

void view::MenuState::createButtons() {
	//New game button
	this->m_newGameButton.setTextures(this->m_data->resourceManager.getTexture("New Game Button"),
		this->m_data->resourceManager.getTexture("New Game Button"));
	this->m_newGameButton.enable();
	this->m_newGameButton.getSprite().setPosition(300, 300);
}