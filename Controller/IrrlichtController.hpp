/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** IrrlichtController
*/

#ifndef IRRLICHTCONTROLLER_HPP_
#define IRRLICHTCONTROLLER_HPP_

#include <irrlicht.h>
#include "Music.hpp"
#include "Storage.hpp"
#include <memory>

#define WIDTH 1280
#define HEIGHT 720

#define DEFAULT_MUSIC 20
#define DEFAULT_SOUND 40

class IrrlichtController {
    public:
        IrrlichtController();
        void Init(irr::video::E_DRIVER_TYPE driver_type, int width, int length);
        ~IrrlichtController();
        bool isRunning(void);
        void SaveConfig();
    public:
        irr::IrrlichtDevice* _device;
        irr::scene::ISceneManager *_scene_mgr;
        irr::video::IVideoDriver *_driver;
        irr::gui::IGUIEnvironment *_env;
        SAppContext _context;
        MyEventReceiver *_receiver;
        std::shared_ptr<Music> _music;
        float _volume;
    private:
        Storage config;
        float LoadMusic();
        float LoadSound();
};

#endif /* !IRRLICHTCONTROLLER_HPP_ */
