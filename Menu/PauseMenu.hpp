//
// Created by peter on 11/06/2020.
//

#ifndef BOMBERMAN_PAUSEMENU_HPP
#define BOMBERMAN_PAUSEMENU_HPP

#include "Button.hpp"
#include "GameScene.hpp"
#include "Music.hpp"
#include "Sound.hpp"

#define BACKGROUND_PM "pause/fd_pause.jpg"
#define RESUME_PM "pause/resume.jpg"
#define RESUME_DARK_PM "pause/resume_fonce.jpg"
#define OPTION_PM "pause/settings_pause.jpg"
#define OPTION_DARK_PM "pause/settings_pause_fonce.jpg"
#define EXIT_PM "pause/exit_pause.jpg"
#define EXIT_DARK_PM "pause/exit_pause_fonce.jpg"
#define BUTTON_SOUND_PM "audio/sound_button.wav"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class PauseMenu : public AScene {
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
