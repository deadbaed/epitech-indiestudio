/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** IrrlichtController
*/

#ifndef IRRLICHTCONTROLLER_HPP_
#define IRRLICHTCONTROLLER_HPP_

#include <irrlicht.h>
#include "../EventReceiver/MyEventReceiver.hpp"
#define WIDTH 1280
#define HEIGHT 720

class IrrlichtController {
    public:
        IrrlichtController();
        void Init(irr::video::E_DRIVER_TYPE driver_type, int width, int length);
        ~IrrlichtController();
        bool isRunning(void);
    public:
        irr::IrrlichtDevice* _device;
        irr::scene::ISceneManager *_scene_mgr;
        irr::video::IVideoDriver *_driver;
        irr::gui::IGUIEnvironment *_env;
        SAppContext _context;
        IEventReceiver *_receiver;
};

#endif /* !IRRLICHTCONTROLLER_HPP_ */
