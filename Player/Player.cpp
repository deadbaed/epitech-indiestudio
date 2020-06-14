/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** Player
*/

#include "Player.hpp"
#include "AssetSelector.hpp"

Player::Player(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameObject(ctrl, irr::core::vector3df(5, 5, 5), name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
    _node = NULL;
}

Player::Player(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name, BomberType type, KeyConfig conf): GameObject(ctrl, irr::core::vector3df(5, 5, 5), name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
    _node = NULL;
    _type = type;
    _conf = conf;
    _alive = true;
    _win = false;
    _pose = false;
    _dead = false;
    _nb = 0;
    _speed = SPEED;
    _no_collids = false;
    _collid = false;
}

void Player::Init()
{
    switch (this->_type) {
        case WHITE:
            _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(AssetSelector(WHITE_PATH).c_str()));
            break;
        case GREEN:
            _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(AssetSelector(GREEN_PATH).c_str()));
            break;
        case BLUE:
            _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(AssetSelector(BLUE_PATH).c_str()));
            break;
        case BLACK:
            _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(AssetSelector(BLACK_PATH).c_str()));
            break;
        default:
            _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(AssetSelector(WHITE_PATH).c_str()));
    }
    if (_node) {
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMD2Animation(scene::EMAT_STAND);
    }
    this->_old = this->_ctrl->_device->getTimer()->getTime();
    _node->setScale(irr::core::vector3df(2, 2, 2));
    _node->setAnimationSpeed(90);
}

void Player::Init(const std::string texture)
{
    _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(texture.c_str()));
    if (_node) {
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMD2Animation(scene::EMAT_STAND);
    }
    this->_old = this->_ctrl->_device->getTimer()->getTime();
}

void Player::Update(std::vector<std::shared_ptr<IGameObject>> &obj)
{
    /* Movements */
    _frameDeltaTime = this->GetTime();
    this->_old = this->_now;
    this->_obj = &obj;

    if (!_dead && !_pose) {
        if (this->_conf == KeyConfig::LEFT) {
            core::vector3df nodePosition = this->GetPosition();

            if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_Z)) {
                nodePosition.X -= _speed * _frameDeltaTime;
                this->setRotation(core::vector3df(0, 90, 0));
            } else if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_S)) {
                nodePosition.X += _speed * _frameDeltaTime;
                this->setRotation(core::vector3df(0, -90, 0));
            }
            if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_Q)) {
                nodePosition.Z -= _speed * _frameDeltaTime;
                this->setRotation(core::vector3df(0, 0, 0));
            } else if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_D)) {
                nodePosition.Z += _speed * _frameDeltaTime;
                this->setRotation(core::vector3df(0, 180, 0));
            }

            _collider->SetPosition(nodePosition);
            if (!calculateCollision())
                this->setPosition(nodePosition);
            else if (_no_collids && !calculateBorderCollisions())
                this->setPosition(nodePosition);

            if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_A)) {
                this->_win = true;
                this->_node->setCurrentFrame(WIN_BEGIN);
            }
            if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_E)) {
                this->_pose = true;
                this->_node->setCurrentFrame(POSE_BEGIN);
            }
        }

        if (this->_conf == KeyConfig::RIGHT) {
            core::vector3df nodePosition = this->GetPosition();

            if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_O)) {
                nodePosition.X -= _speed * _frameDeltaTime;
                this->setRotation(core::vector3df(0, 90, 0));
            } else if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_L)) {
                nodePosition.X += _speed * _frameDeltaTime;
                this->setRotation(core::vector3df(0, -90, 0));
            }
            if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_K)) {
                nodePosition.Z -= _speed * _frameDeltaTime;
                this->setRotation(core::vector3df(0, 0, 0));
            } else if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_M)) {
                nodePosition.Z += _speed * _frameDeltaTime;
                this->setRotation(core::vector3df(0, 180, 0));
            }
            _collider->SetPosition(nodePosition);
            if (!calculateCollision())
                this->setPosition(nodePosition);
            else if (_no_collids && !calculateBorderCollisions())
                this->setPosition(nodePosition);

            if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_I)) {
                this->_win = true;
                this->_node->setCurrentFrame(WIN_BEGIN);
            }
            if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_P)) {
                this->_pose = true;
                this->_node->setCurrentFrame(POSE_BEGIN);
            }
        }
        _collider->SetPosition(this->GetPosition());
    }
    if (this->_node)
        this->updateAnimations();
    if (this->_no_collids) {
        this->end = std::chrono::steady_clock::now();
        this->elapsed_seconds = end - start;
        if (this->elapsed_seconds.count() > NO_COLLID && !_collid) {
            this->_no_collids = false;
        }
    }
}

