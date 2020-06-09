/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** TestGameScene
*/

#ifndef TESTGAMESCENE_HPP_
#define TESTGAMESCENE_HPP_

#include "GameScene.hpp"

class TestGameScene : public GameScene {
    public:
        TestGameScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        ~TestGameScene();
    protected:
    private:
};

#endif /* !TESTGAMESCENE_HPP_ */
