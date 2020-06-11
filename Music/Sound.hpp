//
// Created by peter on 11/06/2020.
//

#ifndef BOMBERMAN_SOUND_HPP
#define BOMBERMAN_SOUND_HPP

#include <SFML/Audio.hpp>
#include <string>
#include <memory>
#include "MyEventReceiver.hpp"

class Sound {
    public:
        Sound(SAppContext &context, const std::string path);
        ~Sound(){};
        int Play(void);

    private:
        sf::SoundBuffer _buffer;
        sf::Sound _sound;
        SAppContext &_context;
};

#endif //BOMBERMAN_SOUND_HPP
