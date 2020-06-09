/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** AGameObject
*/

#include <irrlicht.h>
#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : _ctrl(ctrl), _id(name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
}

GameObject::~GameObject()
{

}

void GameObject::Init(void)
{

}

void GameObject::Update(void)
{

}

void GameObject::Render(void)
{

}

void GameObject::Delete(void)
{
    _status = IGameObject::STATUS::DELETED;
}

GameObject &GameObject::operator=(const GameObject &obj)
{
    return *this;
}

const std::string &GameObject::GetId(void)
{
    return _id;
}

bool GameObject::operator==(const GameObject &obj)
{
    if (_id == obj._id)
        return true;
    return false;
}

void GameObject::SetPosition(irr::core::vector3df position)
{
    _position = position;
}

irr::core::vector3df GameObject::GetPosition(void)
{
    return _position;
}

void GameObject::SetRotation(irr::core::vector3df rotation)
{
    _rotation = rotation;
}

irr::core::vector3df GameObject::GetRotation(void)
{
    return _rotation;
}

IGameObject::STATUS &GameObject::GetStatus(void)
{
    return _status;
}