/*
** EPITECH PROJECT, 2020
** Indie
** File description:
** main
*/

#include "GameObject.hpp"
#include "GameScene.hpp"
#include "GameSceneManager.hpp"
#include "Player.hpp"
#include "Introduction.hpp"
#include "TestGameScene.hpp"
#include "Menu.hpp"
#include "Settings.hpp"
#include "ChoosePlayers.hpp"
#include "Music.hpp"
#include "PauseMenu.hpp"
#include "PauseSettings.hpp"

int main(void)
{
    std::shared_ptr<IrrlichtController> c = std::make_shared<IrrlichtController>();
    c->Init(irr::video::E_DRIVER_TYPE::EDT_OPENGL, WIDTH, HEIGHT);

    std::shared_ptr<TestGameScene> testScene = std::make_shared<TestGameScene>(c, "gameScene");
    std::shared_ptr<Menu> menu = std::make_shared<Menu>(c, "menuScene");
    std::shared_ptr<Settings> set = std::make_shared<Settings>(c, "settingsScene");
    std::shared_ptr<ChoosePlayers> chooseP = std::make_shared<ChoosePlayers>(c, "chooseplayersScene");
    std::shared_ptr<Introduction> intro = std::make_shared<Introduction>(c, "introScene");
    std::shared_ptr<PauseMenu> pause = std::make_shared<PauseMenu>(c, "pauseScene");
    std::shared_ptr<PauseSettings> pauseSettings = std::make_shared<PauseSettings>(c, "pauseSettingsScene");

    GameSceneManager m(c);
    m.AddScene(testScene);
    m.AddScene(menu);
    m.AddScene(set);
    m.AddScene(chooseP);
    m.AddScene(intro);
    m.AddScene(pause);
    m.AddScene(pauseSettings);
    m.LoadScene("introScene");
    while (c->isRunning())
    {
        m.Update();
    }
    return 0;
}
