#pragma once

#include "../include/Field.h"

namespace logic {
	class JailVisitor : public Field {
	public:
		JailVisitor()
			: Field(false)
		{
			
		}
		~JailVisitor() = default;
	
	};
}