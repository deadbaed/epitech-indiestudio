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
            _current_scene = i->get();
            _current_scene->Init();
        }
    }
}

void GameSceneManager::Update(void)
{
    if (_current_scene == NULL)
        return;
    _ctrl->_driver->beginScene(true, true, irr::video::SColor(0,156,156,156));
    _current_scene->Update();
    _current_scene->Render();
    _ctrl->_driver->endScene ();
}

GameSceneManager::~GameSceneManager()
{
}