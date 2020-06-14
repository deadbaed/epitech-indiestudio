//
// Created by Pierre on 06/06/2020.
//

#include "Settings.hpp"
#include "AssetSelector.hpp"

Settings::Settings(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{

}

void Settings::Init(void)
{
    this->_background = this->_ctrl->_driver->getTexture(AssetSelector(BACKGROUND_S).c_str());
    this->_buttonPlus = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 4) + 70, (HEIGHT / 3) + 150), GUI_ID_PLUS_BUTTON, AssetSelector(BUTTON_PLUS_S), AssetSelector(BUTTON_PLUS_BIG_S));
    this->_buttonMinus = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 4) - 130, (HEIGHT / 3) + 150), GUI_ID_MINUS_BUTTON, AssetSelector(BUTTON_MINUS_S), AssetSelector(BUTTON_MINUS_BIG_S));
    this->_buttonPlusSound = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 4) + 70, (HEIGHT / 3) + 350), GUI_ID_PLUS_BUTTON_SOUND, AssetSelector(BUTTON_PLUS_S), AssetSelector(BUTTON_PLUS_BIG_S));
    this->_buttonMinusSound = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 4) - 130, (HEIGHT / 3) + 350), GUI_ID_MINUS_BUTTON_SOUND, AssetSelector(BUTTON_MINUS_S), AssetSelector(BUTTON_MINUS_BIG_S));
    this->_buttonBack = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(1280, 100), vector2d<int>(0, 0), GUI_ID_BACK_BUTTON, AssetSelector(BUTTON_BACK_S), AssetSelector(BUTTON_BACK_DARK_S));
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, AssetSelector(BUTTON_SOUND_S));
}

void Settings::Update(void)
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

void Settings::Render(void)
{
    _ctrl->_driver->draw2DImage(_background, core::position2d<s32>(0,0), core::rect<s32>(0,0,1280,720), 0, video::SColor(255,255,255,255), true);
    _ctrl->_env->drawAll();
}
