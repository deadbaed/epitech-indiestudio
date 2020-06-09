//
// Created by peter on 08/06/2020.
//

#ifndef BOMBERMAN_MENU_HPP
#define BOMBERMAN_MENU_HPP

#include "GameScene.hpp"
#include "Button.hpp"

class Menu : public GameScene {
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
};


#endif //BOMBERMAN_MENU_HPP
