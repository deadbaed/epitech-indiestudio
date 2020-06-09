/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameObject(ctrl, name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
    _node = NULL;
}

void Player::Init(const std::string texture)
{
    _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(texture.c_str()));
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    //irr::scene::IAnimatedMesh *mesh = Device->getSceneManager()->getMesh("resources/models/Character/Bomberman.MD3");
}

void Player::SetPosition(irr::core::vector3df position)
{
    _position = position;
    if (_node)
        _node->setPosition(position);
}

Player::~Player()
{

}

void Player::Update()
{

}

void Player::Delete(void)
{
    _status = DELETED;
}
void Player::test(void)
{

}
