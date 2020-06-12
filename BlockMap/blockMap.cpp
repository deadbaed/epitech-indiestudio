/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** [enter description here]
*/

#include "blockMap.hpp"

BlockMap::BlockMap(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameObject(ctrl, irr::core::vector3df(5, 5, 5), name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
    _node = NULL;
}

void BlockMap::Init(IAnimatedMesh* &mesh)
{
    _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(mesh);
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMD2Animation(scene::EMAT_STAND);
}

void BlockMap::SetPosition(irr::core::vector3df position)
{
    _position = position;
    if (_node)
        _node->setPosition(position);
    _collider->SetPosition(position);
}

BlockMap::~BlockMap()
{

}

void BlockMap::Update(std::vector<std::shared_ptr<IGameObject>> &obj)
{

}

void BlockMap::Delete(void)
{
    _status = DELETED;
}

const IGameObject::type_e BlockMap::GetType(void)
{
    if (!_id.compare("border"))
        return IGameObject::type_e::BORDER;
    if (!_id.compare("wall"))
        return IGameObject::type_e::WALL;
    if (!_id.compare("block"))
        return IGameObject::type_e::DESTRUCTABLE_WALL;
    return IGameObject::type_e::GROUND;

}