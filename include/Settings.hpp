//
// Created by Pierre on 06/06/2020.
//

#ifndef BOMBERMAN_SETTINGS_HPP
#define BOMBERMAN_SETTINGS_HPP

#include <SFML/Audio.hpp>
#include "Button.hpp"
#include "GameScene.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Settings : public GameScene {
    public:
        Settings(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        void Update(void);
        void Render(void);
        void increase_volume(void);
        void decrease_volume(void);
        float get_volume(void);
        //void stopMusic(sf::Music *music);
    private:
        std::unique_ptr<Button> _buttonPlus;
        std::unique_ptr<Button> _buttonMinus;
        std::unique_ptr<Button> _buttonCredits;
        std::unique_ptr<Button> _buttonHelp;
        std::unique_ptr<Button> _buttonBack;
        //sf::Music _music;
        float _volume;
};


#endif //BOMBERMAN_SETTINGS_HPP
