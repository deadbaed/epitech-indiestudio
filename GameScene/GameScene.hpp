/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include "AScene.hpp"

#define MUSIC_GAME "audio/music_game.ogg"
#define FLOOR_ASSET "floor.obj"
#define WALL1_ASSET "wall_1.obj"
#define WALL2_ASSET "wall_2.obj"

class GameScene : public AScene {
    public:
        GameScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        ~GameScene();
    protected:
    private:
};

#endif /* !GAMESCENE_HPP_ */
