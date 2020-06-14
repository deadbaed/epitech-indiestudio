//
// Created by peter on 08/06/2020.
//

#ifndef BOMBERMAN_MENU_HPP
#define BOMBERMAN_MENU_HPP

#include "GameScene.hpp"
#include "Button.hpp"
#include "Sound.hpp"

#define BUTTON_SETTINGS_M  "menu/left_button.jpg"
#define BUTTON_SETTINGS_GREY_M "menu/left_grey_button.jpg"
#define PLAY_M "menu/middle_button.jpg"
#define PLAY_GREY_M "menu/middle_grey_button.jpg"
#define MUSIC_M "audio/menu_music.ogg"
#define EXIT_M "menu/right_button.jpg"
#define EXIT_GREY_M "menu/right_grey_button.jpg"
#define BUTTON_SOUND_M "audio/sound_button.wav"

class Menu : public AScene {
    public:
        Menu(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        void Update(void);
        void Render(void);
        void Clear(void);
    private:
        std::unique_ptr<Button> _buttonSettings;
        std::unique_ptr<Button> _buttonPlay;
        std::unique_ptr<Button> _buttonExit;
        std::unique_ptr<Sound> _buttonSound;
};


#endif //BOMBERMAN_MENU_HPP
