//
// Created by peter on 11/06/2020.
//

#include "PauseMenu.hpp"

PauseMenu::PauseMenu(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameScene(ctrl, name)
{

}

void PauseMenu::Init(void)
{
    this->_background = this->_ctrl->_driver->getTexture(("../assets/fd_pause.jpg"));

    this->_resume = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(400, 100), vector2d<int>(WIDTH / 2 - 200, HEIGHT / 2 - 120), GUI_ID_RESUME_BUTTON_PAUSED, "../assets/resume.jpg", "../assets/resume_fonce.jpg");
    this->_option = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(400, 100), vector2d<int>(WIDTH/ 2 - 200, HEIGHT / 2), GUI_ID_OPTION_BUTTON_PAUSED, "../assets/settings_pause.jpg", "../assets/settings_pause_fonce.jpg");
    this->_exit = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(400, 100), vector2d<int>(WIDTH / 2 - 200, HEIGHT / 2 + 120), GUI_ID_EXIT_BUTTON_PAUSED, "../assets/exit_pause.jpg", "../assets/exit_pause_fonce.jpg");
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, "../assets/sound_button.wav");
}

void PauseMenu::Update(void)
{
    if (this->_exit->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_resume->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_option->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
}

void PauseMenu::Render(void)
{
    _ctrl->_driver->draw2DImage(_background, core::position2d<s32>(0,0), core::rect<s32>(0,0,1280,720), 0, video::SColor(255,255,255,255), true);
    _ctrl->_env->drawAll();
}
