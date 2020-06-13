/*
** EPITECH PROJECT, 2020
** Indie
** File description:
** main
*/

#include "GameObject.hpp"
#include "AScene.hpp"
#include "SceneManager.hpp"
#include "Introduction.hpp"
#include "GameScene.hpp"
#include "Menu.hpp"
#include "Settings.hpp"
#include "ChoosePlayers.hpp"
#include "PauseMenu.hpp"
#include "PauseSettings.hpp"
#include "SelectSkin.hpp"
#include "SelectSkins.hpp"

/* Win32: Remove the console application */
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(void) {
    std::shared_ptr<IrrlichtController> c = std::make_shared<IrrlichtController>();
    c->Init(irr::video::E_DRIVER_TYPE::EDT_OPENGL, WIDTH, HEIGHT);
    c->_device->setWindowCaption(L"Indie Studio");

    std::shared_ptr<GameScene> testScene = std::make_shared<GameScene>(c, "gameScene");
    std::shared_ptr<Menu> menu = std::make_shared<Menu>(c, "menuScene");
    std::shared_ptr<Settings> set = std::make_shared<Settings>(c, "settingsScene");
    std::shared_ptr<ChoosePlayers> chooseP = std::make_shared<ChoosePlayers>(c, "chooseplayersScene");
    std::shared_ptr<SelectSkin> selectSkin = std::make_shared<SelectSkin>(c, "skinScene");
    std::shared_ptr<SelectSkins> selectSkins = std::make_shared<SelectSkins>(c, "skinsScene");
    std::shared_ptr<Introduction> intro = std::make_shared<Introduction>(c, "introScene");
    std::shared_ptr<PauseMenu> pause = std::make_shared<PauseMenu>(c, "pauseScene");
    std::shared_ptr<PauseSettings> pauseSettings = std::make_shared<PauseSettings>(c, "pauseSettingsScene");

    SceneManager m(c);
    m.AddScene(testScene);
    m.AddScene(menu);
    m.AddScene(set);
    m.AddScene(chooseP);
    m.AddScene(intro);
    m.AddScene(pause);
    m.AddScene(pauseSettings);
    m.AddScene(selectSkin);
    m.AddScene(selectSkins);
    m.LoadScene("introScene");
    while (c->isRunning())
        m.Update();

    c->SaveConfig();
    return 0;
}
