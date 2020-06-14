//
// Created by peter on 11/06/2020.
//

#include "PauseSettings.hpp"
#include "AssetSelector.hpp"

PauseSettings::PauseSettings(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{

}

void PauseSettings::Init(void)
{
    this->_background = this->_ctrl->_driver->getTexture(AssetSelector(BACKGROUND_PS).c_str());
    this->_buttonPlus = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 2) + 50, (HEIGHT / 2) - 100), GUI_ID_PLUS_BUTTON, AssetSelector(BUTTON_PLUS_PS), AssetSelector(BUTTON_PLUS_BIG_PS));
    this->_buttonMinus = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 2) - 150, (HEIGHT / 2) - 100), GUI_ID_MINUS_BUTTON, AssetSelector(BUTTON_MINUS_PS), AssetSelector(BUTTON_MINUS_BIG_PS));
    this->_buttonPlusSound = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 2) + 50, (HEIGHT / 2) + 100), GUI_ID_PLUS_BUTTON_SOUND, AssetSelector(BUTTON_PLUS_PS), AssetSelector(BUTTON_PLUS_BIG_PS));
    this->_buttonMinusSound = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 2) - 150, (HEIGHT / 2) + 100), GUI_ID_MINUS_BUTTON_SOUND, AssetSelector(BUTTON_MINUS_PS), AssetSelector(BUTTON_MINUS_BIG_PS));
    this->_buttonBack = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(400, 100), vector2d<int>(WIDTH / 2 - 200, HEIGHT / 2 + 230), GUI_ID_BACK_BUTTON_SETTINGS, AssetSelector(BUTTON_BACK_PS), AssetSelector(BUTTON_BACK_DARK_PS));
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, AssetSelector(BUTTON_SOUND_PS));
}

void PauseSettings::Update(void)
{
    if (this->_buttonBack->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonPlus->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonMinus->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonPlusSound->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonMinusSound->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
}

void PauseSettings::Render(void)
{
    _ctrl->_driver->draw2DImage(_background, core::position2d<s32>(0,0), core::rect<s32>(0,0,1280,720), 0, video::SColor(255,255,255,255), true);
    _ctrl->_env->drawAll();
}