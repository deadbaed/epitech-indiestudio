/*
** EPITECH PROJECT, 2020
** Indie Studio
** File description:
** Bomb
*/

#ifndef BOMB_HPP
#define BOMB_HPP

#include <iostream>
#include "GameObject.hpp"
#include "MyEventReceiver.hpp"

#define BOMB_PATH "../assets/bomb/bomb.b3d"

class Bomb : public GameObject {
public:
    Bomb(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
    ~Bomb() = default;
    void Init();
    void Update();
    void Delete();
private:
    void setPosition(irr::core::vector3df const position);
    irr::scene::IAnimatedMeshSceneNode *_node;
};

#endif /* !BOMB_HPP */d