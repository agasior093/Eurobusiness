#pragma once

#include <memory>
#include <stack>

#include "State.h"

namespace view {
	class StateManager {
		std::stack<std::unique_ptr<State>> m_states;
		std::unique_ptr<State> m_newState;

		bool m_isAdding;
		bool m_isReplacing;
		bool m_isRemoving;
	public:
		StateManager() {}
		~StateManager() {}

		void addState(std::unique_ptr<State> newView, bool isReplacing = true);
		void removeState();
		void processStateChanges();
		std::unique_ptr<State>& getActiveState();
	};
}

