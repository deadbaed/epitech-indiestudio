//
// Created by peter on 08/06/2020.
//

#ifndef BOMBERMAN_MENU_HPP
#define BOMBERMAN_MENU_HPP

#include "GameScene.hpp"
#include "Button.hpp"
#include "Sound.hpp"

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
