//
// Created by Pierre on 13/06/2020.
//

#include "SelectSkin.hpp"
#include "Player.hpp"
#include "AssetSelector.hpp"

SelectSkin::SelectSkin(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{
}

void SelectSkin::Init(void)
{
    this->_background = this->_ctrl->_driver->getTexture(AssetSelector(BACKGROUND_SS).c_str());
    this->_first_skin = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 2) - 215, HEIGHT - 110), GUI_ID_SKIN_WHITE_BUTTON, AssetSelector(FIRST_SKIN_SS).string(), AssetSelector(FIRST_SKIN_SS).string());
    this->_second_skin = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 2) - 105, HEIGHT - 110), GUI_ID_SKIN_GREEN_BUTTON, AssetSelector(SECOND_SKIN_SS).string(), AssetSelector(SECOND_SKIN_SS).string());
    this->_third_skin = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 2) + 5, HEIGHT - 110), GUI_ID_SKIN_BLUE_BUTTON, AssetSelector(THIRD_SKIN_SS).string(), AssetSelector(THIRD_SKIN_SS).string());
    this->_fourth_skin = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(100, 100), vector2d<int>((WIDTH / 2) + 115, HEIGHT - 110), GUI_ID_SKIN_BLACK_BUTTON, AssetSelector(FOURTH_SKIN_SS).string(), AssetSelector(FOURTH_SKIN_SS).string());
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, AssetSelector(BUTTON_SOUND_SS).string());
    this->_buttonGo = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(150, 150), vector2d<int>((WIDTH / 2) + 305, HEIGHT - 160), GUI_ID_GO_BUTTON, AssetSelector(BUTTON_GO_SS).string(), AssetSelector(BUTTON_GO_DARK_SS).string());
    this->_buttonBack = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(150, 150), vector2d<int>((WIDTH / 2) - 550, (HEIGHT / 2) - 300), GUI_ID_PLAY_BUTTON, AssetSelector(BUTTON_BACK_SS).string(), AssetSelector(BUTTON_BACK_DARK_SS).string());

    this->_current_skin = 0;
    _ctrl->_scene_mgr->addCameraSceneNode(0, vector3df(0, 0 , 0), vector3df(0, 0, 1));
    irr::scene::ICameraSceneNode *camera = _ctrl->_scene_mgr->getActiveCamera();
    p1 = std::make_unique<Player>(_ctrl, "p1", Player::WHITE, Player::MENU);
    p2 = std::make_unique<Player>(_ctrl, "p2", Player::GREEN, Player::MENU);
    p3 = std::make_unique<Player>(_ctrl, "p3", Player::BLUE, Player::MENU);
    p4 = std::make_unique<Player>(_ctrl, "p4", Player::BLACK, Player::MENU);
    p1->Init();
    p2->Init();
    p3->Init();
    p4->Init();
    SelectPlayer();
}

void SelectSkin::Update(void)
{
    SelectPlayer();
    _ctrl->_driver->beginScene(true, true, SColor(100, 150, 150, 150));
    if (this->_first_skin->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_second_skin->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_third_skin->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_fourth_skin->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonGo->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonBack->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
}

void SelectSkin::Render(void)
{
    this->_ctrl->_driver->draw2DImage(_background, core::position2d<s32>(0,0), core::rect<s32>(0,0,1280,720), 0, video::SColor(255,255,255,255), true);
    for (auto i = _obj_list.begin(); i != _obj_list.end(); i++)
        if (i->get()->GetStatus() != IGameObject::status_e::DELETED)
            i->get()->Render();
    _ctrl->_scene_mgr->drawAll();
    this->_ctrl->_env->drawAll();
}

void SelectSkin::Clear(void)
{
    this->_ctrl->_env->clear();
    this->_ctrl->_context.clear_obj = true;
}

void SelectSkin::SelectPlayer()
{
    if (_ctrl->_context.skin_player_one == _current_skin)
        return;
    if (_ctrl->_context.skin_player_one == 1) {
        p1->setPosition(irr::core::vector3df(0, -3, 9));
        this->_current_skin = 1;
    }
    if (_ctrl->_context.skin_player_one == 2) {
        p2->setPosition(irr::core::vector3df(0, -3, 9));
        this->_current_skin = 2;
    }
    if (_ctrl->_context.skin_player_one == 3) {
        p3->setPosition(irr::core::vector3df(0, -3, 9));
        this->_current_skin = 3;
    }
    if (_ctrl->_context.skin_player_one == 4) {
        p4->setPosition(irr::core::vector3df(0, -3, 9));
        this->_current_skin = 4;
    }
    for (int i = 1; i <= 4; i++) {
        if (i != this->_current_skin) {
            if (i == 1)
                p1->setPosition(irr::core::vector3df(0, -100, 9));
            if (i == 2)
                p2->setPosition(irr::core::vector3df(0, -100, 9));
            if (i == 3)
                p3->setPosition(irr::core::vector3df(0, -100, 9));
            if (i == 4)
                p4->setPosition(irr::core::vector3df(0, -100, 9));
        }
    }
}