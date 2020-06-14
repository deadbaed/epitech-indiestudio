//
// Created by Pierre on 10/06/2020.
//

#ifndef BOMBERMAN_INTRODUCTION_HPP
#define BOMBERMAN_INTRODUCTION_HPP

#include "GameScene.hpp"

#include <ctime>
#include <chrono>

#define WELCOME "menu/back_intro_welcome.jpg"
#define SPACE "menu/back_intro_space.jpg"
#define FIRST_PART "menu/first_part.jpg"
#define SECOND_PART "menu/second_part.jpg"
#define THIRD_PART "menu/third_part.jpg"
#define FOURTH_PART "menu/fourth_part.jpg"
#define MENU_INTRO_MUSIC "audio/music_intro.ogg"

class Introduction : public AScene {
    public:
        Introduction(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        void Update(void);
        void Render(void);
        void Clear(void);
    private:
        video::ITexture* _image_welcome;
        video::ITexture* _image_space;
//        video::ITexture* _logo;
        video::ITexture* _first_part;
        video::ITexture* _second_part;
        video::ITexture* _third_part;
        video::ITexture* _fourth_part;

        int _select;
        int _logo;
        std::chrono::time_point<std::chrono::steady_clock> start;
        std::chrono::time_point<std::chrono::steady_clock> end;
        std::chrono::duration<double> elapsed_seconds;
        unsigned long seconds;
};


#endif //BOMBERMAN_INTRODUCTION_HPP
