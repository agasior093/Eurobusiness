#include "../include/GameState.h"

view::GameState::GameState(std::shared_ptr<ApplicationData> data)
	: m_data(data), m_game(2, m_playerNames.getNames()) { }

void view::GameState::initialise() {
	loadResources();
	createBackground();
	createButtons();	

	m_playerOneToken.create(m_game.getActivePlayer());	
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

		if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::R) {
			m_game.reset();
		}		
	}
}

void view::GameState::update(sf::Time dt) {	
	updateButtons();
	calculateTokenPosition();
	if (m_playerOneToken.isMoving() == true) {
		m_playerOneToken.move();
	}
}

void view::GameState::draw() {
	this->m_data->window.clear();

	//drawing background
	this->m_data->window.draw(m_background);

	//drawing player token
	this->m_data->window.draw(m_playerOneToken.get());

	//drawing current field
	this->m_data->window.draw(m_currentField);

	//drawing dice
	this->m_data->window.draw(m_diceOne.get());
	this->m_data->window.draw(m_diceTwo.get());

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

	//current field background
	this->m_data->resourceManager.loadTexture("Default field", DEFAULT_FIELD_BACKGROUND);
}

void view::GameState::createBackground() {
	this->m_background.setTexture(this->m_data->resourceManager.getTexture("Background"));

	this->m_currentField.setTexture(this->m_data->resourceManager.getTexture("Default field"));
	m_currentField.setPosition(230, 180);

	createDice();
}

void view::GameState::createButtons() {
	//roll dice button
	this->m_rollButton.setTextures(this->m_data->resourceManager.getTexture("Roll the dice"),
		this->m_data->resourceManager.getTexture("Disabled roll the dice"));
	this->m_rollButton.enable();
	m_rollButton.getSprite().setPosition(85, 100);

	//end turn button
	this->m_endTurnButton.setTextures(this->m_data->resourceManager.getTexture("End turn"),
		this->m_data->resourceManager.getTexture("Disabled end turn"));
	this->m_endTurnButton.enable();
	m_endTurnButton.getSprite().setPosition(300, 390);

	//pay button
	this->m_payButton.setTextures(this->m_data->resourceManager.getTexture("Pay button"),
		this->m_data->resourceManager.getTexture("Disabled pay button"));
	this->m_payButton.enable();
	m_payButton.getSprite().setPosition(300, 320);
}

void view::GameState::createDice() {
	m_diceOne.get().setPosition(FIRST_DICE_POSITION_X, FIRST_DICE_POSITION_Y);
	m_diceTwo.get().setPosition(SECOND_DICE_POSITION_X, SECOND_DICE_POSITION_Y);
}

void view::GameState::calculateTokenPosition() {
	m_tokenPreviousPosition = m_board.get()[static_cast<std::size_t>(m_playerOneToken.getPosition())];
	m_tokenNextPosition = m_board.get()[static_cast<std::size_t>(m_playerOneToken.getPosition() + 1) % 40];
	m_playerOneToken.get().setPosition(m_tokenPreviousPosition 
	+ (m_tokenNextPosition - m_tokenPreviousPosition) 
	* m_playerOneToken.getStep() + m_playerOneToken.getJumpOffSet());
}

void view::GameState::rollTheDice() {
	m_game.startTurn();
	m_diceOne.playSound();
	m_diceOne.changeTexture(m_game.getDiceOne().getCurrentNumber());
	m_diceTwo.changeTexture(m_game.getDiceTwo().getCurrentNumber());
	if (m_game.canMove()) {
		std::cout << "From gameState: " << m_game.getActivePlayer().getPosition() << "\n";
		std::cout << "From gameState: " << m_game.getActivePlayer().getName() << "\n";
		std::cout << "From gameState: " << &m_game.getActivePlayer() << "\n";
		m_playerOneToken.setNewPosition(m_game.getTotalRollResult());
	}
	
}

void view::GameState::updateButtons() {
	if (m_game.canThrow()) {
		m_rollButton.enable();
	}
	else {
		m_rollButton.disable();
	}
}

void view::GameState::createPlayers() {

}