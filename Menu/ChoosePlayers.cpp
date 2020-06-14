//
// Created by Pierre on 09/06/2020.
//

#include "ChoosePlayers.hpp"
#include "AssetSelector.hpp"

ChoosePlayers::ChoosePlayers(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{
}

void ChoosePlayers::Init(void)
{
    this->_buttonOnePlayer = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(640, HEIGHT - 100), vector2d<int>(0, 100), GUI_ID_ONE_PLAYER_BUTTON, AssetSelector(ONE_PLAYER_GREY_C).string(), AssetSelector(ONE_PLAYER_C).string());
    this->_buttonTwoPlayers = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(640, HEIGHT - 100), vector2d<int>(640, 100), GUI_ID_TWO_PLAYERS_BUTTON, AssetSelector(TWO_PLAYERS_GREY_C).string(), AssetSelector(TWO_PLAYERS_C).string());
    this->_buttonBack = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(1280, 100), vector2d<int>(0, 0), GUI_ID_BACK_BUTTON, AssetSelector(BUTTON_BACK_GREY_C).string(), AssetSelector(BUTTON_BACK_C).string());
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, AssetSelector(BUTTON_SOUND_C).string());
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