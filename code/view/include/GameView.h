#pragma once

#include <iostream>

#include "DEFINITIONS.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>

#include "ResourceManager.h"
#include "InputManager.h"
#include "Button.h"
#include "../code/logic/include/Game.h"
#include "../include/DiceView.h"
#include "../include/PlayerView.h"
#include "../include/GameBoardView.h"

namespace view {
	struct Data {
		ResourceManager resourceManager;
		InputManager inputManager;
		sf::RenderWindow window;
		sf::Clock clock;
	};	

		
	class GameView {		
		std::unique_ptr<Data> m_data;
		void gameLoop();
		void initialise();
		void handleInput();
		void update(sf::Time dt);
		void draw();

		//game components
		int m_numberOfPlayers;
		logic::Game m_game;
		view::Dice m_diceOne, m_diceTwo;
		view::GameBoard m_board;
		
		std::vector<view::Player> m_players;
		unsigned m_activePlayer = 0;

		sf::Vector2f m_tokenPreviousPosition;
		sf::Vector2f m_tokenNextPosition;

		//application components
		sf::Sprite m_background;
		sf::Sprite m_currentField;

		//left menu buttons
		Button m_rollButton;	
		Button m_propertyManagerButton;
		Button m_endTurnButton;
		//right menu buttons
		Button m_payButton;
		Button m_buyButton;
		Button m_jailCardButton;
		Button m_jailRollButton;



	public:
		GameView(std::vector<std::string>&);
		~GameView() = default;				
		
		//on init
		void loadResources();
		void createBackground();
		void createButtons();
		void createDice();
		void createPlayers();

		//on update
		void calculateTokenPosition();
		void updateButtons();

		//on event 
		void rollTheDice();
		
		view::Player& activePlayer();
	};
}