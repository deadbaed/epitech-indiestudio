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

void BlockMap::Init()
{
    std::string path = "../assets/wall_2.obj";

    if (GetType() == IGameObject::type_e::GROUND)
        path = "../assets/floor.obj";
    if (GetType() == IGameObject::type_e::DESTRUCTABLE_WALL)
        path = "../assets/wall_2.obj";
    if (GetType() == IGameObject::type_e::WALL)
        path = "../assets/wall_1.obj";
    if (GetType() == IGameObject::type_e::BORDER)
        path = "../assets/wall_1.obj";
    _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(path.c_str()));
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMD2Animation(scene::EMAT_STAND);
    _node->setPosition(GetPosition());

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
    if (this->_node) {
        this->_node->remove();
        this->_node = NULL;
    }
    //_status = DELETED;
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