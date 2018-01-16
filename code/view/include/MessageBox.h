#include <SFML/Graphics.hpp>
#include <string>
#include "DEFINITIONS.h"

namespace view {
	class MessageBox {
		sf::Font m_font;
		sf::Text m_messageBox;
	public:
		void create(float, float, int, sf::Color, std::string);
		void changeText(std::string text);
		sf::Text& get();
	};
}
