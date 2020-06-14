/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** GameScene
*/

#include "GameScene.hpp"
#include "Player.hpp"
#include "MapGenerator.hpp"
#include "AssetSelector.hpp"
#include <iostream>

GameScene::GameScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{

}

GameScene::~GameScene()
{

}

std::shared_ptr<IGameObject> GameScene::initPowerUp(irr::core::vector3df pos, const std::string name)
{
    std::shared_ptr<PowerUp> power_up = std::make_shared<PowerUp>(_ctrl, name);
    power_up->Init();
    power_up->SetPosition(pos);
    return power_up;
}

void GameScene::addPowerUp(unsigned int prob)
{
    std::random_device dev;
    std::mt19937 _prob(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(1,100);
    std::uniform_int_distribution<std::mt19937::result_type> distribution_2(1, 2);
    std::vector<std::shared_ptr<IGameObject>>::iterator ptr;

    for (ptr = _obj_list.begin(); ptr < _obj_list.end(); ptr++)
        if (ptr->get()->GetType() == IGameObject::type_e::GROUND || ptr->get()->GetType() == IGameObject::type_e::DESTRUCTABLE_WALL)
            if (distribution(_prob) <= prob) {
                if (distribution_2(_prob) == 1)
                    _obj_list.push_back(initPowerUp(ptr->get()->GetPosition(), "skate"));
                else
                   _obj_list.push_back(initPowerUp(ptr->get()->GetPosition(), "wall_pass"));
            }
}

void GameScene::Init(void)
{
    if (this->_ctrl->_context.clear_obj) {
        _obj_list.clear();
        this->_ctrl->_context.clear_obj = false;
        this->player_one_set = false;
        this->map_set = false;
        this->player_two_set = false;
        this->end = false;
        this->_winner = 1;
    }
    for (auto i = _obj_list.cbegin(); i != _obj_list.cend(); i++) {
        if (i->get()->GetType() == IGameObject::type_e::BORDER) {
            i->get()->Init();
            map_set = true;
        }
        if (i->get()->GetType() == IGameObject::type_e::DESTRUCTABLE_WALL) {
            i->get()->Init();
            map_set = true;
        }
        if (i->get()->GetType() == IGameObject::type_e::WALL) {
            i->get()->Init();
            map_set = true;
        }
        if (i->get()->GetType() == IGameObject::type_e::GROUND) {
            i->get()->Init();
            map_set = true;
        }
        if (i->get()->GetId().compare("p1") == 0){
            i->get()->Init();
            player_one_set = true;
        }
        if (i->get()->GetId().compare("p2") == 0){
            i->get()->Init();
            player_two_set = true;
        }
    }

    /* Camera */
    _ctrl->_scene_mgr->addCameraSceneNode(0, vector3df(30, 57 , 24), vector3df(10, -300, 24));
    irr::scene::ICameraSceneNode *camera = _ctrl->_scene_mgr->getActiveCamera();
    camera->setPosition(irr::core::vector3df(30, 57, 24));

    /* Map */
    if (!map_set) {
        std::shared_ptr<mapGenerator> map = std::make_shared<mapGenerator>(vector3df(0, 0, 0), (float) 6, 11, 11);
        map->generate(_ctrl, _obj_list, AssetSelector(FLOOR_ASSET).string(), 100);
        map->generateWall(_ctrl, _obj_list, AssetSelector(WALL1_ASSET).string());
        map->generateBorder(_ctrl, _obj_list, AssetSelector(WALL1_ASSET).string());
        map->generateBlock(_ctrl, _obj_list, AssetSelector(WALL2_ASSET).string(), 30);
    }
    addPowerUp(100);

    /* Music */
    this->_ctrl->_music->Play(AssetSelector(MUSIC_GAME).string());

    if (!player_one_set) {
        std::shared_ptr<Player> p = std::make_shared<Player>(_ctrl, "p1",
                                                             (Player::BomberType) this->_ctrl->_context.skin_player_one,
                                                             Player::LEFT);
        p->SetPosition(irr::core::vector3df(0, 0, 0));
        p->Init();
        AddGameObject(p);
    }
    if (this->_ctrl->_context.nb_player > 1 && !player_two_set) {
        std::shared_ptr<Player> p2 = std::make_shared<Player>(_ctrl, "p2",(Player::BomberType) this->_ctrl->_context.skin_player_two,Player::RIGHT);
        p2->SetPosition(irr::core::vector3df(48, 0, 48));
        p2->Init();
        AddGameObject(p2);
    }
}

void GameScene::Update(void)
{
    int idx = 0;
    int players = 0;

    _ctrl->_driver->beginScene(true, true, SColor(100, 150, 150, 150));
    for (auto i = _obj_list.begin(); i != _obj_list.end(); i++) {
        if (i->get()->GetStatus() == IGameObject::status_e::DELETED) {
            i->get()->Delete();
            _obj_list.erase(i);
            i = _obj_list.begin();
        }
    }

    for (auto i = _obj_list.cbegin(); i != _obj_list.cend(); i++) {
        if (i->get()->GetType() == IGameObject::type_e::PLAYER) {
            players++;
            if (i->get()->GetId() == "p1")
                _winner = 1;
            else
                _winner = 2;
        }
    }

    if (players == 1) {
        this->_ctrl->_context.winner = _winner;
        this->_ctrl->_context.sceneName = "endScene";
    }

    if (this->_ctrl->_receiver->IsKeyDown(irr::KEY_ESCAPE)) {
        this->_ctrl->_context.sceneName = "pauseScene";
    }

    for (auto i = _obj_list.begin(); i != _obj_list.end(); i++) {
        if (i->get()->GetStatus() != IGameObject::status_e::DELETED)
            i->get()->Update(_obj_list);
    }
}
