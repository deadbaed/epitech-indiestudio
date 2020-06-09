/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "../GameObject/GameObject.hpp"

#include <iostream>

class Player : public GameObject {
    public:
        Player(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(const std::string texture);
        void Update();
        void Delete();
        void SetPosition(irr::core::vector3df position);
        ~Player();
        void test(void);
    private:
        irr::scene::IAnimatedMeshSceneNode *_node;
};

#endif /* !PLAYER_HPP_ */
