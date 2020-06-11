/*
** EPITECH PROJECT, 2020
** Indie Studio
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomb::Bomb(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameObject(ctrl, irr::core::vector3df(1, 1, 1), name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
    _node = NULL;
}

void Bomb::Init()
{
    _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(BOMB_PATH));
    if (_node) {
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMD2Animation(scene::EMAT_STAND);
    }
}

void Bomb::Update(std::vector<std::shared_ptr<IGameObject>> obj)
{

}

void Bomb::Delete()
{
    _status = DELETED;
}

void Bomb::setPosition(irr::core::vector3df const position)
{
    this->SetPosition(position);
    _node->setPosition((position));
    _collider->SetPosition(position);
}