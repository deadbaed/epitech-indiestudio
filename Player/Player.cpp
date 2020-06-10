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

Player::Player(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name, BomberType type, KeyConfig conf): GameObject(ctrl, name)
{
    _position = irr::core::vector3df(0, 0, 0);
    _rotation = irr::core::vector3df(0, 0, 0);
    _node = NULL;
    _type = type;
    _conf = conf;
    _alive = true;
}

void Player::Init()
{
    switch (this->_type) {
        case WHITE:
            _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(WHITE_PATH));
            break;
        case GREEN:
            _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(BLUE_PATH));
            break;
        case BLUE:
            _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(GREEN_PATH));
            break;
        case BLACK:
            _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(BLACK_PATH));
            break;
        default:
            _node = _ctrl->_scene_mgr->addAnimatedMeshSceneNode(_ctrl->_scene_mgr->getMesh(WHITE_PATH));
    }
    if (_node) {
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMD2Animation(scene::EMAT_STAND);
    }
    this->_old = this->_ctrl->_device->getTimer()->getTime();
    _node->setScale(irr::core::vector3df(2, 2, 2));
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

void Player::Update()
{
    /* Movements */
    _frameDeltaTime = this->GetTime();
    this->_old = this->_now;

    if (this->_conf == KeyConfig::LEFT) {
        core::vector3df nodePosition = this->GetPosition();

        if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_Z))
            nodePosition.X -= SPEED * _frameDeltaTime;
        else if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_S))
            nodePosition.X += SPEED * _frameDeltaTime;
        if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_Q))
            nodePosition.Z += SPEED * _frameDeltaTime;
        else if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_D))
            nodePosition.Z -= SPEED * _frameDeltaTime;
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

        if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_O))
            nodePosition.X -= SPEED * _frameDeltaTime;
        else if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_L))
            nodePosition.X += SPEED * _frameDeltaTime;
        if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_K))
            nodePosition.Z += SPEED * _frameDeltaTime;
        else if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_KEY_M))
            nodePosition.Z -= SPEED * _frameDeltaTime;
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
    /*
    if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_SPACE)) {
        this->_dead = true;
        this->_node->setCurrentFrame(DEAD_BEGIN);
    }
     */
    this->updateAnimations();
}

void Player::Delete()
{
    _status = DELETED;
}

void Player::updateAnimations()
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
    }
}

void Player::animationDead()
{
    if (this->_node->getFrameNr() > DEAD_END) {
        this->_node->setCurrentFrame(DEAD_BEGIN);
        this->_dead = false;
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
    _node->setPosition((position));
}