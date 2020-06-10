//
// Created by Pierre on 09/06/2020.
//

#include "ChoosePlayers.hpp"

ChoosePlayers::ChoosePlayers(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameScene(ctrl, name)
{
}

void ChoosePlayers::Init(void)
{
    this->_buttonOnePlayer = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(640, HEIGHT), vector2d<int>(0, 0), GUI_ID_ONE_PLAYER_BUTTON, "../assets/one_player_grey.jpg", "../assets/one_player.jpg");
    this->_buttonTwoPlayers = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(640, HEIGHT), vector2d<int>(640, 0), GUI_ID_TWO_PLAYERS_BUTTON, "../assets/two_players_grey.jpg", "../assets/two_players.jpg");
}

void ChoosePlayers::Update(void)
{
    this->_buttonOnePlayer->updateButton(this->_ctrl->_context);
    this->_buttonTwoPlayers->updateButton(this->_ctrl->_context);
}

void ChoosePlayers::Render(void)
{
    this->_ctrl->_env->drawAll();
}

void ChoosePlayers::Clear(void)
{
    this->_ctrl->_env->clear();
}