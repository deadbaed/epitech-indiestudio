//
// Created by Pierre on 09/06/2020.
//

#include "Music.hpp"

Music::Music()
{
    this->_volume = 70;
}


int Music::Play(std::string filepath)
{
    if (!this->_music.openFromFile(filepath.c_str()))
        return -1;
    this->_music.play();
    this->_music.setVolume(this->_volume);
    return (0);
}

void Music::Update(float value)
{
    this->_volume += value;
    this->_music.setVolume(this->_volume);
}

void Music::Stop(void)
{
    this->_music.stop();
}

float Music::getVolume(void)
{
    return this->_volume;
}