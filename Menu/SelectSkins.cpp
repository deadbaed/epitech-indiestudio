//
// Created by Pierre on 13/06/2020.
//

#include "SelectSkins.hpp"
#include "AssetSelector.hpp"

SelectSkins::SelectSkins(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name) : AScene(ctrl, name)
{
}

void SelectSkins::Init(void)
{
    this->_background = this->_ctrl->_driver->getTexture(AssetSelector(BACKGROUND_SSS).c_str());
    this->_first_skin_one = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>((WIDTH / 4) - 155, HEIGHT - 110), GUI_ID_SKIN_WHITE_BUTTON, AssetSelector(FIRST_SKIN_SSS).string(), AssetSelector(FIRST_SKIN_SSS).string());
    this->_second_skin_one = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>((WIDTH / 4) - 75, HEIGHT - 110), GUI_ID_SKIN_GREEN_BUTTON, AssetSelector(SECOND_SKIN_SSS).string(), AssetSelector(SECOND_SKIN_SSS).string());
    this->_third_skin_one = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>((WIDTH / 4) + 5, HEIGHT - 110), GUI_ID_SKIN_BLUE_BUTTON, AssetSelector(THIRD_SKIN_SSS).string(), AssetSelector(THIRD_SKIN_SSS).string());
    this->_fourth_skin_one = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>((WIDTH / 4) + 85, HEIGHT - 110), GUI_ID_SKIN_BLACK_BUTTON, AssetSelector(FOURTH_SKIN_SSS).string(), AssetSelector(FOURTH_SKIN_SSS).string());
    this->_first_skin_two = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>(WIDTH - (WIDTH / 4) - 75, HEIGHT - 110), GUI_ID_SKINS_WHITE_BUTTON, AssetSelector(FIRST_SKIN_SSS).string(), AssetSelector(FIRST_SKIN_SSS).string());
    this->_second_skin_two = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>(WIDTH - (WIDTH / 4) - 155, HEIGHT - 110), GUI_ID_SKINS_GREEN_BUTTON, AssetSelector(SECOND_SKIN_SSS).string(), AssetSelector(SECOND_SKIN_SSS).string());
    this->_third_skin_two = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>(WIDTH - (WIDTH / 4) + 5, HEIGHT - 110), GUI_ID_SKINS_BLUE_BUTTON, AssetSelector(THIRD_SKIN_SSS).string(), AssetSelector(THIRD_SKIN_SSS).string());
    this->_fourth_skin_two = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(70, 70), vector2d<int>(WIDTH - (WIDTH / 4) + 85, HEIGHT - 110), GUI_ID_SKINS_BLACK_BUTTON, AssetSelector(FOURTH_SKIN_SSS).string(), AssetSelector(FOURTH_SKIN_SSS).string());
    this->_buttonSound = std::make_unique<Sound>(this->_ctrl->_context, AssetSelector(BUTTON_SOUND_SSS).string());
    this->_buttonGo = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(150, 150), vector2d<int>((WIDTH / 2) - 75, HEIGHT - 160), GUI_ID_GO_BUTTON, AssetSelector(BUTTON_GO_SSS).string(), AssetSelector(BUTTON_GO_DARK_SSS).string());
    this->_buttonBack = std::make_unique<Button>(this->_ctrl->_device, vector2d<int>(150, 150), vector2d<int>((WIDTH / 2) - 550, (HEIGHT / 2) - 300), GUI_ID_PLAY_BUTTON, AssetSelector(BUTTON_BACK_SSS).string(), AssetSelector(BUTTON_BACK_DARK_SSS).string());

    this->_current_skin1 = 0;
    this->_current_skin2 = 0;
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
    SelectPlayerOne();
    SelectPlayerTwo();
}

