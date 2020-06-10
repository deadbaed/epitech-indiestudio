//
// Created by Pierre on 09/06/2020.
//

#ifndef BOMBERMAN_MUSIC_HPP
#define BOMBERMAN_MUSIC_HPP

#include <SFML/Audio.hpp>
#include <string>
#include "IrrlichtController.hpp"

class Music {
    public:
        Music (const std::shared_ptr<IrrlichtController> &ctrl);
        ~Music () {};

        int Play(std::string filepath);
        void Update(void);
        void Stop(void);
        float getVolume(void);
    private:
        const std::shared_ptr<IrrlichtController> &_ctrl;
        std::string _path_music;
        sf::Music _music;
};


#endif //BOMBERMAN_MUSIC_HPP
