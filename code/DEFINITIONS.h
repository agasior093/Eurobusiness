#pragma once

constexpr auto JAIL_TIME = 3;
constexpr auto JAIL_POSITION = 10;
constexpr auto BOARD_SIZE = 40;
constexpr auto PASSED_START_CASH = 400.0f;
constexpr auto STARTING_POSITION_X = 675.f;
constexpr auto STARTING_POSITION_Y = 675.f;

constexpr auto APPLICATION_SCREEN_WIDTH = 720;
constexpr auto APPLICATION_SCREEN_HEIGHT = 720;
constexpr auto APPLICATION_TITLE = "Eurobusiness";

constexpr auto MENU_STATE_BACKGROUND_FILE = "resources//board.png";
constexpr auto CANDARA_FONT_FILE = "resources//Candara.ttf";

//dice
constexpr auto FIRST_DICE_POSITION_X = 300.f;
constexpr auto FIRST_DICE_POSITION_Y = 130.f;
constexpr auto SECOND_DICE_POSITION_X = 360.f;
constexpr auto SECOND_DICE_POSITION_Y = 105.f;

constexpr auto DICE_WIDTH = 55.f;
constexpr auto DICE_HEIGHT = 55.f;
constexpr auto DICE_SOUND = "resources//diceSound.wav";
constexpr auto DICE_TEXTURE = "resources//dice.png";

//current field background
constexpr auto DEFAULT_FIELD_BACKGROUND = "resources//default_current_field.png";
constexpr auto FIELD_BACKGROUNDS = "resources//field_backgrounds.png";

//active/not active player
constexpr auto PLAYER_LABEL_WIDTH = 140.f;
constexpr auto PLAYER_LABEL_HEIGHT = 70.f;
constexpr auto PLAYER_LABEL = "resources//player_label.png";

constexpr auto PLAYER_LABEL_POSITION_X = 110;
constexpr auto PLAYER_ONE_LABEL_POSITION_Y = 215;
constexpr auto PLAYER_TWO_LABEL_POSITION_Y = 290;
constexpr auto PLAYER_THREE_LABEL_POSITION_Y = 365;
constexpr auto PLAYER_FOUR_LABEL_POSITION_Y = 440;

//buttons
constexpr auto NEW_GAME_BUTTON_FILE = "resources//buttons//play_button.png";
constexpr auto ROLL_THE_DICE_BUTTON_FILE = "resources//buttons//roll_button.png";
constexpr auto DISABLED_ROLL_THE_DICE_BUTTON_FILE = "resources//buttons//disabled_roll_button.png";
constexpr auto END_TURN_BUTTON_FILE = "resources//buttons//end_turn_button.png";
constexpr auto DISABLED_END_TURN_BUTTON_FILE = "resources//buttons//disabled_end_turn_button.png";
constexpr auto PAY_BUTTON_FILE = "resources//buttons//pay_button.png";
constexpr auto DISABLED_PAY_BUTTON_FILE = "resources//buttons//disabled_pay_button.png";
constexpr auto JAIL_CARD_BUTTON_FILE = "resources//buttons//jail_card_button.png";
constexpr auto DISABLED_JAIL_CARD_BUTTON_FILE = "resources//buttons//disabled_jail_card_button.png";
constexpr auto BUY_BUTTON_FILE = "resources//buttons//buy_button.png";
constexpr auto DISABLED_BUY_BUTTON_FILE = "resources//buttons//disabled_buy_button.png";
constexpr auto PROPERTY_MANAGER_BUTTON_FILE = "resources//buttons//property_manager_button.png";
constexpr auto DISABLED_PROPERTY_MANAGER_BUTTON_FILE = "resources//buttons//disabled_property_manager_button.png";
constexpr auto REVEAL_BUTTON_FILE = "resources//buttons//reveal_button.png";
constexpr auto DISABLED_REVEAL_BUTTON_FILE = "resources//buttons//disabled_reveal_button.png";
constexpr auto COLLECT_BUTTON_FILE = "resources//buttons//collect_button.png";
constexpr auto DISABLED_COLLECT_BUTTON_FILE = "resources//buttons//disabled_collect_button.png";