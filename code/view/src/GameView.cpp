#include "../include/GameView.h"



view::GameView::GameView(std::vector<std::string>& playerNames)
	: m_game(playerNames), m_numberOfPlayers(playerNames.size())
{
	m_players.reserve(4); // probably need to refactor later into std::array or change way of initialisation
	m_data = std::make_unique<Data>();
	m_data->window.create(sf::VideoMode(APPLICATION_SCREEN_WIDTH, APPLICATION_SCREEN_HEIGHT), APPLICATION_TITLE, sf::Style::Close | sf::Style::Titlebar);
	gameLoop();
}

void view::GameView::gameLoop() {
	initialise(); 
	while (m_data->window.isOpen()) {
		handleInput();
		update(m_data->clock.restart());
		draw();
	}
}

void view::GameView::initialise() {
	loadResources();
	createBackground();
	createButtons();
	createPlayers();
}

void view::GameView::handleInput() {
	sf::Event evnt;
	while (m_data->window.pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed) {
			m_data->window.close();
		}	

		if (this->m_data->inputManager.isSpriteClicked(this->m_rollButton, evnt, this->m_data->window)) {
			rollTheDice();
		}

		if (this->m_data->inputManager.isSpriteClicked(this->m_endTurnButton, evnt, this->m_data->window)) {
			m_game.endTurn();
		}
	}
}

void view::GameView::update(sf::Time dt) {
	updateButtons();
	calculateTokenPosition();
	if (activePlayer().isMoving() == true) {
		activePlayer().move();
	}
}

void view::GameView::draw() {
	this->m_data->window.clear();

	//drawing background
	this->m_data->window.draw(m_background);
	
	//drawing current field
	this->m_data->window.draw(m_currentField);

	//drawing players
	for (int i = 0; i < m_numberOfPlayers; ++i) {
		this->m_data->window.draw(m_players[i].getToken());
		this->m_data->window.draw(m_players[i].getLabel());
	}
	
	//drawing dice
	this->m_data->window.draw(m_diceOne.get());
	this->m_data->window.draw(m_diceTwo.get());

	//drawing buttons
	this->m_data->window.draw(m_endTurnButton.getSprite());
	this->m_data->window.draw(m_propertyManagerButton.getSprite());
	this->m_data->window.draw(m_rollButton.getSprite());

	this->m_data->window.draw(m_payButton.getSprite());

	this->m_data->window.display();
}

void view::GameView::loadResources() {
	//background texture
	this->m_data->resourceManager.loadTexture("Background", MENU_STATE_BACKGROUND_FILE);

	//button textures
	this->m_data->resourceManager.loadTexture("Roll the dice", ROLL_THE_DICE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled roll the dice", DISABLED_ROLL_THE_DICE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("End turn", END_TURN_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled end turn", DISABLED_END_TURN_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Pay", PAY_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled pay", DISABLED_PAY_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Property manager", PROPERTY_MANAGER_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled property manager", DISABLED_PROPERTY_MANAGER_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Buy", BUY_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled buy", DISABLED_BUY_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Jail card", JAIL_CARD_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled jail card", DISABLED_JAIL_CARD_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Jail roll", ROLL_THE_DICE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled jail roll", DISABLED_ROLL_THE_DICE_BUTTON_FILE);

	//current field background
	this->m_data->resourceManager.loadTexture("Default field", DEFAULT_FIELD_BACKGROUND);

	//active player field
	this->m_data->resourceManager.loadTexture("Player label", PLAYER_LABEL);
	this->m_data->resourceManager.loadTexture("Active player", ACTIVE_PLAYER);
	this->m_data->resourceManager.loadTexture("Disactive player", NOT_ACTIVE_PLAYER);
}

void view::GameView::createBackground() {
	this->m_background.setTexture(this->m_data->resourceManager.getTexture("Background"));

	this->m_currentField.setTexture(this->m_data->resourceManager.getTexture("Default field"));
	m_currentField.setPosition(260, 210);

	createDice();
}

