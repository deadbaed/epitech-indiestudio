//
// Created by Pierre on 09/06/2020.
//

#ifndef BOMBERMAN_MUSIC_HPP
#define BOMBERMAN_MUSIC_HPP

#include <SFML/Audio.hpp>
#include <string>
#include <memory>
#include "MyEventReceiver.hpp"

class Music {
    public:
        Music(SAppContext &context);
        ~Music(){};

        int Play(std::string filepath);
        void Update(void);
        void Stop(void);
        float getVolume(void);
    private:
        std::string _path_music;
        sf::Music _music;
        SAppContext &_context;
};


#endif //BOMBERMAN_MUSIC_HPP
