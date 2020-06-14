/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** Player
*/

#include "AI.hpp"
#include "AssetSelector.hpp"

AI::AI(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name): GameObject(ctrl, irr::core::vector3df(5, 5, 5), name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
    _node = NULL;
    _alive = true;
    _win = false;
    _pose = false;
    _dead = false;
    _nb = 0;
    _direction = AI::direction_e::IDLE;
}

void AI::Init()
{
    _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(AssetSelector(WHITE_PATH).c_str()));

    if (_node) {
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMD2Animation(scene::EMAT_STAND);
    }
    this->_old = this->_ctrl->_device->getTimer()->getTime();
    _node->setScale(irr::core::vector3df(2, 2, 2));
}

void AI::Update(std::vector<std::shared_ptr<IGameObject>> &obj)
{
    /* Movements */
    _frameDeltaTime = this->GetTime();
    this->_old = this->_now;
    this->_obj = &obj;
    UpdateDirection();
    core::vector3df nodePosition = this->GetPosition();

    if (_direction == AI::direction_e::UP) {
        nodePosition.X -= SPEED * _frameDeltaTime;
        this->setRotation(core::vector3df(0, 90, 0));
    } else if (_direction == AI::direction_e::UP) {
        nodePosition.X += SPEED * _frameDeltaTime;
        this->setRotation(core::vector3df(0, -90, 0));
    }
    if (_direction == AI::direction_e::LEFT) {
        nodePosition.Z -= SPEED * _frameDeltaTime;
        this->setRotation(core::vector3df(0, 0, 0));
    } else if (_direction == AI::direction_e::RIGHT) {
        nodePosition.Z += SPEED * _frameDeltaTime;
        this->setRotation(core::vector3df(0, 180, 0));
    }
    _collider->SetPosition(nodePosition);
    if (!calculateCollision())
        this->setPosition(nodePosition);
    _collider->SetPosition(this->GetPosition());
    _node->setAnimationSpeed(90);
    this->updateAnimations();
}

bool AI::calculateCollision()
{
    for (auto i = _obj->cbegin(); i != _obj->cend(); i++) {
        if (i->get()->GetId() != _id && i->get()->GetId().compare("p1") != 0 && i->get()->GetId().compare("p2") != 0 && i->get()->GetId().compare("ground") != 0) {
            if (GetCollider()->Collide(*i->get()->GetCollider())) {
                return (true);
            }
        }
    }
    return (false);
}

void AI::Delete()
{
    _dead = true;
    _status = DELETED;
    this->_node->remove();
}

void AI::updateAnimations()
{
    if (!_win && !_pose && !_dead)
        this->_node->setCurrentFrame(BEGIN);
    if (this->_win)
        this->animationWin();
    if (this->_pose)
        this->animationPose();
    if (this->_dead)
        this->animationDead();
}

void AI::UpdateDirection(void)
{
    _direction = AI::direction_e::RIGHT;
}

void AI::animationWin()
{
    if (this->_node->getFrameNr() > WIN_END) {
        this->_node->setCurrentFrame(WIN_BEGIN);
        this->_win = false;
    }
}

void AI::animationPose()
{
    if (this->_node->getFrameNr() > POSE_END) {
        this->_node->setCurrentFrame(POSE_BEGIN);
        this->_pose = false;
        poseBomb();
    }
}

void AI::animationDead()
{
    if (this->_node->getFrameNr() > DEAD_END) {
        this->_node->setCurrentFrame(DEAD_BEGIN);
        this->_dead = false;
    }
}

f32 AI::GetTime()
{
    this->_now = this->_ctrl->_device->getTimer()->getTime();
    return ((f32)(this->_now - this->_old) / 1000.f);
}

void AI::setPosition(irr::core::vector3df const position)
{
    this->SetPosition(position);
    _node->setPosition((position));
    _collider->SetPosition(position);
}

void AI::setRotation(irr::core::vector3df const rotation)
{
    this->SetRotation(rotation);
    _node->setRotation(rotation);
}

void AI::poseBomb()
{
    std::shared_ptr<Bomb> bomb = std::make_unique<Bomb>(this->_ctrl, "bomb_" + std::to_string(_nb));

    _nb++;
    bomb->Init();
    vector3df vect = this->GetPosition(); // add a +1
    bomb->setPosition(vect);
    _obj->push_back(bomb);
}
const IGameObject::type_e AI::GetType(void)
{
    return IGameObject::type_e::AI;
}