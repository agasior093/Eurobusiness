#include "../include/PropertyManagerView.h"

view::PropertyManager::PropertyManager(logic::Player* player, logic::PropertyManager& propertyManager) 
{
	m_data = std::make_unique<Data>();
	m_propertyManager = &propertyManager;
	m_propertyManager->setActivePlayer(player);
	m_data->window.create(sf::VideoMode(PROPERTY_MANAGER_SCREEN_WIDTH, PROPERTY_MANAGER_SCREEN_HEIGHT), PROPERTY_MANAGER_TITLE, sf::Style::Close | sf::Style::Titlebar);
	gameLoop();	
}

void view::PropertyManager::gameLoop() {
	initialise();
	while (m_data->window.isOpen()) {
		handleInput();
		update(m_data->clock.restart());
		draw();
	}
}

void view::PropertyManager::initialise() {
	loadTextures();
	createBackground();
	createButtons();
	createMessageBoxes();
}

void view::PropertyManager::handleInput(){
	sf::Event evnt;
	while (m_data->window.pollEvent(evnt)) {
		if ((evnt.type == sf::Event::Closed) || 
			(this->m_data->inputManager.isSpriteClicked(this->m_backButton, evnt, this->m_data->window))) {
			m_data->window.close();			
		}
		if (this->m_data->inputManager.isSpriteClicked(this->m_nextButton, evnt, this->m_data->window)) {
			showNextProperty();
		}
		if (this->m_data->inputManager.isSpriteClicked(this->m_previousButton, evnt, this->m_data->window)) {
			showPreviousProperty();
		}
		if (this->m_data->inputManager.isSpriteClicked(this->m_buyHouseButton, evnt, this->m_data->window)) {
			buyHouse();
		}

		if (this->m_data->inputManager.isSpriteClicked(this->m_sellHouseButton, evnt, this->m_data->window)) {
			sellHouse();
		}

		if (this->m_data->inputManager.isSpriteClicked(this->m_buyHotelButton, evnt, this->m_data->window)) {
			buyHotel();
		}

		if (this->m_data->inputManager.isSpriteClicked(this->m_sellHotelButton, evnt, this->m_data->window)) {
			sellHotel();
		}

		if (this->m_data->inputManager.isSpriteClicked(this->m_mortgageButton, evnt, this->m_data->window)) {
			mortgageProperty();
		}

		if (this->m_data->inputManager.isSpriteClicked(this->m_liftMortgageButton, evnt, this->m_data->window)) {
			liftMortgage();
		}
	}
}

void view::PropertyManager::update(sf::Time) {
	updateButtons();
	updateMessageBoxes();
}

void view::PropertyManager::draw() {
	this->m_data->window.clear();

	this->m_data->window.draw(m_background);

	this->m_data->window.draw(m_playerLabel);
	this->m_data->window.draw(m_fieldBackground);

	this->m_data->window.draw(m_playerInfo.get());
	this->m_data->window.draw(m_message.get());
	this->m_data->window.draw(m_fieldInfo.get());
	this->m_data->window.draw(m_propertyCounter.get());

	this->m_data->window.draw(m_mortgageButton.getSprite());
	this->m_data->window.draw(m_liftMortgageButton.getSprite());
	this->m_data->window.draw(m_buyHouseButton.getSprite());
	this->m_data->window.draw(m_sellHouseButton.getSprite());
	this->m_data->window.draw(m_buyHotelButton.getSprite());
	this->m_data->window.draw(m_sellHotelButton.getSprite());
	this->m_data->window.draw(m_backButton.getSprite());
	this->m_data->window.draw(m_previousButton.getSprite());
	this->m_data->window.draw(m_nextButton.getSprite());

	this->m_data->window.display();
}

