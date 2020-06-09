//
// Created by Pierre on 06/06/2020.
//

#ifndef BOMBERMAN_SETTINGS_HPP
#define BOMBERMAN_SETTINGS_HPP

#include "Button.hpp"
#include "GameScene.hpp"
#include "Music.hpp"

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
    private:
        std::unique_ptr<Button> _buttonPlus;
        std::unique_ptr<Button> _buttonMinus;
        std::unique_ptr<Button> _buttonCredits;
        std::unique_ptr<Button> _buttonHelp;
        std::unique_ptr<Button> _buttonBack;
        std::unique_ptr<Music> _Music;
        ITexture *_background;
};


#endif //BOMBERMAN_SETTINGS_HPP
