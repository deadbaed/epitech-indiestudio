/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** GameScene
*/

#include "GameScene.hpp"

GameScene::GameScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{
    this->player_one_set = false;
    this->map_set = false;
}

GameScene::~GameScene()
{

}

void GameScene::Init(void)
{
    if (this->_ctrl->_context.clear_obj) {
        _obj_list.clear();
        this->_ctrl->_context.clear_obj = false;
        this->player_one_set = false;
        this->map_set = false;
        this->player_two_set = false;
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
        std::shared_ptr<mapGenerator> map = std::make_shared<mapGenerator>(vector3df(0, 0, 0), 6, 11, 11);
        map->generate(_ctrl, _obj_list, "../assets/floor.obj", 100);
        map->generateWall(_ctrl, _obj_list, "../assets/wall_1.obj");
        map->generateBorder(_ctrl, _obj_list, "../assets/wall_1.obj");
        map->generateBlock(_ctrl, _obj_list, "../assets/wall_2.obj", 30);
    }

    /* Music */
    this->_ctrl->_music->Play("../assets/audio/music_game.ogg");

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
