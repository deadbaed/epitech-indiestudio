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
#include "EndScene.hpp"
#include <exception>

/* Win32: Remove the console application */
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(void) {

    std::shared_ptr<IrrlichtController> c;
    std::shared_ptr<Menu> menu;
    std::shared_ptr<Settings> set;
    std::shared_ptr<ChoosePlayers> chooseP;
    std::shared_ptr<SelectSkin> selectSkin;
    std::shared_ptr<SelectSkins> selectSkins;
    std::shared_ptr<Introduction> intro;
    std::shared_ptr<PauseMenu> pause;
    std::shared_ptr<PauseSettings> pauseSettings;
    std::shared_ptr<EndScene> endScene;
    std::shared_ptr<GameScene> testScene;
    try {
        c = std::make_shared<IrrlichtController>();
        c->Init(irr::video::E_DRIVER_TYPE::EDT_OPENGL, WIDTH, HEIGHT);
        c->_device->setWindowCaption(L"Indie Studio");
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    SceneManager m(c);
    try {
        menu = std::make_shared<Menu>(c, "menuScene");
        set = std::make_shared<Settings>(c, "settingsScene");
        chooseP = std::make_shared<ChoosePlayers>(c, "chooseplayersScene");
        selectSkin = std::make_shared<SelectSkin>(c, "skinScene");
        selectSkins = std::make_shared<SelectSkins>(c, "skinsScene");
        intro = std::make_shared<Introduction>(c, "introScene");
        pause = std::make_shared<PauseMenu>(c, "pauseScene");
        pauseSettings = std::make_shared<PauseSettings>(c, "pauseSettingsScene");
        endScene = std::make_shared<EndScene>(c, "endScene");
        testScene = std::make_shared<GameScene>(c, "gameScene");
        m.AddScene(menu);
        m.AddScene(set);
        m.AddScene(chooseP);
        m.AddScene(intro);
        m.AddScene(pause);
        m.AddScene(pauseSettings);
        m.AddScene(selectSkin);
        m.AddScene(selectSkins);
        m.AddScene(endScene);
        m.AddScene(testScene);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    try {
        m.LoadScene("introScene");
        while (c->isRunning())
            m.Update();
        c->SaveConfig();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return 0;
}
