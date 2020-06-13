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
                        Context.sceneName = "chooseplayersScene";
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
                    case GUI_ID_ONE_PLAYER_BUTTON:
                        Context.nb_player = 1;
                        Context.sceneName = "skinScene";
                        return true;
                    case GUI_ID_TWO_PLAYERS_BUTTON:
                        Context.nb_player = 2;
                        Context.sceneName = "skinsScene";
                        return true;
                    case GUI_ID_PLUS_BUTTON:
                        Context.up_volume = true;
                        return true;
                    case GUI_ID_MINUS_BUTTON:
                        Context.down_volume = true;
                        return true;
                    case GUI_ID_PLUS_BUTTON_SOUND:
                        Context.up_volume_sound = true;
                        return true;
                    case GUI_ID_MINUS_BUTTON_SOUND:
                        Context.down_volume_sound = true;
                        return true;
                    case GUI_ID_RESUME_BUTTON_PAUSED:
                        Context.sceneName = "gameScene";
                        return true;
                    case GUI_ID_EXIT_BUTTON_PAUSED:
                        Context.sceneName = "menuScene";
                        return true;
                    case GUI_ID_OPTION_BUTTON_PAUSED:
                        Context.sceneName = "pauseSettingsScene";
                        return true;
                    case GUI_ID_BACK_BUTTON_SETTINGS:
                        Context.sceneName = "pauseScene";
                        return true;
                    case GUI_ID_SKIN_WHITE_BUTTON:
                        Context.skin_player_one = 1;
                        return true;
                    case GUI_ID_SKIN_BLUE_BUTTON:
                        Context.skin_player_one = 3;
                        return true;
                    case GUI_ID_SKIN_GREEN_BUTTON:
                        Context.skin_player_one = 2;
                        return true;
                    case GUI_ID_SKIN_BLACK_BUTTON:
                        Context.skin_player_one = 4;
                        return true;
                    case GUI_ID_SKINS_WHITE_BUTTON:
                        Context.skin_player_two = 1;
                        return true;
                    case GUI_ID_SKINS_BLUE_BUTTON:
                        Context.skin_player_two = 3;
                        return true;
                    case GUI_ID_SKINS_GREEN_BUTTON:
                        Context.skin_player_two = 2;
                        return true;
                    case GUI_ID_SKINS_BLACK_BUTTON:
                        Context.skin_player_two = 4;
                        return true;
                    case GUI_ID_GO_BUTTON:
                        Context.sceneName = "gameScene";
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