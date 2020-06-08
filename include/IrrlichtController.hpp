/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** IrrlichtController
*/

#ifndef IRRLICHTCONTROLLER_HPP_
#define IRRLICHTCONTROLLER_HPP_

#include <irrlicht.h>

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
};

#endif /* !IRRLICHTCONTROLLER_HPP_ */
