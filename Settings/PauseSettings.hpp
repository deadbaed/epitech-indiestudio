//
// Created by peter on 11/06/2020.
//

#ifndef BOMBERMAN_PAUSESETTINGS_HPP
#define BOMBERMAN_PAUSESETTINGS_HPP

#include "Button.hpp"
#include "GameScene.hpp"
#include "Music.hpp"
#include "Sound.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class PauseSettings : public GameScene {
    public:
        PauseSettings(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        void Update(void);
        void Render(void);
    private:
        std::unique_ptr<Button> _buttonPlus;
        std::unique_ptr<Button> _buttonMinus;
        std::unique_ptr<Button> _buttonPlusSound;
        std::unique_ptr<Button> _buttonMinusSound;
        std::unique_ptr<Button> _buttonBack;
        ITexture *_background;
        std::unique_ptr<Sound> _buttonSound;
};

#endif //BOMBERMAN_PAUSESETTINGS_HPP
