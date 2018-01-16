#pragma once
#include <memory>
#include <SFML\Graphics.hpp>
#include "../code/logic/include/Player.h"
#include "../include/GameView.h"

namespace view{	
	struct Data;

	class PropertyManager {
		std::unique_ptr<view::Data> m_data;
		logic::Player* m_player;
		void gameLoop();
		void initialise();
		void handleInput();
		void update(sf::Time); 
		void draw();

		sf::Sprite m_background;
		sf::Sprite m_fieldBackground;
		sf::Sprite m_playerLabel;
		
		MessageBox m_message;
		MessageBox m_playerInfo;
		MessageBox m_fieldInfo;

		Button m_mortgageButton;
		Button m_liftMortgageButton;
		Button m_buyHouseButton;
		Button m_sellHouseButton;
		Button m_buyHotelButton;
		Button m_sellHotelButton;
		Button m_nextButton;
		Button m_previousButton;
		Button m_backButton;

	public:
		PropertyManager(logic::Player&);
		~PropertyManager();

		void loadTextures();
		void createBackground();
		void createButtons();
		void createMessageBoxes();

		void showNextProperty();
		void showPreviousProperty();

		template <typename T>
		std::string toStringWithPrecision(const T a_value, const int n = 1) {
			std::stringstream stream;
			stream << std::fixed << std::setprecision(n) << a_value;
			std::string s = stream.str();
			return s;
		}
	};
}