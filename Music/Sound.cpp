//
// Created by peter on 11/06/2020.
//

#include "Sound.hpp"
#include "Error.hpp"

Sound::Sound(SAppContext &context, const std::string path) : _context(context)
{
    if (!this->_buffer.loadFromFile(path))
        throw MusicError("Can't open sound file");
    this->_sound.setBuffer(this->_buffer);
    this->_sound.setVolume(_context.volume_sound);
}

int Sound::Play(void)
{
    this->_sound.setVolume(_context.volume_sound);
    this->_sound.play();
    return (0);
}