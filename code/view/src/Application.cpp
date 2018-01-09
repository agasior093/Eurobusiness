#include "../include/Application.h"

view::Application::Application(int width, int height, std::string title) {
	m_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

	m_data->stateManager.addState(std::unique_ptr<State>(new MenuState(this->m_data)));

	this->run();
}

void view::Application::run() {	
	while (this->m_data->window.isOpen()) {
		this->m_data->stateManager.processStateChanges();
		this->m_data->stateManager.getActiveState()->handleUserInput();
		this->m_data->stateManager.getActiveState()->update(m_clock.restart());
		this->m_data->stateManager.getActiveState()->draw();
	}
}

