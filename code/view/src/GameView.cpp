#include "../include/GameView.h"

view::GameView::GameView(std::vector<std::string>& playerNames)
	: m_game(playerNames), m_numberOfPlayers(playerNames.size())
{	
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
	createDice();
	createButtons();
	createPlayers();
	createMessageBoxes();	
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
			endTurn();			
		}

		if (this->m_data->inputManager.isSpriteClicked(this->m_collectButton, evnt, this->m_data->window)) {
			m_game.collectCash();
			m_gameStatus.changeText("You recieved 400$.");			
		}

		if (this->m_data->inputManager.isSpriteClicked(this->m_jailCardButton, evnt, this->m_data->window)) {
			m_game.getActivePlayer().useOutOfJailCard();
		}

		if (this->m_data->inputManager.isSpriteClicked(this->m_jailRollButton, evnt, this->m_data->window)) {
			m_game.jailRoll();
			m_board.getField(30).roll();
			m_diceOne.changeTexture(m_game.getDiceOne().getCurrentNumber());
			m_diceTwo.changeTexture(m_game.getDiceTwo().getCurrentNumber());
		}

		//test keys		
		if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::C) {
			m_game.getActivePlayer().addOutOfJailCard();			
		}

		if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::T) {
			std::cout << m_game.getActivePlayer().getTurnsLeftInJail();
		}
	}
}

void view::GameView::update(sf::Time dt) { 
	updateButtons();
	updatePlayerLabels();
	updateCurrentField();		
	if (activePlayer().isMoving() == true) {
		calculateTokenPosition();
		activePlayer().move();				
	}
}

