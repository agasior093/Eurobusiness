#pragma once

#include <memory>
#include <string>
#include <SFML\Graphics.hpp>

#include "StateManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "MenuState.h"

namespace view {
	struct ApplicationData {
		StateManager stateManager;
		ResourceManager resourceManager;
		InputManager inputManager;
		sf::RenderWindow window;
	};

	class Application {
	private:
		sf::Clock m_clock;
		std::shared_ptr<ApplicationData> m_data = std::make_shared<ApplicationData>();
		void run();
	public:
		Application(int width, int height, std::string title);
	};
}

