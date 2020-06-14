//
// Created by peter on 08/06/2020.
//

#include "Menu.hpp"
#include "AssetSelector.hpp"

Menu::Menu(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{

}

void Menu::Init(void)
{
    this->_buttonSettings = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(427, HEIGHT), vector2d<int>(0, 0), GUI_ID_SETTINGS_BUTTON, AssetSelector(BUTTON_SETTINGS_GREY_M), AssetSelector(BUTTON_SETTINGS_M));
    this->_buttonPlay = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(427, HEIGHT), vector2d<int>(427, 0), GUI_ID_PLAY_BUTTON, AssetSelector(PLAY_GREY_M), AssetSelector(PLAY_M));
    this->_buttonExit = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(427, HEIGHT), vector2d<int>(854, 0), GUI_ID_EXIT_BUTTON, AssetSelector(EXIT_GREY_M), AssetSelector(EXIT_M));
    this->_ctrl->_music->Play(AssetSelector(MUSIC_M));
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, AssetSelector(BUTTON_SOUND_M));
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