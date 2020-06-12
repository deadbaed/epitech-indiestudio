/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** GameObject
*/

#ifndef IGAMEOBJECT_HPP_
#define IGAMEOBJECT_HPP_

#include <irrlicht.h>
#include "Collider.hpp"
class IGameObject {
    public:
    enum TYPE {
        PLAYER = 0,
        ENEMY,
        WALL,
        DESTRUCTABLE_WALL,
        GROUND,
        BONUS
    };
    enum STATUS {
        OK = 0,
        DELETED
    };
    public:
        virtual ~IGameObject() = default;
        virtual void Init(void) = 0;
        virtual void Update(std::vector<std::shared_ptr<IGameObject>> &obj) = 0;
        virtual void Render(void) = 0;
        virtual void Delete(void) = 0;
        virtual Collider *GetCollider(void) = 0;
        virtual void SetPosition(irr::core::vector3df position) = 0;
        virtual irr::core::vector3df GetPosition(void) = 0;
        virtual void SetRotation(irr::core::vector3df position) = 0;
        virtual irr::core::vector3df GetRotation(void) = 0;
        virtual const std::string &GetId(void) = 0;
        virtual IGameObject::STATUS &GetStatus(void) = 0;
};

#endif /* !GAMEOBJECT_HPP_ */
