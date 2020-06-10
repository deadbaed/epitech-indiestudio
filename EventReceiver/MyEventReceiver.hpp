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
};

class MyEventReceiver : public IEventReceiver {
    public:
        MyEventReceiver(SAppContext &context) : Context(context) {}
        virtual bool OnEvent(const SEvent &event);

    private:
        SAppContext &Context;
};

enum ButtonType {
    GUI_ID_PLAY_BUTTON,
    GUI_ID_SETTINGS_BUTTON,
    GUI_ID_EXIT_BUTTON,
    GUI_ID_PLUS_BUTTON,
    GUI_ID_MINUS_BUTTON,
    GUI_ID_BACK_BUTTON,
    GUI_ID_ONE_PLAYER_BUTTON,
    GUI_ID_TWO_PLAYERS_BUTTON
};

#endif //BOMBERMAN_MYEVENTRECEIVER_HPP
