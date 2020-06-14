/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include "AScene.hpp"
#include "PowerUp.hpp"

#define MUSIC_GAME "audio/music_game.ogg"
#define FLOOR_ASSET "map/floor.obj"
#define WALL1_ASSET "map/wall_1.obj"
#define WALL2_ASSET "map/wall_2.obj"

class GameScene : public AScene {
    public:
        GameScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        ~GameScene();
    protected:
    private:
        void addPowerUp(unsigned int prob);
        std::shared_ptr<IGameObject> initPowerUp(irr::core::vector3df pos, const std::string name);
};

#endif /* !GAMESCENE_HPP_ */
