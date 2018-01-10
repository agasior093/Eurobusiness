#pragma once

#include "../include/Field.h"

namespace logic {
	class Parking : public Field {
	public:
		Parking()
			: Field(false)
		{
			
		}
		~Parking() = default;
	
	};
}