//
// Created by peter on 08/06/2020.
//

#include "Menu.hpp"

Menu::Menu(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameScene(ctrl, name)
{

}

void Menu::Init(void)
{
    this->_buttonSettings = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(427, HEIGHT), vector2d<int>(0, 0), GUI_ID_SETTINGS_BUTTON, "../assets/left_grey_button.jpg", "../assets/left_button.jpg");
    this->_buttonPlay = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(427, HEIGHT), vector2d<int>(427, 0), GUI_ID_PLAY_BUTTON, "../assets/middle_grey_button.jpg", "../assets/middle_button.jpg");
    this->_buttonExit = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(427, HEIGHT), vector2d<int>(854, 0), GUI_ID_EXIT_BUTTON, "../assets/right_grey_button.jpg", "../assets/right_button.jpg");
    this->_ctrl->_music->Play("../assets/menu_music.ogg");
}

void Menu::Update(void)
{
    this->_buttonPlay->updateButton(this->_ctrl->_context);
    this->_buttonSettings->updateButton(this->_ctrl->_context);
    this->_buttonExit->updateButton(this->_ctrl->_context);
}

void Menu::Render(void)
{
    this->_ctrl->_env->drawAll();
}

void Menu::Clear(void)
{
    this->_ctrl->_env->clear();
}