void view::PropertyManager::loadTextures() {
	this->m_data->resourceManager.loadTexture("Background", PROPERTY_MANAGER_BACKGROUND_FILE);
	this->m_data->resourceManager.loadTexture("Field background", PROPERTY_MANAGER_FIELD_BACKGROUND_FILE);
	this->m_data->resourceManager.loadTexture("Player label", PROPERTY_MANAGER_PLAYER_LABEL_FILE);

	this->m_data->resourceManager.loadTexture("Mortgage property", MORTGAGE_PROPERTY_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Lift mortgage", LIFT_MORTGAGE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Buy house", BUY_HOUSE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Sell house", SELL_HOUSE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Buy hotel", BUY_HOTEL_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Sell hotel", SELL_HOTEL_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Next", NEXT_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Previous", PREVIOUS_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Back", BACK_BUTTON_FILE);

	this->m_data->resourceManager.loadTexture("Disabled mortgage property", DISABLED_MORTGAGE_PROPERTY_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled lift mortgage", DISABLED_LIFT_MORTGAGE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled buy house", DISABLED_BUY_HOUSE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled sell house", DISABLED_SELL_HOUSE_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled buy hotel", DISABLED_BUY_HOTEL_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled sell hotel", DISABLED_SELL_HOTEL_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled next", DISABLED_NEXT_BUTTON_FILE);
	this->m_data->resourceManager.loadTexture("Disabled previous", DISABLED_PREVIOUS_BUTTON_FILE);	
}

void view::PropertyManager::createBackground() {
	this->m_background.setTexture(this->m_data->resourceManager.getTexture("Background"));
	this->m_playerLabel.setTexture(this->m_data->resourceManager.getTexture("Player label"));
	this->m_fieldBackground.setTexture(this->m_data->resourceManager.getTexture("Field background"));

	m_playerLabel.setPosition(255, 50);
	m_fieldBackground.setPosition(215, 120);

	if (m_propertyManager->getActivePlayer().getProperties().size() > 0) {
		m_fieldBackground.setTextureRect(sf::IntRect(0, 0, 220, 300));
	}
	else {
		m_fieldBackground.setTextureRect(sf::IntRect(220, 0, 220, 300));
	}
	
}

void view::PropertyManager::createButtons() {
	this->m_mortgageButton.setTextures(this->m_data->resourceManager.getTexture("Mortgage property"),
		this->m_data->resourceManager.getTexture("Disabled mortgage property"));
	m_mortgageButton.getSprite().setPosition(35, 50);
	this->m_mortgageButton.disable();

	this->m_liftMortgageButton.setTextures(this->m_data->resourceManager.getTexture("Lift mortgage"),
		this->m_data->resourceManager.getTexture("Disabled lift mortgage"));
	m_liftMortgageButton.getSprite().setPosition(35, 120);
	this->m_liftMortgageButton.disable();

	this->m_buyHouseButton.setTextures(this->m_data->resourceManager.getTexture("Buy house"),
		this->m_data->resourceManager.getTexture("Disabled buy house"));
	m_buyHouseButton.getSprite().setPosition(35, 190);
	this->m_buyHouseButton.disable();

	this->m_sellHouseButton.setTextures(this->m_data->resourceManager.getTexture("Sell house"),
		this->m_data->resourceManager.getTexture("Disabled sell house"));
	m_sellHouseButton.getSprite().setPosition(35, 240);
	this->m_sellHouseButton.disable();

	this->m_buyHotelButton.setTextures(this->m_data->resourceManager.getTexture("Buy hotel"),
		this->m_data->resourceManager.getTexture("Disabled buy hotel"));
	m_buyHotelButton.getSprite().setPosition(35, 290);
	this->m_buyHotelButton.disable();

	this->m_sellHotelButton.setTextures(this->m_data->resourceManager.getTexture("Sell hotel"),
		this->m_data->resourceManager.getTexture("Disabled sell hotel"));
	m_sellHotelButton.getSprite().setPosition(35, 340);
	this->m_sellHotelButton.disable();

	this->m_backButton.setTextures(this->m_data->resourceManager.getTexture("Back"),
		this->m_data->resourceManager.getTexture("Back"));
	m_backButton.getSprite().setPosition(35, 430);
	this->m_backButton.enable();

	this->m_previousButton.setTextures(this->m_data->resourceManager.getTexture("Previous"),
		this->m_data->resourceManager.getTexture("Disabled previous"));
	m_previousButton.getSprite().setPosition(220, 430);
	this->m_previousButton.enable();

	this->m_nextButton.setTextures(this->m_data->resourceManager.getTexture("Next"),
		this->m_data->resourceManager.getTexture("Disabled next"));
	m_nextButton.getSprite().setPosition(330, 430);
	this->m_nextButton.enable();
}

