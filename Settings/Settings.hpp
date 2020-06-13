//
// Created by Pierre on 06/06/2020.
//

#ifndef BOMBERMAN_SETTINGS_HPP
#define BOMBERMAN_SETTINGS_HPP

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

class Settings : public AScene {
    public:
        Settings(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
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


#endif //BOMBERMAN_SETTINGS_HPP
