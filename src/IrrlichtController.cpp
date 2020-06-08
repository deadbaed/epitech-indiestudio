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
}

bool IrrlichtController::isRunning(void)
{
    return _device->run();
}

IrrlichtController::~IrrlichtController()
{

}
