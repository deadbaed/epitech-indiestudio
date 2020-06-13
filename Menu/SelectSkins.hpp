//
// Created by Pierre on 13/06/2020.
//

#ifndef BOMBERMAN_SELECTSKINS_HPP
#define BOMBERMAN_SELECTSKINS_HPP

#include "Button.hpp"
#include "GameScene.hpp"
#include "Sound.hpp"

class SelectSkins : public AScene {
    public:
        SelectSkins(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        void Update(void);
        void Render(void);
        void Clear(void);
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
        std::unique_ptr<Sound> _buttonSound;
};

#endif //BOMBERMAN_SELECTSKINS_HPP
