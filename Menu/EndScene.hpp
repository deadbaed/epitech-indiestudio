//
// Created by peter on 13/06/2020.
//

#ifndef BOMBERMAN_ENDSCENE_HPP
#define BOMBERMAN_ENDSCENE_HPP

#include "Button.hpp"
#include "GameScene.hpp"
#include "Sound.hpp"

class EndScene : public AScene{
public:
    EndScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
    void Init(void);
    void Update(void);
    void Render(void);
    void Clear(void);
private:
    std::unique_ptr<Button> _restart;
    std::unique_ptr<Button> _exit;
    std::unique_ptr<Sound> _buttonSound;
    ITexture *_background;
};


#endif //BOMBERMAN_ENDSCENE_HPP
