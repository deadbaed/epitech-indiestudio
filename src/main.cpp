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
#include "MyEventReceiver.hpp"
#include "Menu.hpp"
#include "Settings.hpp"
#include "TestGameSceneTest.hpp"
#include <unistd.h>

int main(void)
{
    std::shared_ptr<IrrlichtController> c = std::make_shared<IrrlichtController>();
    c->Init(irr::video::E_DRIVER_TYPE::EDT_OPENGL, WIDTH, HEIGHT);

    std::shared_ptr<TestGameScene> testScene = std::make_shared<TestGameScene>(c, "test");
    std::shared_ptr<Menu> menu = std::make_shared<Menu>(c, "menu");
    std::shared_ptr<Settings> set = std::make_shared<Settings>(c, "set");
    GameSceneManager m(c);

    m.AddScene(testScene);
    m.AddScene(menu);
    m.AddScene(set);

    m.LoadScene("menu");

    while (c->isRunning())
    {
        m.Update();
    }
    return 0;
}
