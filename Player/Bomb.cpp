/*
** EPITECH PROJECT, 2020
** Indie Studio
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "AssetSelector.hpp"
#include <memory>

Bomb::Bomb(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameObject(ctrl, irr::core::vector3df(0, 0, 0), name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
    _node = NULL;
    this->_particles = std::make_unique<Particles>(this->_ctrl, this->setParticle());
    this->_upperExplosion = std::make_unique<Particles>(this->_ctrl, this->setExplosions(core::vector3df(-0.03f,0.0f,0.0f)));
    this->_downExplosion = std::make_unique<Particles>(this->_ctrl, this->setExplosions(core::vector3df(0.03f,0.0f,0.0f)));
    this->_leftExplosion = std::make_unique<Particles>(this->_ctrl, this->setExplosions(core::vector3df(0.0f,0.0f,-0.03f)));
    this->_rightExplosion = std::make_unique<Particles>(this->_ctrl, this->setExplosions(core::vector3df(0.0f,0.0f,0.03f)));
    this->_boom = false;
}

void Bomb::Init()
{
    _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(AssetSelector(BOMB_PATH).c_str()));
    if (_node) {
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMD2Animation(scene::EMAT_STAND);
    }
    _node->setScale(irr::core::vector3df((float)3.3, (float)3.3, (float)3.3));
    this->start = std::chrono::steady_clock::now();
    this->_particles->Init();
}

Particles::ParticleSetting_t Bomb::setExplosions(core::vector3df direction)
{
    Particles::ParticleSetting_t tmp = {
            core::aabbox3d<f32>(-1.5,0,-0.5,1.5,1.5,1.5),
            direction,
            600,
            800,
            500,
            600,
            core::dimension2d<f32>(2.0f, 2.0f),
            core::dimension2d<f32>(4.0f, 4.0f),
    };
    return (tmp);
}

Particles::ParticleSetting_t Bomb::setParticle()
{
    Particles::ParticleSetting_t tmp = {
            core::aabbox3d<f32>(-0.5,0.5,-0.5,0.5,1,0.5),
            core::vector3df(0.0f,0.03f,0.0f),
            80,
            200,
            100,
            350,
            core::dimension2d<f32>(2.0f, 2.0f),
            core::dimension2d<f32>(2.0f, 2.0f),
    };
    return (tmp);
}
void Bomb::Update(std::vector<std::shared_ptr<IGameObject>> &obj)
{
    this->end = std::chrono::steady_clock::now();
    this->elapsed_seconds = end - start;
    this->_obj = &obj;
    if (this->_boom == false ) {
        if (this->elapsed_seconds.count() > TIME_BOMB) {
            explosion();
            this->_boom = true;
            this->start = std::chrono::steady_clock::now();
        }
    } else if (this->_boom) {
        if (this->elapsed_seconds.count() > TIME_ALIVE) {
            SetStatus(IGameObject::status_e::DELETED);
        }
    }
}

bool Bomb::calculateCollision(irr::core::vector3df position)
{
    std::unique_ptr<Collider> tmp = std::make_unique<Collider>(position, 5, 5, 5);
    bool ret = false;

    for (auto i = _obj->begin(); i != _obj->end(); i++) {

        if (i->get()->GetId() != _id && i->get()->GetType() == IGameObject::type_e::PLAYER) {
            if (tmp->Collide(*i->get()->GetCollider())) {
                i->get()->SetStatus(IGameObject::status_e::DELETED);
            }
        }

        if (i->get()->GetId() != _id && i->get()->GetType() == IGameObject::type_e::DESTRUCTABLE_WALL) {
            if (tmp->Collide(*i->get()->GetCollider())) {
                i->get()->SetStatus(IGameObject::status_e::DELETED);
            }
        }

        if (i->get()->GetId() != _id && i->get()->GetType() != IGameObject::type_e::PLAYER && i->get()->GetType() != IGameObject::type_e::DESTRUCTABLE_WALL && i->get()->GetType() != IGameObject::type_e::GROUND) {
            if (tmp->Collide(*i->get()->GetCollider())) {
                ret = true;
            }
        }
    }
    return (ret);
}

void Bomb::explosion()
{
    irr::core::vector3df pos = this->GetPosition();

    this->_particles->clear();
    if (!calculateCollision(vector3df(pos.X - 6, pos.Y, pos.Z)))
        this->_upperExplosion->Init();
    if (!calculateCollision(vector3df(pos.X + 6, pos.Y, pos.Z)))
        this->_downExplosion->Init();
    if (!calculateCollision(vector3df(pos.X, pos.Y, pos.Z - 6)))
        this->_leftExplosion->Init();
    if (!calculateCollision(vector3df(pos.X, pos.Y, pos.Z + 6)))
        this->_rightExplosion->Init();
}

void Bomb::Delete()
{
    this->_particles->Delete();
    this->_upperExplosion->Delete();
    this->_downExplosion->Delete();
    this->_rightExplosion->Delete();
    this->_leftExplosion->Delete();
    if (this->_node) {
        this->_node->remove();
        this->_node = NULL;
    }
}

void Bomb::setPosition(irr::core::vector3df const position)
{
    this->SetPosition(position);
    _node->setPosition((position));
    _particles->setPosition(position);
    _upperExplosion->setPosition(position);
    _downExplosion->setPosition(position);
    _leftExplosion->setPosition(position);
    _rightExplosion->setPosition(position);
    _collider->SetPosition(position);
}
const IGameObject::type_e Bomb::GetType(void)
{
    return IGameObject::type_e::BOMB;
}