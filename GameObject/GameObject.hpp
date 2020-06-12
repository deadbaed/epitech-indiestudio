/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** AGameObject
*/

#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include <irrlicht.h>
#include <string>
#include <memory>
#include <vector>
#include "IGameObject.hpp"
#include "IrrlichtController.hpp"
#include "Collider.hpp"

class GameObject : public IGameObject {
    public:
        GameObject(const std::shared_ptr<IrrlichtController> &ctrl, const irr::core::vector3df dimension, const std::string name);
        ~GameObject();
        virtual void Init(void);
        virtual void Update(std::vector<std::shared_ptr<IGameObject>> &obj);
        virtual void Render(void);
        virtual void Delete(void);
        virtual GameObject &operator=(const GameObject &obj);
        virtual bool operator==(const GameObject &obj);
        virtual void SetPosition(irr::core::vector3df position);
        virtual irr::core::vector3df GetPosition(void);
        virtual void SetRotation(irr::core::vector3df position);
        virtual irr::core::vector3df GetRotation(void);
        virtual Collider *GetCollider(void);
        virtual const std::string &GetId(void);
        virtual IGameObject::status_e &GetStatus(void);
        virtual const IGameObject::type_e GetType(void);

    protected:
        irr::core::vector3df _position;
        irr::core::vector3df _rotation;
        const std::string _id;
        const std::shared_ptr<IrrlichtController> &_ctrl;
        IGameObject::status_e _status;
        std::shared_ptr<Collider> _collider;
        IGameObject::status_e _type;
};

#endif /* !GAMEOBJECT_HPP_ */
