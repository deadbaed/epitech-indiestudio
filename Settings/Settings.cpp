//
// Created by Pierre on 06/06/2020.
//

#include "Settings.hpp"

Settings::Settings(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameScene(ctrl, name)
{

}

void Settings::Init(void)
{
    this->_background = this->_ctrl->_driver->getTexture(("../assets/fond_settings.jpg"));
    this->_buttonPlus = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 4) + 90, (HEIGHT / 3) + 100), GUI_ID_PLUS_BUTTON, "../assets/volume_up.jpg", "../assets/volume_up_big.jpg");
    this->_buttonMinus = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 4) - 100, (HEIGHT / 3) + 100), GUI_ID_MINUS_BUTTON, "../assets/volume_down.jpg", "../assets/volume_down_big.jpg");
    this->_buttonBack = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(1280, 100), vector2d<int>(0, 0), GUI_ID_BACK_BUTTON, "../assets/home_p.jpg", "../assets/home_fonce.jpg");
}

void Settings::Update(void)
{
    this->_buttonBack->updateButton(this->_ctrl->_context);
    this->_buttonPlus->updateButton(this->_ctrl->_context);
    this->_buttonMinus->updateButton(this->_ctrl->_context);
}

void Settings::Render(void)
{
    _ctrl->_driver->draw2DImage(_background, core::position2d<s32>(0,0), core::rect<s32>(0,0,1280,720), 0, video::SColor(255,255,255,255), true);
    _ctrl->_env->drawAll();
}