void view::PropertyManager::createMessageBoxes() {	
	m_playerInfo.create(265, 55, 17, sf::Color::Black, m_propertyManager->getActivePlayer().getName() + "\nCash: " + toStringWithPrecision(m_propertyManager->getActivePlayer().getCash()) + "$");
	m_message.create(20, 10, 15, sf::Color::Black, "Manage your properties. You can buy only 4 buildings per round. ");	
	if (m_propertyManager->getActivePlayer().getProperties().size() == 0) {
		m_fieldInfo.create(225, 125, 15, sf::Color::Black, "");
	}
	else {
		m_fieldInfo.create(225, 125, 15, sf::Color::Black, m_propertyManager->getActivePlayer().getProperties()[0]->getPropertyInfo());
	}

	m_propertyCounter.create(390, 125, 15, sf::Color::Black, "[0/0]");
}

void view::PropertyManager::updateButtons() {
	if (m_propertyManager->getActivePlayer().getProperties().size() <= 1) {
		m_nextButton.disable();
		m_previousButton.disable();
	}
	else {
		m_nextButton.enable();
		m_previousButton.enable();
	}

	if (m_propertyManager->shouldEnableMortgage()) {
		m_mortgageButton.enable();
	}
	else {
		m_mortgageButton.disable();
	}

	if (m_propertyManager->shouldEnableLiftMortgage()) {
		m_liftMortgageButton.enable();
	}
	else {
		m_liftMortgageButton.disable();
	}

	if (m_propertyManager->shouldEnableBuyHouse()) {
		m_buyHouseButton.enable();
	}
	else {
		m_buyHouseButton.disable();
	}

	if (m_propertyManager->shouldEnableSellHouse()) {
		m_sellHouseButton.enable();
	}
	else {
		m_sellHouseButton.disable();
	}

	if (m_propertyManager->shouldEnableBuyHotel()) {
		m_buyHotelButton.enable();
	}
	else {
		m_buyHotelButton.disable();
	}

	if (m_propertyManager->shouldEnableSellHotel()) {
		m_sellHotelButton.enable();
	}
	else {
		m_sellHotelButton.disable();
	}
}

void view::PropertyManager::updateMessageBoxes() {
	m_propertyCounter.changeText("[" + std::to_string(m_propertyManager->getActivePropertyID() + 1) +
		"/" + std::to_string(m_propertyManager->getActivePlayer().getProperties().size()) + "]");
}

void view::PropertyManager::showNextProperty() {
	m_propertyManager->goToNextProperty();
	m_fieldInfo.changeText(m_propertyManager->getActiveProperty()->getPropertyInfo());
}

void view::PropertyManager::showPreviousProperty() {
	m_propertyManager->goToPreviousProperty();
	m_fieldInfo.changeText(m_propertyManager->getActiveProperty()->getPropertyInfo());
}

void view::PropertyManager::mortgageProperty() {
	m_propertyManager->mortgageProperty();
	m_fieldInfo.changeText(m_propertyManager->getActivePlayer().getProperties()[m_propertyManager->getActivePropertyID()]->getPropertyInfo());
	m_playerInfo.changeText(m_propertyManager->getActivePlayer().getName() + "\nCash: " + toStringWithPrecision(m_propertyManager->getActivePlayer().getCash()) + "$");
	m_message.changeText("You set " + m_propertyManager->getActiveProperty()->getName() + " under mortgage and gained "
		+ toStringWithPrecision(m_propertyManager->getActiveProperty()->getPrice() / 2) + "$");
}

