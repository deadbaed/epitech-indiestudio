//
// Created by Pierre on 09/06/2020.
//

#ifndef BOMBERMAN_CHOOSEPLAYERS_HPP
#define BOMBERMAN_CHOOSEPLAYERS_HPP

#include "Button.hpp"
#include "GameScene.hpp"
#include "Sound.hpp"

class ChoosePlayers : public GameScene {
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
