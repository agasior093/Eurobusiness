#include "pch.h"

#include "C:\Users\aleks\Desktop\Eurobusiness\Eurobusiness\code\view\src\Button.cpp"

class ButtonTestable {
	Button button;
public:
	inline Button get() {
		return button;
	}
};

class ButtonTestSuite : public testing::Test {
public:
	ButtonTestable m_sut;
};

TEST_F(ButtonTestSuite, shouldBeEnabledAfterConstructing) {
	auto button = m_sut.get();
	ASSERT_EQ(button.isEnabled(), true);
}