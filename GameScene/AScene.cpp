/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** AScene
*/

#include "AScene.hpp"
#include "AssetSelector.hpp"
#include <iostream>

AScene::AScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : _id(name), _ctrl(ctrl)
{
    this->_background = this->_ctrl->_driver->getTexture(AssetSelector(FD_GAME_ASSET).c_str());
}

AScene::~AScene()
{

}

void AScene::Init(void)
{
    irr::SKeyMap keyMap[5];                             // re-assigne les commandes
    keyMap[0].Action = irr::EKA_MOVE_FORWARD;           // avancer
    keyMap[0].KeyCode = irr::KEY_KEY_Z;                 // w
    keyMap[1].Action = irr::EKA_MOVE_BACKWARD;          // reculer
    keyMap[1].KeyCode = irr::KEY_KEY_S;                 // s
    keyMap[2].Action = irr::EKA_STRAFE_LEFT;            // a gauche
    keyMap[2].KeyCode = irr::KEY_KEY_Q;                 // a
    keyMap[3].Action = irr::EKA_STRAFE_RIGHT;           // a droite
    keyMap[3].KeyCode = irr::KEY_KEY_D;                 // d
    keyMap[4].Action = irr::EKA_JUMP_UP;                // saut
    keyMap[4].KeyCode = irr::KEY_SPACE;

    _ctrl->_scene_mgr->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, keyMap, 5);
    irr::scene::ICameraSceneNode *camera = _ctrl->_scene_mgr->getActiveCamera();
    camera->setPosition(irr::core::vector3df(0, 45, 0));
    camera->setRotation(irr::core::vector3df(90, 180, 0));
}

void AScene::AddGameObject(const std::shared_ptr<IGameObject> &obj)
{
    _obj_list.push_back(obj);
}

void AScene::Update(void)
{
    int idx = 0;

    _ctrl->_driver->beginScene(true, true, SColor(100, 150, 150, 150));
    for (auto i = _obj_list.begin(); i != _obj_list.end(); i++) {
        if (i->get()->GetStatus() == IGameObject::status_e::DELETED) {
            i->get()->Delete();
            _obj_list.erase(i);
        }
        if (i == _obj_list.end())
            break;
    }

    if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_ESCAPE)) {
        this->_ctrl->_context.sceneName = "pauseScene";
    }

    for (auto i = _obj_list.begin(); i != _obj_list.end(); i++) {
        if (i->get()->GetStatus() != IGameObject::status_e::DELETED)
            i->get()->Update(_obj_list);
    }
}

void AScene::Render(void)
{
    _ctrl->_driver->draw2DImage(_background, core::position2d<s32>(0,0), core::rect<s32>(0,0,1280,720), 0, video::SColor(255,255,255,255), true);
    for (auto i = _obj_list.begin(); i != _obj_list.end(); i++)
        if (i->get()->GetStatus() != IGameObject::status_e::DELETED)
            i->get()->Render();
    _ctrl->_scene_mgr->drawAll();
}

void AScene::Clear(void)
{

}

IGameObject *AScene::GetGameObject(std::string id)
{
    for (auto i = _obj_list.begin(); i != _obj_list.end(); i++) {
        if (i->get()->GetId() == id)
            return i->get();
    }
    return nullptr;
}

const std::string &AScene::GetId(void)
{
    return _id;
}

const irr::video::SColor &AScene::GetBackgroundColor(void)
{
    return _background_color;
}

void AScene::SetBackgroundColor(const irr::video::SColor color)
{
    _background_color = color;
}
