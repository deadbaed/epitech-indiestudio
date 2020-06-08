/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** GameObject
*/

#ifndef IGAMEOBJECT_HPP_
#define IGAMEOBJECT_HPP_

#include <irrlicht.h>

class IGameObject {
    enum TYPE {
        PLAYER = 0,
        ENEMY,
        WALL,
        DESTRUCTABLE_WALL,
        GROUND,
        BONUS
    };
    public:
        virtual ~IGameObject() = default;
        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void SetPosition(irr::core::vector3df position) = 0;
        virtual irr::core::vector3df GetPosition(void) = 0;
        virtual void SetRotation(irr::core::vector3df position) = 0;
        virtual irr::core::vector3df GetRotation(void) = 0;
        virtual const std::string &GetId(void) = 0;
};

#endif /* !GAMEOBJECT_HPP_ */
