#pragma once

#include "State.h"
#include "DEFINITIONS.h"
#include <memory>
#include "Application.h"

namespace view {
	struct ApplicationData;

	class MenuState : public State {
		std::shared_ptr<ApplicationData> m_data;
		sf::Clock m_clock;
		sf::Sprite m_background;
		Button m_newGameButton;
	
	public:
		MenuState(std::shared_ptr<ApplicationData> data);
	
		void initialise() override;
		void handleUserInput() override;
		void update(sf::Time) override;
		void draw() override;

		void loadTextures();
		void createButtons();
	};
}