void SelectSkins::Update(void)
{
    SelectPlayerOne();
    SelectPlayerTwo();
    _ctrl->_driver->beginScene(true, true, SColor(100, 150, 150, 150));
    if (this->_first_skin_one->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_second_skin_one->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_third_skin_one->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_fourth_skin_one->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();

    if (this->_first_skin_two->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_second_skin_two->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_third_skin_two->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_fourth_skin_two->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonGo->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
    if (this->_buttonBack->updateButton(this->_ctrl->_context))
        this->_buttonSound->Play();
}

void SelectSkins::Render(void)
{
    this->_ctrl->_driver->draw2DImage(_background, core::position2d<s32>(0,0), core::rect<s32>(0,0,1280,720), 0, video::SColor(255,255,255,255), true);
    for (auto i = _obj_list.begin(); i != _obj_list.end(); i++)
        if (i->get()->GetStatus() != IGameObject::status_e::DELETED)
            i->get()->Render();
    _ctrl->_scene_mgr->drawAll();
    this->_ctrl->_env->drawAll();
}

void SelectSkins::Clear(void)
{
    this->_ctrl->_env->clear();
    this->_ctrl->_context.clear_obj = true;
}

void SelectSkins::SelectPlayerOne()
{
    if (_ctrl->_context.skin_player_one == _current_skin1)
        return;
    if (_ctrl->_context.skin_player_one == _ctrl->_context.skin_player_two)
        return;
    if (_ctrl->_context.skin_player_one == 1) {
        p1->setPosition(irr::core::vector3df(-4, -3, 9));
        this->_current_skin1 = 1;
    }
    if (_ctrl->_context.skin_player_one == 2) {
        p2->setPosition(irr::core::vector3df(-4, -3, 9));
        this->_current_skin1 = 2;
    }
    if (_ctrl->_context.skin_player_one == 3) {
        p3->setPosition(irr::core::vector3df(-4, -3, 9));
        this->_current_skin1 = 3;
    }
    if (_ctrl->_context.skin_player_one == 4) {
        p4->setPosition(irr::core::vector3df(-4, -3, 9));
        this->_current_skin1 = 4;
    }
    for (int i = 1; i <= 4; i++) {
        if ((i != this->_current_skin1) && (i != this->_current_skin2)) {
            if (i == 1)
                p1->setPosition(irr::core::vector3df(-4, -100, 9));
            if (i == 2)
                p2->setPosition(irr::core::vector3df(-4, -100, 9));
            if (i == 3)
                p3->setPosition(irr::core::vector3df(-4, -100, 9));
            if (i == 4)
                p4->setPosition(irr::core::vector3df(-4, -100, 9));
        }
    }
}

void SelectSkins::SelectPlayerTwo()
{
    if (_ctrl->_context.skin_player_two == _current_skin2)
        return;
    if (_ctrl->_context.skin_player_two == _ctrl->_context.skin_player_one)
        return;
    if (_ctrl->_context.skin_player_two == 1) {
        p1->setPosition(irr::core::vector3df(4, -3, 9));
        this->_current_skin2 = 1;
    }
    if (_ctrl->_context.skin_player_two == 2) {
        p2->setPosition(irr::core::vector3df(4, -3, 9));
        this->_current_skin2 = 2;
    }
    if (_ctrl->_context.skin_player_two == 3) {
        p3->setPosition(irr::core::vector3df(4, -3, 9));
        this->_current_skin2 = 3;
    }
    if (_ctrl->_context.skin_player_two == 4) {
        p4->setPosition(irr::core::vector3df(4, -3, 9));
        this->_current_skin2 = 4;
    }
    for (int i = 1; i <= 4; i++) {
        if ((i != this->_current_skin1) && (i != this->_current_skin2)) {
            if (i == 1)
                p1->setPosition(irr::core::vector3df(4, -100, 9));
            if (i == 2)
                p2->setPosition(irr::core::vector3df(4, -100, 9));
            if (i == 3)
                p3->setPosition(irr::core::vector3df(4, -100, 9));
            if (i == 4)
                p4->setPosition(irr::core::vector3df(4, -100, 9));
        }
    }
}