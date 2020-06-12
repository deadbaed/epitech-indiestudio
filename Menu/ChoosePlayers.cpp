//
// Created by Pierre on 09/06/2020.
//

#include "ChoosePlayers.hpp"

ChoosePlayers::ChoosePlayers(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameScene(ctrl, name)
{
}

void ChoosePlayers::Init(void)
{
    this->_buttonOnePlayer = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(640, HEIGHT - 100), vector2d<int>(0, 100), GUI_ID_ONE_PLAYER_BUTTON, "../assets/menu/one_player_grey.jpg", "../assets/menu/one_player.jpg");
    this->_buttonTwoPlayers = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(640, HEIGHT - 100), vector2d<int>(640, 100), GUI_ID_TWO_PLAYERS_BUTTON, "../assets/menu/two_players_grey.jpg", "../assets/menu/two_players.jpg");
    this->_buttonBack = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(1280, 100), vector2d<int>(0, 0), GUI_ID_BACK_BUTTON, "../assets/menu/home_grey_p.jpg", "../assets/settings/home_p.jpg");
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, "../assets/audio/sound_button.wav");
}

void ChoosePlayers::Update(void)
{
    if (this->_buttonOnePlayer->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonTwoPlayers->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonBack->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
}

void ChoosePlayers::Render(void)
{
    this->_ctrl->_env->drawAll();
}

void ChoosePlayers::Clear(void)
{
    this->_ctrl->_env->clear();
}