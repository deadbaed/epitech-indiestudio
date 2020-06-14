//
// Created by Pierre on 09/06/2020.
//

#ifndef BOMBERMAN_CHOOSEPLAYERS_HPP
#define BOMBERMAN_CHOOSEPLAYERS_HPP

#include "Button.hpp"
#include "GameScene.hpp"
#include "Sound.hpp"

#define ONE_PLAYER_C "../assets/menu/one_player.jpg"
#define ONE_PLAYER_GREY_C "../assets/menu/one_player_grey.jpg"
#define TWO_PLAYERS_C "../assets/menu/two_players.jpg"
#define TWO_PLAYERS_GREY_C "../assets/menu/two_players_grey.jpg"
#define BUTTON_BACK_C "../assets/settings/home_p.jpg"
#define BUTTON_BACK_GREY_C "../assets/menu/home_grey_p.jpg"
#define BUTTON_SOUND_C "../assets/audio/sound_button.wav"

class ChoosePlayers : public AScene {
    public:
        ChoosePlayers(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        void Update(void);
        void Render(void);
        void Clear(void);
    private:
        std::unique_ptr<Button> _buttonOnePlayer;
        std::unique_ptr<Button> _buttonBack;
        std::unique_ptr<Button> _buttonTwoPlayers;
        std::unique_ptr<Sound> _buttonSound;
};


#endif //BOMBERMAN_CHOOSEPLAYERS_HPP
