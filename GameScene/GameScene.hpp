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

#define NB_POWER_UP 10

class GameScene : public AScene {
    public:
        GameScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        void Update(void);
    ~GameScene();
    protected:
    private:
        bool map_set;
        bool player_one_set;
        bool player_two_set;
        bool end;
        bool _powers;
        int _winner;
        void addPowerUp(unsigned int prob);
        std::shared_ptr<IGameObject> initPowerUp(irr::core::vector3df pos, const std::string name);
};

#endif /* !GAMESCENE_HPP_ */
