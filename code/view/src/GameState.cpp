#include "../include/GameState.h"

view::GameState::GameState(std::shared_ptr<ApplicationData> data)
	: m_data(data), m_game(2, m_playerNames.getNames())
{ }

void view::GameState::initialise() {
	loadResources();
	createBackground();
	createButtons();
	createDice();
}

void view::GameState::handleUserInput() {
	sf::Event evnt;
	while (this->m_data->window.pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed) {
			this->m_data->window.close();
		}

		if (this->m_data->inputManager.isSpriteClicked(this->m_rollButton, evnt, this->m_data->window)) {
			rollTheDice();
		}
	}
}

void view::GameState::update(sf::Time dt) {

}

void view::GameState::draw() {
	this->m_data->window.clear();

	//drawing background
	this->m_data->window.draw(m_background);

	//drawing dice
	this->m_data->window.draw(m_firstDice.get());
	this->m_data->window.draw(m_secondDice.get());

	//drawing buttons
	this->m_data->window.draw(m_endTurnButton.getSprite());	
	this->m_data->window.draw(m_rollButton.getSprite());
	
	this->m_data->window.draw(m_payButton.getSprite());

	//displaying window
	this->m_data->window.display();
}

void view::GameState::loadResources() {
	//button textures
	this->m_data->resourceManager.loadTexture("Roll the dice", ROLL_THE_DICE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled roll the dice", DISABLED_ROLL_THE_DICE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("End turn", END_TURN_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled end turn", DISABLED_END_TURN_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Pay button", PAY_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled pay button", DISABLED_PAY_BUTTON_FILE);
}

void view::GameState::createBackground() {
	this->m_background.setTexture(this->m_data->resourceManager.getTexture("Background"));
}

void view::GameState::createButtons() {
	//roll dice button
	this->m_rollButton.setTextures(this->m_data->resourceManager.getTexture("Roll the dice"),
		this->m_data->resourceManager.getTexture("Disabled roll the dice"));
	this->m_rollButton.enable();
	m_rollButton.getSprite().setPosition(40, 270);

	//end turn button
	this->m_endTurnButton.setTextures(this->m_data->resourceManager.getTexture("End turn"),
		this->m_data->resourceManager.getTexture("Disabled end turn"));
	this->m_endTurnButton.enable();
	m_endTurnButton.getSprite().setPosition(40, 390);

	//pay button
	this->m_payButton.setTextures(this->m_data->resourceManager.getTexture("Pay button"),
		this->m_data->resourceManager.getTexture("Disabled pay button"));
	this->m_payButton.enable();
	m_payButton.getSprite().setPosition(880, 320);
}

void view::GameState::createDice() {
	m_firstDice.get().setPosition(FIRST_DICE_POSITION_X, FIRST_DICE_POSITION_Y);
	m_secondDice.get().setPosition(SECOND_DICE_POSITION_X, SECOND_DICE_POSITION_Y);
}

void view::GameState::rollTheDice() {
	m_game.rollTheDice();
	m_firstDice.playSound();
	m_firstDice.changeTexture(m_game.getFirstRollResult());
	m_secondDice.changeTexture(m_game.getSecondRollResult());
}

