#include "../include/Dice.h"

int logic::Dice::roll() {
	std::uniform_int_distribution<int> dist(1, 6);	 
	return dist(rng);
}