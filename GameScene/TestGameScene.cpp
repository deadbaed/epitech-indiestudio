/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** TestGameScene
*/

#include "TestGameScene.hpp"
#include "Player.hpp"

TestGameScene::TestGameScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : GameScene(ctrl, name)
{

}

void TestGameScene::Init(void)
{
    irr::SKeyMap keyMap[5];                             // re-assigne les commandes
    keyMap[0].Action = irr::EKA_MOVE_FORWARD;           // avancer
    keyMap[0].KeyCode = irr::KEY_KEY_Z;                 // w
    keyMap[1].Action = irr::EKA_MOVE_BACKWARD;          // reculer
    keyMap[1].KeyCode = irr::KEY_KEY_S;                 // s
    keyMap[2].Action = irr::EKA_STRAFE_LEFT;            // a gauche
    keyMap[2].KeyCode = irr::KEY_KEY_Q;                 // a
    keyMap[3].Action = irr::EKA_STRAFE_RIGHT;           // a droite
    keyMap[3].KeyCode = irr::KEY_KEY_D;                 // d
    keyMap[4].Action = irr::EKA_JUMP_UP;                // saut
    keyMap[4].KeyCode = irr::KEY_SPACE;

    _ctrl->_scene_mgr->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, keyMap, 5);
    irr::scene::ICameraSceneNode *camera = _ctrl->_scene_mgr->getActiveCamera();
    camera->setPosition(irr::core::vector3df(0, 45, 0));
    camera->setRotation(irr::core::vector3df(90, 180, 0));
    std::shared_ptr<Player> p = std::make_shared<Player>(_ctrl, "p1");
    std::shared_ptr<Player> p2 = std::make_shared<Player>(_ctrl, "p2");
    p->Init("../assets/player_1.obj");
    p2->Init("../assets/player_2.obj");
    p->SetPosition(irr::core::vector3df(0, 0, 0));
    p2->SetPosition(irr::core::vector3df(30, 0, 0));

    AddGameObject(p);
    AddGameObject(p2);
    this->_ctrl->_music->Play("../assets/music_game.ogg");
}

TestGameScene::~TestGameScene()
{

}
