//
// Created by Pierre on 09/06/2020.
//

#include "Music.hpp"
#include "Error.hpp"

Music::Music(SAppContext &context) : _context(context)
{
    this->_path_music = "";
}

int Music::Play(std::string filepath)
{
    if (filepath == this->_path_music)
        return 0;
    this->_music.stop();
    if (!this->_music.openFromFile(filepath.c_str()))
        throw MusicError("Can't open music file");
    this->_path_music = filepath;
    this->_music.play();
    this->_music.setVolume(this->_context.volume_music);
    return (0);
}

void Music::Update(void)
{
    if (this->_context.volume_music < 100 && this->_context.up_volume) {
        this->_context.volume_music += 5;
        this->_context.up_volume = false;
    }
    if (this->_context.volume_music > 0 && this->_context.down_volume) {
        this->_context.volume_music -= 5;
        this->_context.down_volume = false;
    }
    this->_music.setVolume(this->_context.volume_music);

    if (this->_context.volume_sound < 100 && this->_context.up_volume_sound) {
        this->_context.volume_sound += 5;
        this->_context.up_volume_sound = false;
    }
    if (this->_context.volume_sound > 0 && this->_context.down_volume_sound) {
        this->_context.volume_sound -= 5;
        this->_context.down_volume_sound = false;
    }
}

void Music::Stop(void)
{
    this->_music.stop();
}

float Music::getVolume(void)
{
    return this->_context.volume_music;
}