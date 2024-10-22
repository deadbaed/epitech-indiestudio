//
// Created by peter on 13/06/2020.
//

#include "EndScene.hpp"
#include "Player.hpp"
#include "AssetSelector.hpp"

EndScene::EndScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{

}

void EndScene::Init(void)
{
    this->_background = this->_ctrl->_driver->getTexture(AssetSelector(BACKGROUND_END).c_str());
    _ctrl->_scene_mgr->addCameraSceneNode(0, vector3df(0, 0 , 0), vector3df(0, 0, 1));
    irr::scene::ICameraSceneNode *camera = _ctrl->_scene_mgr->getActiveCamera();
    std::shared_ptr<Player> p = std::make_shared<Player>(_ctrl, "p1", (Player::BomberType)_ctrl->_context.skin_player_one, Player::MENU);
    std::shared_ptr<Player> p2 = std::make_shared<Player>(_ctrl, "p2", (Player::BomberType)_ctrl->_context.skin_player_two, Player::MENU);
    p->Init();
    p2->Init();
    if (_ctrl->_context.winner == 1) {
        p->setPosition(irr::core::vector3df(1, -3, 9));
        p2->setPosition(irr::core::vector3df(-6, -3, 14));
    }
    else {
        p2->setPosition(irr::core::vector3df(1, -3, 9));
        p->setPosition(irr::core::vector3df(-6, -3, 14));
    }
    this->_ctrl->_music->Play(AssetSelector(MUSIC_END).string());
    this->_restart = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(400, 100), vector2d<int>(WIDTH / 2 - 600, HEIGHT / 2 - 300), GUI_ID_RESUME_BUTTON_PAUSED, AssetSelector(RESTART).string(), AssetSelector(RESTART_DARK).string());
    this->_exit = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(400, 100), vector2d<int>(WIDTH / 2 + 200, HEIGHT / 2 - 300), GUI_ID_EXIT_BUTTON_PAUSED, AssetSelector(EXIT_END).string(), AssetSelector(EXIT_END_DARK).string());
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, AssetSelector(BUTTON_SOUND_END).string());
}
void EndScene::Update(void)
{
    _ctrl->_driver->beginScene(true, true, SColor(100, 150, 150, 150));
    if (this->_exit->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_restart->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
}

void EndScene::Render(void)
{
    _ctrl->_driver->draw2DImage(_background, core::position2d<s32>(0,0), core::rect<s32>(0,0,1280,720), 0, video::SColor(255,255,255,255), true);
//    for (auto i = _obj_list.begin(); i != _obj_list.end(); i++)
//        if (i->get()->GetStatus() != IGameObject::status_e::DELETED)
//            i->get()->Render();
    _ctrl->_scene_mgr->drawAll();
    this->_ctrl->_env->drawAll();
}

void EndScene::Clear(void)
{
    this->_ctrl->_env->clear();
    this->_ctrl->_context.clear_obj = true;
}