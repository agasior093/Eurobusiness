#include "../include/PropertyManagerView.h"
#include <iostream>

view::PropertyManager::PropertyManager(logic::Player& player) 
{
	m_data = std::make_unique<Data>();
	m_player = &player;
	m_data->window.create(sf::VideoMode(PROPERTY_MANAGER_SCREEN_WIDTH, PROPERTY_MANAGER_SCREEN_HEIGHT), PROPERTY_MANAGER_TITLE, sf::Style::Close | sf::Style::Titlebar);
	gameLoop();
	
}

view::PropertyManager::~PropertyManager() {	
	m_player = nullptr;
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
	}
}
void view::PropertyManager::update(sf::Time) {

}
void view::PropertyManager::draw() {
	this->m_data->window.clear();

	this->m_data->window.draw(m_background);

	this->m_data->window.draw(m_playerLabel);
	this->m_data->window.draw(m_fieldBackground);

	this->m_data->window.draw(m_playerInfo.get());
	this->m_data->window.draw(m_message.get());
	this->m_data->window.draw(m_fieldInfo.get());

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
}

void view::PropertyManager::createBackground() {
	this->m_background.setTexture(this->m_data->resourceManager.getTexture("Background"));
	this->m_playerLabel.setTexture(this->m_data->resourceManager.getTexture("Player label"));
	this->m_fieldBackground.setTexture(this->m_data->resourceManager.getTexture("Field background"));

	m_playerLabel.setPosition(255, 50);
	m_fieldBackground.setPosition(215, 120);

	if (m_player->getProperties().size() > 0) {
		m_fieldBackground.setTextureRect(sf::IntRect(0, 0, 220, 300));
	}
	else {
		m_fieldBackground.setTextureRect(sf::IntRect(220, 0, 220, 300));
	}
	
}

void view::PropertyManager::createButtons() {
	this->m_mortgageButton.setTextures(this->m_data->resourceManager.getTexture("Mortgage property"),
		this->m_data->resourceManager.getTexture("Mortgage property"));
	m_mortgageButton.getSprite().setPosition(35, 50);
	this->m_mortgageButton.enable();

	this->m_liftMortgageButton.setTextures(this->m_data->resourceManager.getTexture("Lift mortgage"),
		this->m_data->resourceManager.getTexture("Lift mortgage"));
	m_liftMortgageButton.getSprite().setPosition(35, 120);
	this->m_liftMortgageButton.enable();

	this->m_buyHouseButton.setTextures(this->m_data->resourceManager.getTexture("Buy house"),
		this->m_data->resourceManager.getTexture("Buy house"));
	m_buyHouseButton.getSprite().setPosition(35, 190);
	this->m_buyHouseButton.enable();

	this->m_sellHouseButton.setTextures(this->m_data->resourceManager.getTexture("Sell house"),
		this->m_data->resourceManager.getTexture("Sell house"));
	m_sellHouseButton.getSprite().setPosition(35, 240);
	this->m_sellHouseButton.enable();

	this->m_buyHotelButton.setTextures(this->m_data->resourceManager.getTexture("Buy hotel"),
		this->m_data->resourceManager.getTexture("Buy hotel"));
	m_buyHotelButton.getSprite().setPosition(35, 290);
	this->m_buyHotelButton.enable();

	this->m_sellHotelButton.setTextures(this->m_data->resourceManager.getTexture("Sell hotel"),
		this->m_data->resourceManager.getTexture("Sell hotel"));
	m_sellHotelButton.getSprite().setPosition(35, 340);
	this->m_sellHotelButton.enable();

	this->m_backButton.setTextures(this->m_data->resourceManager.getTexture("Back"),
		this->m_data->resourceManager.getTexture("Back"));
	m_backButton.getSprite().setPosition(35, 430);
	this->m_backButton.enable();

	this->m_previousButton.setTextures(this->m_data->resourceManager.getTexture("Previous"),
		this->m_data->resourceManager.getTexture("Previous"));
	m_previousButton.getSprite().setPosition(220, 430);
	this->m_previousButton.enable();

	this->m_nextButton.setTextures(this->m_data->resourceManager.getTexture("Next"),
		this->m_data->resourceManager.getTexture("Next"));
	m_nextButton.getSprite().setPosition(330, 430);
	this->m_nextButton.enable();
}

void view::PropertyManager::createMessageBoxes() {
	std::string playerInfo = m_player->getName() + "\nCash: " + toStringWithPrecision(m_player->getCash()) + "$";
	m_playerInfo.create(265, 55, 17, sf::Color::Black, playerInfo);
	m_message.create(20, 15, 15, sf::Color::Black, "Manage your properties.");	
	if (m_player->getProperties().size() == 0) {
		m_fieldInfo.create(225, 125, 15, sf::Color::Black, "");
	}
	else {
		m_fieldInfo.create(225, 125, 15, sf::Color::Black, m_player->getProperties()[0]->getPropertyInfo());
	}
	

}

void view::PropertyManager::showNextProperty() {

}

void view::PropertyManager::showPreviousProperty() {

}