/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** AGameObject
*/

#include <irrlicht.h>
#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(const std::shared_ptr<IrrlichtController> &ctrl, irr::core::vector3df dimension,  std::string name) : _ctrl(ctrl), _id(name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
    _collider = std::make_shared<Collider>(_position, dimension.X, dimension.Y, dimension.Z);
    _status = IGameObject::OK;
}

GameObject::~GameObject()
{

}

void GameObject::Init(void)
{

}

void GameObject::Update(std::vector<std::shared_ptr<IGameObject>> &obj)
{

}

void GameObject::Render(void)
{

}

void GameObject::Delete(void)
{
    _status = IGameObject::status_e::DELETED;
}

Collider *GameObject::GetCollider(void)
{
    return _collider.get();
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
    _collider->SetPosition(position);
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

IGameObject::status_e &GameObject::GetStatus(void)
{
    return _status;
}

const IGameObject::type_e GameObject::GetType(void)
{
    return IGameObject::type_e::GAME_OBJECT;
}

void GameObject::SetStatus(IGameObject::status_e status)
{
    _status = status;
}