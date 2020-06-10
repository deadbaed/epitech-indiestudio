//
// Created by Pierre on 09/06/2020.
//

#include "Music.hpp"

Music::Music(const std::shared_ptr<IrrlichtController> &ctrl): _ctrl(ctrl)
{

}


int Music::Play(std::string filepath)
{
    if (!this->_music.openFromFile(filepath.c_str()))
        return -1;
    this->_music.play();
    this->_music.setVolume(this->_ctrl->_volume);
    return (0);
}

void Music::Update(void)
{
    if (this->_ctrl->_volume < 100 && this->_ctrl->_context.up_volume) {
        this->_ctrl->_volume += 5;
        this->_ctrl->_context.up_volume = false;
    }
    if (this->_ctrl->_volume > 0 && this->_ctrl->_context.down_volume) {
        this->_ctrl->_volume -= 5;
        this->_ctrl->_context.down_volume = false;
    }
    this->_music.setVolume(this->_ctrl->_volume);
}

void Music::Stop(void)
{
    this->_music.stop();
}

float Music::getVolume(void)
{
    return this->_ctrl->_volume;
}