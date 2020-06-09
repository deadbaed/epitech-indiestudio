//
// Created by peter on 06/06/2020.
//

#include "Button.hpp"

Button::Button(IrrlichtDevice *device, vector2d<int> size, vector2d<int> pos, ButtonType type, std::string path1, std::string path2)
{
    this->_driver = device->getVideoDriver();
    this->_env = device->getGUIEnvironment();
    this->_textureButton = this->_driver->getTexture(path1.c_str());
    this->_textureButtonOver = this->_driver->getTexture(path2.c_str());
    this->_button = this->_env->addButton(rect<s32>(pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y), 0, type);
    this->_button->setImage(this->_textureButton);
    this->_button->setPressedImage(this->_textureButtonOver);
    this->_states = 0;
    this->_lastStates = 0;
}

Button::Button(IrrlichtDevice *device, vector2d<int> size, vector2d<int> pos, ButtonType type, std::string path1)
{
    this->_driver = device->getVideoDriver();
    this->_env = device->getGUIEnvironment();

    this->_textureButton = this->_driver->getTexture(path1.c_str());
    this->_textureButtonOver = NULL;
    this->_button = this->_env->addButton(rect<s32>(pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y), 0, type);
    this->_button->setImage(this->_textureButton);

    this->_states = 0;
    this->_lastStates = 0;
}


int Button::updateButton(SAppContext context) {
    if (this->_textureButtonOver == NULL)
        return 0;
    if (this->_button->isPointInside(vector2d<s32>(context.Position.X, context.Position.Y))) {
        this->_states = 1;
    }
    if (!this->_button->isPointInside(vector2d<s32>(context.Position.X, context.Position.Y))) {
        this->_states = 0;
    }
    if (this->_states == 0 && this->_lastStates == 1) {
        this->_button->setImage(this->_textureButton);
        this->_lastStates = 0;
    }
    if (this->_states == 1 && this->_lastStates == 0) {
        this->_button->setImage(this->_textureButtonOver);
        this->_lastStates = 1;
    }
    return 0;
}