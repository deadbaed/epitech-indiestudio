//
// Created by Pierre on 13/06/2020.
//

#ifndef BOMBERMAN_SELECTSKINS_HPP
#define BOMBERMAN_SELECTSKINS_HPP

#include "Button.hpp"
#include "GameScene.hpp"
#include "Sound.hpp"
#include "Player.hpp"

#define BACKGROUND_SSS "../assets/menu/fd_select.jpg"
#define FIRST_SKIN_SSS "../assets/menu/white.jpg"
#define SECOND_SKIN_SSS "../assets/menu/green.jpg"
#define THIRD_SKIN_SSS "../assets/menu/blue.jpg"
#define FOURTH_SKIN_SSS "../assets/menu/black.png"
#define BUTTON_SOUND_SSS "../assets/audio/sound_button.wav"
#define BUTTON_GO_SSS "../assets/menu/go.png"
#define BUTTON_GO_DARK_SSS "../assets/menu/go_fonce.png"
#define BUTTON_BACK_SSS "../assets/menu/fleche.png"
#define BUTTON_BACK_DARK_SSS "../assets/menu/fleche_fonce.png"





class SelectSkins : public AScene {
    public:
        SelectSkins(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        void Update(void);
        void Render(void);
        void Clear(void);
        void SelectPlayerOne();
        void SelectPlayerTwo();
    private:
        ITexture *_background;
        std::unique_ptr<Button> _first_skin_one;
        std::unique_ptr<Button> _second_skin_one;
        std::unique_ptr<Button> _third_skin_one;
        std::unique_ptr<Button> _fourth_skin_one;
        std::unique_ptr<Button> _first_skin_two;
        std::unique_ptr<Button> _second_skin_two;
        std::unique_ptr<Button> _third_skin_two;
        std::unique_ptr<Button> _fourth_skin_two;
        std::unique_ptr<Button> _buttonGo;
        std::unique_ptr<Button> _buttonBack;
        std::unique_ptr<Sound> _buttonSound;

        std::unique_ptr<Player> p1;
        std::unique_ptr<Player> p2;
        std::unique_ptr<Player> p3;
        std::unique_ptr<Player> p4;

        int _current_skin1;
        int _current_skin2;
};

#endif //BOMBERMAN_SELECTSKINS_HPP