bool Player::calculateCollision()
{
    bool ret = false;

    for (auto i = _obj->cbegin(); i != _obj->cend(); i++) {
        if (i->get()->GetId() != _id && i->get()->GetType() == IGameObject::type_e::PWU_WALL_PASS) {
            if (GetCollider()->Collide(*i->get()->GetCollider())) {
                _no_collids = true;
                this->start = std::chrono::steady_clock::now();
                i->get()->SetStatus(IGameObject::status_e::DELETED);
            }
        }
        if (i->get()->GetId() != _id && i->get()->GetType() == IGameObject::type_e::PWU_SKATE) {
            if (GetCollider()->Collide(*i->get()->GetCollider())) {
                _speed += 1;
                i->get()->SetStatus(IGameObject::status_e::DELETED);
            }
        }
        if (i->get()->GetId() != _id && i->get()->GetType() != IGameObject::PLAYER && i->get()->GetType() != IGameObject::AI && i->get()->GetId().compare("ground") != 0 \
        && i->get()->GetType() != IGameObject::type_e::PWU_SKATE && i->get()->GetType() != IGameObject::type_e::PWU_WALL_PASS) {
            if (GetCollider()->Collide(*i->get()->GetCollider())) {
                ret = true;
            }
        }
    }
    _collid = ret;
    return (ret);
}

bool Player::calculateBorderCollisions()
{
    bool ret = false;

    for (auto i = _obj->cbegin(); i != _obj->cend(); i++) {
        if (i->get()->GetId() != _id && i->get()->GetType() == IGameObject::type_e::BORDER) {
            if (GetCollider()->Collide(*i->get()->GetCollider())) {
                ret = true;
            }
        }
    }
    return (ret);
}

void Player::Delete()
{
    _dead = true;
    this->_node->setCurrentFrame(DEAD_BEGIN);
}

void Player::updateAnimations()
{
    if (!_win && !_pose && !_dead)
        this->_node->setCurrentFrame(BEGIN);
    if (this->_win && !_dead)
        this->animationWin();
    if (this->_pose && !_dead)
        this->animationPose();
    if (this->_dead)
        this->animationDead();
}

void Player::animationWin()
{
    if (this->_node->getFrameNr() > WIN_END) {
        this->_node->setCurrentFrame(WIN_BEGIN);
        this->_win = false;
    }
}

void Player::animationPose()
{
    if (this->_node->getFrameNr() > POSE_END) {
        this->_node->setCurrentFrame(POSE_BEGIN);
        this->_pose = false;
        poseBomb();
    }
}

void Player::animationDead()
{
    if (this->_node->getFrameNr() > DEAD_END) {
        this->_node->setCurrentFrame(DEAD_BEGIN);
        //this->_dead = false;
    }
}

f32 Player::GetTime()
{
    this->_now = this->_ctrl->_device->getTimer()->getTime();
    return ((f32)(this->_now - this->_old) / 1000.f);
}

void Player::setPosition(irr::core::vector3df const position)
{
    this->SetPosition(position);
    if (_node)
        _node->setPosition((position));
    _collider->SetPosition(position);
}

void Player::setRotation(irr::core::vector3df const rotation)
{
    this->SetRotation(rotation);
    _node->setRotation(rotation);
}

void Player::poseBomb()
{
    std::shared_ptr<Bomb> bomb = std::make_unique<Bomb>(this->_ctrl, "bomb_" + std::to_string(_nb));

    _nb++;
    bomb->Init();
    vector3df vect = this->GetPosition();
    vector3df pos_bomb;
    std::unique_ptr<Collider> tmp = std::make_unique<Collider>(vect, 1, 1, 1);
    for (auto i = _obj->cbegin(); i != _obj->cend(); i++) {
        if (i->get()->GetId() != _id && i->get()->GetType() == IGameObject::type_e::GROUND) {
            if (tmp->Collide(*i->get()->GetCollider())) {
                pos_bomb = i->get()->GetPosition();
                bomb->setPosition(pos_bomb);
                _obj->push_back(bomb);
            }
        }
    }
}

const IGameObject::type_e Player::GetType(void)
{
    return IGameObject::type_e::PLAYER;
}