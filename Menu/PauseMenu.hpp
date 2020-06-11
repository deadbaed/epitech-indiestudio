//
// Created by peter on 11/06/2020.
//

#ifndef BOMBERMAN_PAUSEMENU_HPP
#define BOMBERMAN_PAUSEMENU_HPP

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

class PauseMenu : public GameScene {
public:
    PauseMenu(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
    void Init(void);
    void Update(void);
    void Render(void);
private:
    std::unique_ptr<Button> _resume;
    std::unique_ptr<Button> _option;
    std::unique_ptr<Button> _exit;
    std::unique_ptr<Music> _Music;
    ITexture *_background;
    std::unique_ptr<Sound> _buttonSound;
};


#endif //BOMBERMAN_PAUSEMENU_HPP
