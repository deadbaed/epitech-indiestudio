/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

SceneManager::SceneManager(const std::shared_ptr<IrrlichtController> &ctrl) : _ctrl(ctrl)
{
    _current_scene = NULL;
}

void SceneManager::AddScene(const std::shared_ptr<AScene> &scene)
{
    _scene_list.push_back(scene);
}

void SceneManager::LoadScene(const std::string name)
{
    for (auto i = _scene_list.begin(); i != _scene_list.end(); i++) {
        if (i->get()->GetId() == name) {
            if (_current_scene) {
                if (_ctrl->_scene_mgr->getSceneLoaderCount() > 0) {
                        std::cout << "name " << name << std::endl;
                        std::cout << _current_scene->GetId() << std::endl;
//                    if (_current_scene->GetId() != "gameScene" && name != "pauseScene" || _current_scene->GetId() != "pauseScene" && name != "gameScene") {
//                        _ctrl->_scene_mgr->clear();
                        _ctrl->_scene_mgr->clear();
                        _ctrl->_env->clear();
//                    }
                }
            }
            _current_scene = i->get();
            _current_scene->Init();
            _ctrl->_context.sceneName = _current_scene->GetId();
        }
    }
}

void SceneManager::Update(void)
{
    AScene *scene = _current_scene;
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

SceneManager::~SceneManager()
{
}