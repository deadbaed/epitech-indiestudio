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
    _context.sceneName = "";
    _context.down_volume = false;
    _context.up_volume = false;
    _context.down_volume_sound = false;
    _context.up_volume_sound = false;
    _context.volume_music = LoadMusic();
    _context.volume_sound = LoadSound();
    this->_music = std::make_shared<Music>(_context);
    this->_receiver = new MyEventReceiver(_context);
    _context.nb_player = 0;
    _context.skin_player_one = 1;
    _context.skin_player_two = 2;
    _context.winner = 1;
    _device->setEventReceiver(_receiver);
}

bool IrrlichtController::isRunning(void)
{
    return _device->run();
}

IrrlichtController::~IrrlichtController()
{

}

float IrrlichtController::LoadMusic() {
    float new_music;

    bool ret = config.Load("Music", &new_music);

    if (!ret)
        new_music = DEFAULT_MUSIC;
    return new_music;
}

float IrrlichtController::LoadSound() {
    float new_sound;

    bool ret = config.Load("Sound", &new_sound);

    if (!ret)
        new_sound = DEFAULT_SOUND;
    return new_sound;
}

void IrrlichtController::SaveConfig() {
    config.Save("Music", &_context.volume_music);
    config.Save("Sound", &_context.volume_sound);
}