/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** GameSceneManager
*/

#include "GameSceneManager.hpp"

GameSceneManager::GameSceneManager(const std::shared_ptr<IrrlichtController> &ctrl) : _ctrl(ctrl)
{
    _current_scene = NULL;
}

void GameSceneManager::AddScene(const std::shared_ptr<GameScene> &scene)
{
    _scene_list.push_back(scene);
}

void GameSceneManager::LoadScene(const std::string name)
{
    for (auto i = _scene_list.begin(); i != _scene_list.end(); i++) {
        if (i->get()->GetId() == name) {
            if (_current_scene) {
                if (_ctrl->_scene_mgr->getSceneLoaderCount() > 0)
                    _ctrl->_scene_mgr->clear();
            }
            _current_scene = i->get();
            _current_scene->Init();
        }
    }
}

void GameSceneManager::Update(void)
{
    GameScene *scene = _current_scene;
    if (scene == NULL)
        return;
    this->_ctrl->_music->Update();
    try {
        _ctrl->_driver->beginScene(true, true, scene->GetBackgroundColor());
        scene->Update();
        scene->Render();
        _ctrl->_driver->endScene ();
    } catch (const std::exception &e) {
        return;
    }
    if (this->_ctrl->_context.sceneName != _current_scene->GetId()) {
        this->_current_scene->Clear();
        LoadScene(this->_ctrl->_context.sceneName);
    }

}

GameSceneManager::~GameSceneManager()
{
}