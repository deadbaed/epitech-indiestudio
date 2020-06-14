/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** [enter description here]
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "GameObject.hpp"

#include <random>
#include <iostream>

#define SKATE "../assets/skate.obj"

class PowerUp : public GameObject {
    public:
        PowerUp(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(void);
        void Update(std::vector<std::shared_ptr<IGameObject>> &obj);
        void Delete();
        void SetPosition(irr::core::vector3df position);
        const IGameObject::type_e GetType(void);
        ~PowerUp();
    private:
        irr::scene::IAnimatedMeshSceneNode *_node;
};

#endif /* !BLOCK_HPP_ */
