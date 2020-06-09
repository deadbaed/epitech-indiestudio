//
// Created by Pierre on 06/06/2020.
//

#include "Settings.hpp"

Settings::Settings(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameScene(ctrl, name)
{

}

void Settings::Init(void)
{
    //if (!this->_music.openFromFile("../src/menu/assets/menu_music.ogg"))
    //return -1;
    //this->_music.play();
    this->_volume = 70;
    //this->_music.setVolume(this->_volume);
    this->_buttonPlus = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(80, 80), vector2d<int>(WIDTH / 3, HEIGHT / 3), GUI_ID_PLUS_BUTTON, "../assets/volume_up.png");
    this->_buttonMinus = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(65, 65), vector2d<int>(WIDTH / 3, HEIGHT / 2), GUI_ID_MINUS_BUTTON, "../assets/volume_down.png");
    this->_buttonCredits = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(263, 100), vector2d<int>(WIDTH - (WIDTH / 3), HEIGHT / 3), GUI_ID_CREDITS_BUTTON, "../assets/credits.png");
    this->_buttonHelp = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>(WIDTH - (WIDTH / 3), HEIGHT / 2), GUI_ID_HELP_BUTTON, "../assets/help.png");
    this->_buttonBack = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>(WIDTH / 2, HEIGHT / 4), GUI_ID_BACK_BUTTON, "../assets/home.png");
}

void Settings::Update(void)
{

}

void Settings::Render(void)
{
    _ctrl->_env->drawAll();
}

void Settings::increase_volume(void)
{
    if (this->_volume < 100) {
        this->_volume += 5;
    //this->_music.setVolume(this->_volume);
    }
}

void Settings::decrease_volume(void)
{
    if (this->_volume > 0) {
        this->_volume -= 5;
    //this->_music.setVolume(this->_volume);
    }
}

float Settings::get_volume(void)
{
    return this->_volume;
}

//
//void Settings::stopMusic(sf::Music *music)
//{
//    music->stop();
//}