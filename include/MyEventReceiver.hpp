//
// Created by Pierre on 05/06/2020.
//

#ifndef BOMBERMAN_MYEVENTRECEIVER_HPP
#define BOMBERMAN_MYEVENTRECEIVER_HPP

#include <irrlicht.h>

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
};

class MyEventReceiver : public IEventReceiver {
public:
    MyEventReceiver(SAppContext &context) : Context(context) {}
    virtual bool OnEvent(const SEvent &event);

private:
    SAppContext &Context;
};

#endif //BOMBERMAN_MYEVENTRECEIVER_HPP
