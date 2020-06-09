/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** TestGameScene
*/

#ifndef TESTGAMESCENETEST_HPP_
#define TESTGAMESCENETEST_HPP_

#include "GameScene.hpp"

class TestGameSceneTest : public GameScene {
    public:
        TestGameSceneTest(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        ~TestGameSceneTest();
    protected:
    private:
};

#endif /* !TESTGAMESCENE_HPP_ */
