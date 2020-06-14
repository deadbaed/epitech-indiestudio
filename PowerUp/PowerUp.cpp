/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** [enter description here]
*/

#include "PowerUp.hpp"
#include "AssetSelector.hpp"

PowerUp::PowerUp(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameObject(ctrl, irr::core::vector3df(5, 5, 5), name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
    _node = NULL;
}

void PowerUp::Init(void)
{
    if (_id.compare("skate")) {
        _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(AssetSelector(SKATE).c_str()));
    } else {
        _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(AssetSelector(SKATE).c_str()));
    }
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _node->setMD2Animation(scene::EMAT_STAND);
}

void PowerUp::SetPosition(irr::core::vector3df position)
{
    _position = position;
    if (_node)
        _node->setPosition(position);
    _collider->SetPosition(position);
}

PowerUp::~PowerUp()
{

}

void PowerUp::Update(std::vector<std::shared_ptr<IGameObject>> &obj)
{

}

void PowerUp::Delete(void)
{
    if (this->_node) {
        this->_node->remove();
        this->_node = NULL;
    }
}

const IGameObject::type_e PowerUp::GetType(void)
{
    if (_id.compare("skate") == 0)
        return IGameObject::type_e::PWU_SKATE;
    if (_id.compare("wall_pass") == 0)
        return IGameObject::type_e::PWU_WALL_PASS;
    return IGameObject::type_e::BONUS;
}
