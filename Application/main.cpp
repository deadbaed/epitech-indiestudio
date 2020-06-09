/*
** EPITECH PROJECT, 2020
** Indie
** File description:
** main
*/

#include "../GameObject/GameObject.hpp"
#include "../GameScene/GameScene.hpp"
#include "../GameScene/GameSceneManager.hpp"
#include "../Controller/IrrlichtController.hpp"
#include "../Player/Player.hpp"
#include "../GameScene/TestGameScene.hpp"
#include "../EventReceiver/MyEventReceiver.hpp"
#include "../Menu/Menu.hpp"
#include "../Settings/Settings.hpp"
#include "../GameScene/TestGameSceneTest.hpp"

int main(void)
{
    std::shared_ptr<IrrlichtController> c = std::make_shared<IrrlichtController>();
    c->Init(irr::video::E_DRIVER_TYPE::EDT_OPENGL, WIDTH, HEIGHT);

    std::shared_ptr<TestGameScene> testScene = std::make_shared<TestGameScene>(c, "gameScene");
    std::shared_ptr<Menu> menu = std::make_shared<Menu>(c, "menuScene");
    std::shared_ptr<Settings> set = std::make_shared<Settings>(c, "settingsScene");
    GameSceneManager m(c);
    m.AddScene(testScene);
    m.AddScene(menu);
    m.AddScene(set);
    m.LoadScene("menuScene");
    while (c->isRunning())
    {
        m.Update();
    }
    return 0;
}
