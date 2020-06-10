/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** IrrlichtController
*/

#include "IrrlichtController.hpp"

IrrlichtController::IrrlichtController()
{

}

void IrrlichtController::Init(irr::video::E_DRIVER_TYPE driver_type, int width, int length)
{
    _device = irr::createDevice(driver_type, irr::core::dimension2d<irr::u32>(width, length), 64);
    _driver = _device->getVideoDriver();
    _scene_mgr = _device->getSceneManager();
    _env = _device->getGUIEnvironment();
    _context.device = this->_device;
    _context.Position.X = -1;
    _context.Position.Y = -1;
    _context.settings = false;
    _context.sceneName = "menuScene";
    _context.down_volume = false;
    _context.up_volume = false;
    _context.volume = 40; //à charger avec le fichier Save
    this->_music = std::make_shared<Music>(_context);
    this->_receiver = new MyEventReceiver(_context);

    _device->setEventReceiver(_receiver);
}

bool IrrlichtController::isRunning(void)
{
    return _device->run();
}

IrrlichtController::~IrrlichtController()
{

}
