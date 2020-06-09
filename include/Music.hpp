//
// Created by Pierre on 09/06/2020.
//

#ifndef BOMBERMAN_MUSIC_HPP
#define BOMBERMAN_MUSIC_HPP

#include <SFML/Audio.hpp>
#include <string>

class Music {
    public:
        Music ();
        ~Music () {};

        int Play(std::string filepath);
        void Update(float value);
        void Stop(void);
        float getVolume(void);
    private:
        std::string _path_music;
        sf::Music _music;
        float _volume;
};


#endif //BOMBERMAN_MUSIC_HPP
