//
// Created by Pierre on 05/06/2020.
//

#ifndef BOMBERMAN_MYEVENTRECEIVER_HPP
#define BOMBERMAN_MYEVENTRECEIVER_HPP

#include <irrlicht.h>
#include <string>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

struct SAppContext {
    IrrlichtDevice *device;
    core::position2di Position;
    bool settings;
    std::string sceneName;
    float volume_music;
    float volume_sound;
    bool up_volume;
    bool down_volume;
    bool up_volume_sound;
    bool down_volume_sound;
    int nb_player;
    int skin_player_one;
    int skin_player_two;
    int winner;
};

class MyEventReceiver : public IEventReceiver {
    public:
        MyEventReceiver(SAppContext &context);
        virtual bool OnEvent(const SEvent &event);
        virtual bool IsKeyDown(EKEY_CODE keyCode) const;

private:
        SAppContext &Context;
        bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

enum ButtonType {
    GUI_ID_PLAY_BUTTON,
    GUI_ID_SETTINGS_BUTTON,
    GUI_ID_EXIT_BUTTON,

    GUI_ID_PLUS_BUTTON,
    GUI_ID_MINUS_BUTTON,
    GUI_ID_PLUS_BUTTON_SOUND,
    GUI_ID_MINUS_BUTTON_SOUND,
    GUI_ID_BACK_BUTTON,

    GUI_ID_ONE_PLAYER_BUTTON,
    GUI_ID_TWO_PLAYERS_BUTTON,

    GUI_ID_SKIN_WHITE_BUTTON,
    GUI_ID_SKIN_BLACK_BUTTON,
    GUI_ID_SKIN_GREEN_BUTTON,
    GUI_ID_SKIN_BLUE_BUTTON,
    GUI_ID_SKINS_WHITE_BUTTON,
    GUI_ID_SKINS_BLACK_BUTTON,
    GUI_ID_SKINS_GREEN_BUTTON,
    GUI_ID_SKINS_BLUE_BUTTON,
    GUI_ID_GO_BUTTON,

    GUI_ID_RESUME_BUTTON_PAUSED,
    GUI_ID_EXIT_BUTTON_PAUSED,
    GUI_ID_OPTION_BUTTON_PAUSED,

    GUI_ID_BACK_BUTTON_SETTINGS
};

#endif //BOMBERMAN_MYEVENTRECEIVER_HPP
