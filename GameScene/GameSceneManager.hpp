/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** GameSceneManager
*/

#ifndef GAMESCENEMANAGER_HPP_
#define GAMESCENEMANAGER_HPP_

#include "GameScene.hpp"

class GameSceneManager {
    public:
        GameSceneManager(const std::shared_ptr<IrrlichtController> &ctrl);
        void AddScene(const std::shared_ptr<GameScene> &scene);
        void LoadScene(const std::string name);
        void Update(void);
        ~GameSceneManager();
    private:
        const std::shared_ptr<IrrlichtController> &_ctrl;
        std::vector<std::shared_ptr<GameScene>> _scene_list;
        GameScene *_current_scene;
};

#endif /* !GAMESCENEMANAGER_HPP_ */
