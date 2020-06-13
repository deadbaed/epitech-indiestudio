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
#include "Particles.hpp"

#define BOMB_PATH       "../assets/bomb/bomb.b3d"
#define PARTICLE_PATH   "../assets/bomb/fire.bmp"

/* Explose after.. */
#define TIME_BOMB    4

class Bomb : public GameObject {
public:
    Bomb(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
    ~Bomb() = default;
    void Init();
    void Update(std::vector<std::shared_ptr<IGameObject>> &obj);
    void Delete();
    void setPosition(irr::core::vector3df const position);
private:
    bool calculateCollision(irr::core::vector3df position);
    void explosion(void);
    Particles::ParticleSetting_t setExplosions(core::vector3df);
    Particles::ParticleSetting_t setParticle(void);
    irr::scene::IAnimatedMeshSceneNode *_node;
    std::vector<std::shared_ptr<IGameObject>> *_obj;
    /* Particles */
    std::unique_ptr<Particles> _particles;
    /* During Explosion */
    std::unique_ptr<Particles> _upperExplosion;
    std::unique_ptr<Particles> _downExplosion;
    std::unique_ptr<Particles> _leftExplosion;
    std::unique_ptr<Particles> _rightExplosion;
    /* Clock */
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::time_point<std::chrono::steady_clock> end;
    std::chrono::duration<double> elapsed_seconds;
    bool _boom;
};

#endif /* !BOMB_HPP */