void view::PropertyManager::liftMortgage() {
	m_propertyManager->liftMortgage();
	m_fieldInfo.changeText(m_propertyManager->getActivePlayer().getProperties()[m_propertyManager->getActivePropertyID()]->getPropertyInfo());
	m_playerInfo.changeText(m_propertyManager->getActivePlayer().getName() + "\nCash: " + toStringWithPrecision(m_propertyManager->getActivePlayer().getCash()) + "$");
	m_message.changeText("You lifted mortgage from " + m_propertyManager->getActiveProperty()->getName() + " and payed "
		+ toStringWithPrecision((m_propertyManager->getActiveProperty()->getPrice() / 2) + (m_propertyManager->getActiveProperty()->getPrice() * 0.1)) + "$");
}

void view::PropertyManager::buyHouse() {
	m_propertyManager->buyHouse();
	m_fieldInfo.changeText(m_propertyManager->getActivePlayer().getProperties()[m_propertyManager->getActivePropertyID()]->getPropertyInfo());
	m_playerInfo.changeText(m_propertyManager->getActivePlayer().getName() + "\nCash: " + toStringWithPrecision(m_propertyManager->getActivePlayer().getCash()) + "$");
	if (m_propertyManager->getActivePlayer().getTransactionCounter() != 4) {
		m_message.changeText("You bought house for " + toStringWithPrecision(m_propertyManager->getActiveProperty()->getHousePrice()) + "$.\n" +
			"You can buy " + std::to_string(4 - m_propertyManager->getActivePlayer().getTransactionCounter()) + " more buildings in this turn.");
	}
	else {
		m_message.changeText("You bought house for " + toStringWithPrecision(m_propertyManager->getActiveProperty()->getHousePrice()) + "$.\n" +
			"You can't build anything else in this turn.");
	}
}

void view::PropertyManager::sellHouse() {
	m_propertyManager->sellHouse();
	m_fieldInfo.changeText(m_propertyManager->getActivePlayer().getProperties()[m_propertyManager->getActivePropertyID()]->getPropertyInfo());
	m_playerInfo.changeText(m_propertyManager->getActivePlayer().getName() + "\nCash: " + toStringWithPrecision(m_propertyManager->getActivePlayer().getCash()) + "$");
	m_message.changeText("You sold house for " + toStringWithPrecision(m_propertyManager->getActiveProperty()->getHousePrice()) + "$.");
}

void view::PropertyManager::buyHotel() {
	m_propertyManager->buyHotel();
	m_fieldInfo.changeText(m_propertyManager->getActivePlayer().getProperties()[m_propertyManager->getActivePropertyID()]->getPropertyInfo());
	m_playerInfo.changeText(m_propertyManager->getActivePlayer().getName() + "\nCash: " + toStringWithPrecision(m_propertyManager->getActivePlayer().getCash()) + "$");
	if (m_propertyManager->getActivePlayer().getTransactionCounter() != 4) {
		m_message.changeText("You bought hotel for " + toStringWithPrecision(m_propertyManager->getActiveProperty()->getHotelPrice()) + "$.\n" +
			"You can buy " + std::to_string(4 - m_propertyManager->getActivePlayer().getTransactionCounter()) + " more buildings in this turn.");
	}
	else {
		m_message.changeText("You bought house for " + toStringWithPrecision(m_propertyManager->getActiveProperty()->getHousePrice()) + "$.\n" +
			"You can't build anything else in this turn.");
	}
}

void view::PropertyManager::sellHotel() {
	m_propertyManager->sellHotel();
	m_fieldInfo.changeText(m_propertyManager->getActivePlayer().getProperties()[m_propertyManager->getActivePropertyID()]->getPropertyInfo());
	m_playerInfo.changeText(m_propertyManager->getActivePlayer().getName() + "\nCash: " + toStringWithPrecision(m_propertyManager->getActivePlayer().getCash()) + "$");
	m_message.changeText("You bought hotel for " + toStringWithPrecision(m_propertyManager->getActiveProperty()->getHotelPrice()) + "$.");
}