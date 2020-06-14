//
// Created by peter on 13/06/2020.
//

#ifndef BOMBERMAN_ENDSCENE_HPP
#define BOMBERMAN_ENDSCENE_HPP

#include "Button.hpp"
#include "GameScene.hpp"
#include "Sound.hpp"

#define BACKGROUND_END "end/bgend.jpg"
#define MUSIC_END "audio/music_game.ogg"
#define RESTART "end/restart.png"
#define RESTART_DARK "end/restart_fonce.png"
#define EXIT_END "end/menu.png"
#define EXIT_END_DARK "end/menu_fonce.png"
#define BUTTON_SOUND_END "audio/sound_button.wav"


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
