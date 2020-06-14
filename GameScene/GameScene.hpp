/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include <iostream>
#include "AScene.hpp"
#include "Player.hpp"
#include "MapGenerator.hpp"

class GameScene : public AScene {
    public:
        GameScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        ~GameScene();
    protected:
    private:
    bool map_set;
    bool player_one_set;
    bool player_two_set;
    std::shared_ptr<mapGenerator> map;
};

#endif /* !GAMESCENE_HPP_ */