void view::GameView::draw() {
	this->m_data->window.clear();

	//drawing background
	this->m_data->window.draw(m_background);
	
	//drawing background objects
	this->m_data->window.draw(m_currentField);
	this->m_data->window.draw(m_fieldInfo.get());
	this->m_data->window.draw(m_gameStatus.get());

	//drawing players
	for (int i = 0; i < m_numberOfPlayers; ++i) {
		this->m_data->window.draw(m_players[i].getToken());
		this->m_data->window.draw(m_players[i].getLabel());
		this->m_data->window.draw(m_playerLabels[i].get());
		this->m_data->window.draw(m_playerTokenCopies[i]);
	}
	
	//drawing dice
	this->m_data->window.draw(m_diceOne.get());
	this->m_data->window.draw(m_diceTwo.get());

	//drawing buttons
	this->m_data->window.draw(m_endTurnButton.getSprite());
	this->m_data->window.draw(m_propertyManagerButton.getSprite());
	this->m_data->window.draw(m_rollButton.getSprite());

	this->m_data->window.draw(m_buyButton.getSprite());
	this->m_data->window.draw(m_payButton.getSprite());
	this->m_data->window.draw(m_jailRollButton.getSprite());
	this->m_data->window.draw(m_jailCardButton.getSprite());
	this->m_data->window.draw(m_revealButton.getSprite());
	this->m_data->window.draw(m_collectButton.getSprite());


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
	this->m_data->resourceManager.loadTexture("Reveal", REVEAL_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled reveal", DISABLED_REVEAL_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Collect", COLLECT_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled collect", DISABLED_COLLECT_BUTTON_FILE);

	//current field background	
	this->m_data->resourceManager.loadTexture("Field backgrounds", FIELD_BACKGROUNDS);

	//active player field
	this->m_data->resourceManager.loadTexture("Player label", PLAYER_LABEL);	
}

void view::GameView::createBackground() {
	this->m_background.setTexture(this->m_data->resourceManager.getTexture("Background"));

	this->m_currentField.setTexture(this->m_data->resourceManager.getTexture("Field backgrounds"));
	m_currentField.setTextureRect(sf::IntRect(0, 0, 200, 300));
	m_currentField.setPosition(260, 210);	
}

void view::GameView::createButtons() {
	m_buttons["Roll the dice"] = &m_rollButton;
	m_buttons["Property manager"] = &m_propertyManagerButton;
	m_buttons["End turn"] = &m_endTurnButton;
	m_buttons["Buy"] = &m_buyButton;
	m_buttons["Pay"] = &m_payButton;
	m_buttons["Jail roll"] = &m_jailRollButton;
	m_buttons["Jail card"] = &m_jailCardButton;
	m_buttons["Reveal"] = &m_revealButton;
	m_buttons["Collect"] = &m_collectButton;

	//roll dice button
	this->m_rollButton.setTextures(this->m_data->resourceManager.getTexture("Roll the dice"),
		this->m_data->resourceManager.getTexture("Disabled roll the dice"));	
	m_rollButton.getSprite().setPosition(120, 540);

	this->m_propertyManagerButton.setTextures(this->m_data->resourceManager.getTexture("Property manager"),
		this->m_data->resourceManager.getTexture("Disabled property manager"));	
	this->m_propertyManagerButton.enable();
	m_propertyManagerButton.getSprite().setPosition(300, 530);

	//end turn button
	this->m_endTurnButton.setTextures(this->m_data->resourceManager.getTexture("End turn"),
		this->m_data->resourceManager.getTexture("Disabled end turn"));	
	m_endTurnButton.getSprite().setPosition(485, 540);
	
	//buy button
	this->m_buyButton.setTextures(this->m_data->resourceManager.getTexture("Buy"),
		this->m_data->resourceManager.getTexture("Disabled buy"));
	this->m_buyButton.disable();
	m_buyButton.getSprite().setPosition(485, 215);

	//pay button
	this->m_payButton.setTextures(this->m_data->resourceManager.getTexture("Pay"),
		this->m_data->resourceManager.getTexture("Disabled pay"));	
	this->m_payButton.disable();
	m_payButton.getSprite().setPosition(485, 265);

	//jail roll button
	this->m_jailRollButton.setTextures(this->m_data->resourceManager.getTexture("Jail roll"),
		this->m_data->resourceManager.getTexture("Disabled jail roll"));
	this->m_jailRollButton.disable();
	m_jailRollButton.getSprite().setPosition(485, 315);

	//jail card button
	this->m_jailCardButton.setTextures(this->m_data->resourceManager.getTexture("Jail card"),
		this->m_data->resourceManager.getTexture("Disabled jail card"));
	this->m_jailCardButton.disable();
	m_jailCardButton.getSprite().setPosition(485, 365);

	//reveal button
	this->m_revealButton.setTextures(this->m_data->resourceManager.getTexture("Reveal"),
		this->m_data->resourceManager.getTexture("Disabled reveal"));
	this->m_revealButton.disable();
	m_revealButton.getSprite().setPosition(485, 415);

	//collect button
	this->m_collectButton.setTextures(this->m_data->resourceManager.getTexture("Collect"),
		this->m_data->resourceManager.getTexture("Disabled collect"));
	this->m_collectButton.disable();
	m_collectButton.getSprite().setPosition(485, 465);
}

void view::GameView::createDice() {
	m_diceOne.get().setPosition(FIRST_DICE_POSITION_X, FIRST_DICE_POSITION_Y);
	m_diceTwo.get().setPosition(SECOND_DICE_POSITION_X, SECOND_DICE_POSITION_Y);
}

void view::GameView::createPlayers() {
	m_players.reserve(m_numberOfPlayers); // probably need to refactor later into std::array or change way of initialisation
	m_playerLabels.reserve(m_numberOfPlayers);
	m_playerTokenCopies.reserve(m_numberOfPlayers);

	sf::Color color;
	float labelPositionX = PLAYER_LABEL_POSITION_X;
	float labelPositionY;
	float originX, originY;
	for (int i = 0; i < m_numberOfPlayers; ++i) {			
		if (i == 0) {
			color = sf::Color::Red;			
			labelPositionY = PLAYER_ONE_LABEL_POSITION_Y;
			originX = 0;
			originY = 0;
		}
		if (i == 1) {
			color = sf::Color::Blue;			
			labelPositionY = PLAYER_TWO_LABEL_POSITION_Y;
			originX = 20;
			originY = 0;
		}
		if (i == 2) {
			color = sf::Color::Green;			
			labelPositionY = PLAYER_THREE_LABEL_POSITION_Y;
			originX = 0;
			originY = 20;
		}
		if (i == 3) {
			color = sf::Color::Yellow;			
			labelPositionY = PLAYER_FOUR_LABEL_POSITION_Y;
			originX = 20;
			originY = 20;
		}
		
		m_players.emplace_back(view::Player(m_game.getPlayer(i)));
		m_players[i].create(color, labelPositionX, labelPositionY, originX, originY);			

		m_playerLabels.emplace_back(view::MessageBox());
		m_playerLabels[i].create(labelPositionX + 5, labelPositionY + 5, 15, sf::Color::Black, m_players[i].getPlayerInfo());

		m_playerTokenCopies.emplace_back(m_players[i].getTokenCopy());
		m_playerTokenCopies[i].setPosition(labelPositionX + 25, labelPositionY + 25);
		m_playerTokenCopies[i].setOrigin(20, 20);
	}	
}

void view::GameView::createMessageBoxes() {
	m_fieldInfo.create(275, 250, 12, sf::Color::Black, "");
	m_gameStatus.create(100, 100, 17, sf::Color::Black, "");
}

void view::GameView::calculateTokenPosition() {
	m_tokenPreviousPosition = m_board.getField(static_cast<std::size_t>(activePlayer().getPosition())).getPosition();
	m_tokenNextPosition = m_board.getField(static_cast<std::size_t>(activePlayer().getPosition() + 1) % 40).getPosition();
	activePlayer().getToken().setPosition(m_tokenPreviousPosition
		+ (m_tokenNextPosition - m_tokenPreviousPosition)
		* activePlayer().getStep() ); //+ activePlayer().getJumpOffSet()
}

void view::GameView::rollTheDice() {
	m_game.startTurn();
	m_diceOne.playSound();
	m_diceOne.changeTexture(m_game.getDiceOne().getCurrentNumber());
	m_diceTwo.changeTexture(m_game.getDiceTwo().getCurrentNumber());
	
	m_gameStatus.changeText(m_game.checkForDoubles());

	if (m_game.canMove()) {
		activePlayer().setTargetPosition();
	}	
}

void view::GameView::endTurn() {	
	if (m_game.getActivePlayer().isSentToJail()) {
		activePlayer().getToken().setPosition(45, 675);
		activePlayer().setPosition(10);
	}
	m_board.getField(m_game.getActivePlayer().getPosition()).reset();
	m_game.endTurn();	
}

void view::GameView::updateButtons() {	
	//roll 
	if (m_game.canThrow()) {
		m_rollButton.enable();
	}
	else {
		m_rollButton.disable();
	}	

	//end turn
	if (m_game.canEndTurn() && !activePlayer().isMoving()) {
		m_endTurnButton.enable();
	} 
	else {
		m_endTurnButton.disable();
	}

	//collect
	if (m_game.passedStart() != "") {
		m_gameStatus.changeText(m_game.passedStart());
		m_collectButton.enable();
	}
	else {
		m_collectButton.disable();
	}	
}

void view::GameView::updatePlayerLabels() {
	for (size_t i = 0; i < m_players.size(); ++i) {
		m_players[i].updateLabel();
		m_playerLabels[i].changeText(m_players[i].getPlayerInfo());
	}
}

void view::GameView::updateCurrentField() {	
	m_currentField.setTextureRect(sf::IntRect(m_board.getField(activePlayer().getPosition()).getTexturePosition(), 0, 200, 300));
	m_fieldInfo.changeText(m_game.getBoard().getField(static_cast<int>(activePlayer().getPosition())).getMessage());	
	m_board.getField(static_cast<int>(activePlayer().getPosition())).activate(m_buttons, m_game.getActivePlayer());
}

view::Player& view::GameView::activePlayer() {
	m_activePlayer = m_game.getActivePlayerID();
	return m_players[m_activePlayer];
}

view::Button* view::GameView::getButton(std::string buttonName) {
	return m_buttons.at(buttonName);
}