void view::GameView::createButtons() {
	//roll dice button
	this->m_rollButton.setTextures(this->m_data->resourceManager.getTexture("Roll the dice"),
		this->m_data->resourceManager.getTexture("Disabled roll the dice"));
	this->m_rollButton.enable();
	m_rollButton.getSprite().setPosition(120, 130);

	this->m_propertyManagerButton.setTextures(this->m_data->resourceManager.getTexture("Property manager"),
		this->m_data->resourceManager.getTexture("Disabled property manager"));
	this->m_propertyManagerButton.enable();
	m_propertyManagerButton.getSprite().setPosition(300, 530);

	//end turn button
	this->m_endTurnButton.setTextures(this->m_data->resourceManager.getTexture("End turn"),
		this->m_data->resourceManager.getTexture("Disabled end turn"));
	this->m_endTurnButton.enable();
	m_endTurnButton.getSprite().setPosition(120, 540);

	//pay button
	this->m_payButton.setTextures(this->m_data->resourceManager.getTexture("Pay"),
		this->m_data->resourceManager.getTexture("Disabled pay"));
	this->m_payButton.enable();
	m_payButton.getSprite().setPosition(485, 210);
}

void view::GameView::createDice() {
	m_diceOne.get().setPosition(FIRST_DICE_POSITION_X, FIRST_DICE_POSITION_Y);
	m_diceTwo.get().setPosition(SECOND_DICE_POSITION_X, SECOND_DICE_POSITION_Y);
}

void view::GameView::createPlayers() {
	sf::Color color;
	int labelPositionX = PLAYER_LABEL_POSITION_X;
	int labelPositionY;
	for (int i = 0; i < m_numberOfPlayers; ++i) {			
		if (i == 0) {
			color = sf::Color::Red;			
			labelPositionY = PLAYER_ONE_LABEL_POSITION_Y;
		}
		if (i == 1) {
			color = sf::Color::Blue;			
			labelPositionY = PLAYER_TWO_LABEL_POSITION_Y;
		}
		if (i == 2) {
			color = sf::Color::Green;			
			labelPositionY = PLAYER_THREE_LABEL_POSITION_Y;
		}
		if (i == 3) {
			color = sf::Color::Yellow;			
			labelPositionY = PLAYER_FOUR_LABEL_POSITION_Y;
		}
		
		m_players.push_back(view::Player(m_game.getPlayer(i)));
		m_players[i].create(color, labelPositionX, labelPositionY);			
	}	
}

view::Player& view::GameView::activePlayer() {
	m_activePlayer = m_game.getActivePlayerID();
	return m_players[m_activePlayer];
}

void view::GameView::calculateTokenPosition() {
	m_tokenPreviousPosition = m_board.get()[static_cast<std::size_t>(activePlayer().getPosition())];
	m_tokenNextPosition = m_board.get()[static_cast<std::size_t>(activePlayer().getPosition() + 1) % 40];
	activePlayer().getToken().setPosition(m_tokenPreviousPosition
		+ (m_tokenNextPosition - m_tokenPreviousPosition)
		* activePlayer().getStep() + activePlayer().getJumpOffSet());
}

void view::GameView::rollTheDice() {
	m_game.startTurn();
	m_diceOne.playSound();
	m_diceOne.changeTexture(m_game.getDiceOne().getCurrentNumber());
	m_diceTwo.changeTexture(m_game.getDiceTwo().getCurrentNumber());

	if (m_game.canMove()) {
		activePlayer().setTargetPosition();
	}
}

void view::GameView::updateButtons() {	
	if (m_game.canThrow()) {
		m_rollButton.enable();
	}
	else {
		m_rollButton.disable();
	}	

	if (m_game.canEndTurn() && !activePlayer().isMoving()) {
		m_endTurnButton.enable();
	} 
	else {
		m_endTurnButton.disable();
	}
}