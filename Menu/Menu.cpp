//
// Created by peter on 08/06/2020.
//

#include "Menu.hpp"

Menu::Menu(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{

}

void Menu::Init(void)
{
    this->_buttonSettings = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(427, HEIGHT), vector2d<int>(0, 0), GUI_ID_SETTINGS_BUTTON, "../assets/menu/left_grey_button.jpg", "../assets/menu/left_button.jpg");
    this->_buttonPlay = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(427, HEIGHT), vector2d<int>(427, 0), GUI_ID_PLAY_BUTTON, "../assets/menu/middle_grey_button.jpg", "../assets/menu/middle_button.jpg");
    this->_buttonExit = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(427, HEIGHT), vector2d<int>(854, 0), GUI_ID_EXIT_BUTTON, "../assets/menu/right_grey_button.jpg", "../assets/menu/right_button.jpg");
    this->_ctrl->_music->Play("../assets/audio/menu_music.ogg");
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, "../assets/audio/sound_button.wav");
}

void Menu::Update(void)
{
    if (this->_buttonPlay->updateButton(this->_ctrl->_context) == 1)
        this->_buttonSound->Play();
    if (this->_buttonSettings->updateButton(this->_ctrl->_context) == 1)
        this->_buttonSound->Play();
    if (this->_buttonExit->updateButton(this->_ctrl->_context) == 1)
        this->_buttonSound->Play();
}

void Menu::Render(void)
{
    this->_ctrl->_env->drawAll();
}

void Menu::Clear(void)
{
    this->_ctrl->_env->clear();
}