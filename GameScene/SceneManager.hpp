/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include "AScene.hpp"

class SceneManager {
    public:
        SceneManager(const std::shared_ptr<IrrlichtController> &ctrl);
        void AddScene(const std::shared_ptr<AScene> &scene);
        void LoadScene(const std::string name);
        void Update(void);
        ~SceneManager();
    private:
        const std::shared_ptr<IrrlichtController> &_ctrl;
        std::vector<std::shared_ptr<AScene>> _scene_list;
        AScene *_current_scene;
};

#endif /* !SCENEMANAGER_HPP_ */
