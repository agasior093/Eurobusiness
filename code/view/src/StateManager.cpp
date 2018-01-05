#include "../include/StateManager.h"

void view::StateManager::addState(std::unique_ptr<State> newState, bool isReplacing) {
	this->m_isAdding = true;
	this->m_isReplacing = isReplacing;

	this->m_newState = std::move(newState);
}

void view::StateManager::removeState() {
	this->m_isRemoving = true;
}

void view::StateManager::processStateChanges() {
	if (this->m_isRemoving && !this->m_states.empty()) {
		this->m_states.pop();
		this->m_isRemoving = false;
	}

	if (this->m_isAdding) {
		if (!this->m_states.empty()) {
			if (this->m_isReplacing) {
				this->m_states.pop();
			}			
		}
		this->m_states.push(std::move(this->m_newState));
		this->m_states.top()->initialise();
		this->m_isAdding = false;
	}
}

std::unique_ptr<view::State>& view::StateManager::getActiveState() {
	return this->m_states.top();
}