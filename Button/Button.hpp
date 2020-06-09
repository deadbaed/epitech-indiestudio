//
// Created by peter on 06/06/2020.
//

#ifndef BOMBERMAN_BUTTON_HPP
#define BOMBERMAN_BUTTON_HPP

#include <irrlicht.h>
#include <string>
#include <memory>
#include "../EventReceiver/MyEventReceiver.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Button {
    public:
        Button(IrrlichtDevice *device, vector2d<int> size, vector2d<int> pos, ButtonType type, std::string path1);
        Button(IrrlichtDevice *device, vector2d<int> size, vector2d<int> pos, ButtonType type, std::string path1, std::string path2);
        ~Button(){}
        int updateButton(SAppContext _context);
    private:
        video::IVideoDriver *_driver;
        IGUIEnvironment *_env;
        int _sizeX;
        int _sizeY;
        vector2d<int> _position;
        IGUIButton *_button;
        ITexture *_textureButton;
        ITexture *_textureButtonOver;
        int _lastStates;
        int _states;
};


#endif //BOMBERMAN_BUTTON_HPP
