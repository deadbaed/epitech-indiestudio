/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** [enter description here]
*/

#include "blockMap.hpp"

BlockMap::BlockMap(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameObject(ctrl, name)
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
}

BlockMap::~BlockMap()
{

}

void BlockMap::Update()
{

}

void BlockMap::Delete(void)
{
    _status = DELETED;
}
void BlockMap::test(void)
{

}
