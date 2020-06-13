//
// Created by Pierre on 13/06/2020.
//

#include "SelectSkins.hpp"

SelectSkins::SelectSkins(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{
}

void SelectSkins::Init(void)
{
    this->_background = this->_ctrl->_driver->getTexture(("../assets/pause/fd_pause.jpg"));
    this->_first_skin_one = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>((WIDTH / 4) - 75, HEIGHT - 110), GUI_ID_SKIN_WHITE_BUTTON, "../assets/menu/white.jpg", "../assets/menu/white.jpg");
    this->_second_skin_one = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>((WIDTH / 4) - 155, HEIGHT - 110), GUI_ID_SKIN_BLUE_BUTTON, "../assets/menu/green.jpg", "../assets/menu/green.jpg");
    this->_third_skin_one = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>((WIDTH / 4) + 5, HEIGHT - 110), GUI_ID_SKIN_BLACK_BUTTON, "../assets/menu/red.jpg", "../assets/menu/red.jpg");
    this->_fourth_skin_one = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>((WIDTH / 4) + 85, HEIGHT - 110), GUI_ID_SKIN_GREEN_BUTTON, "../assets/menu/blue.jpg", "../assets/menu/blue.jpg");
    this->_first_skin_two = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>(WIDTH - (WIDTH / 4) - 75, HEIGHT - 110), GUI_ID_SKINS_WHITE_BUTTON, "../assets/menu/white.jpg", "../assets/menu/white.jpg");
    this->_second_skin_two = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>(WIDTH - (WIDTH / 4) - 155, HEIGHT - 110), GUI_ID_SKINS_BLUE_BUTTON, "../assets/menu/green.jpg", "../assets/menu/green.jpg");
    this->_third_skin_two = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>(WIDTH - (WIDTH / 4) + 5, HEIGHT - 110), GUI_ID_SKINS_BLACK_BUTTON, "../assets/menu/red.jpg", "../assets/menu/red.jpg");
    this->_fourth_skin_two = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>(WIDTH - (WIDTH / 4) + 85, HEIGHT - 110), GUI_ID_SKINS_GREEN_BUTTON, "../assets/menu/blue.jpg", "../assets/menu/blue.jpg");
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, "../assets/audio/sound_button.wav");
    this->_buttonGo = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(150, 150), vector2d<int>((WIDTH / 2) - 75, HEIGHT - 160), GUI_ID_GO_BUTTON, "../assets/menu/white.jpg", "../assets/menu/white.jpg");
}

void SelectSkins::Update(void)
{
    if (this->_first_skin_one->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_second_skin_one->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_third_skin_one->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_fourth_skin_one->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();

    if (this->_first_skin_two->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_second_skin_two->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_third_skin_two->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_fourth_skin_two->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonGo->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
}

void SelectSkins::Render(void)
{
    this->_ctrl->_driver->draw2DImage(_background, core::position2d<s32>(0,0), core::rect<s32>(0,0,1280,720), 0, video::SColor(255,255,255,255), true);
    this->_ctrl->_env->drawAll();
}

void SelectSkins::Clear(void)
{
    this->_ctrl->_env->clear();
}