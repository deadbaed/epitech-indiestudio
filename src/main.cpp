/*
** EPITECH PROJECT, 2020
** Indie
** File description:
** main
*/

#include "GameObject.hpp"
#include "GameScene.hpp"
#include "GameSceneManager.hpp"
#include "IrrlichtController.hpp"
#include "Player.hpp"

#include "TestGameScene.hpp"

#include <unistd.h>

int main(void)
{


    std::shared_ptr<IrrlichtController> c = std::make_shared<IrrlichtController>();
    std::shared_ptr<TestGameScene> s = std::make_shared<TestGameScene>(c, "test");
    //std::shared_ptr<Player> p = std::make_shared<Player>(c, "player 1");
    //std::shared_ptr<Player> p2 = std::make_shared<Player>(c, "player 2");
    c->Init(irr::video::E_DRIVER_TYPE::EDT_OPENGL, 1080, 720);
    //p->Init("player_1.obj");
    //s->Init();
    //s->AddGameObject(p);
    GameSceneManager m(c);
    m.AddScene(s);
    m.LoadScene("test");
    int i = 0;
    while (c->isRunning())
    {
        m.Update();
    }
    return 0;
}
