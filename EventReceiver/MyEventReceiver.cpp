//
// Created by Pierre on 05/06/2020.
//

#include "MyEventReceiver.hpp"

MyEventReceiver::MyEventReceiver(SAppContext &context) : Context(context)
{
    for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

bool MyEventReceiver::OnEvent(const SEvent &event) {
    if (event.EventType == EET_GUI_EVENT) {
        s32 id = event.GUIEvent.Caller->getID();
        IGUIEnvironment *env = Context.device->getGUIEnvironment();
        switch (event.GUIEvent.EventType) {
            case EGET_BUTTON_CLICKED:
                switch (id) {
                    case GUI_ID_PLAY_BUTTON:
                        Context.sceneName = "gameScene";
                        return true;
                    case GUI_ID_SETTINGS_BUTTON:
                        Context.sceneName = "settingsScene";
                        return true;
                    case GUI_ID_EXIT_BUTTON:
                        Context.device->closeDevice();
                        return true;
                    case GUI_ID_BACK_BUTTON:
                        Context.sceneName = "menuScene";
                        return true;
                    default:
                        return false;
                }
            default:
                break;
        }
    }
    if (event.EventType == EET_MOUSE_INPUT_EVENT) {
        switch (event.MouseInput.Event) {
            case EMIE_MOUSE_MOVED:
                this->Context.Position.X = event.MouseInput.X;
                this->Context.Position.Y = event.MouseInput.Y;
                break;
            default:
                break;
        }
    }
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return false;
}

bool MyEventReceiver::IsKeyDown(EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}