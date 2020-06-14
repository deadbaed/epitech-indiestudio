/*
** EPITECH PROJECT, 2020
** Indie Studio
** File description:
** Particles
*/

#ifndef PARTICLES_HPP
#define PARTICLES_HPP

#include "GameObject.hpp"
#include "MyEventReceiver.hpp"

#define PARTICLE_PATH   "bomb/fire.bmp"

class Particles
{
public:
    /* Particles settings */
    typedef struct ParticleSetting_s {
        core::aabbox3d<f32> _box;
        core::vector3df _direction;
        int _minParticles;
        int _maxParticles;
        int _minLifeTime;
        int _maxLifeTime;
        core::dimension2d<f32> _minStartSize;
        core::dimension2d<f32> _maxStartSize;
    } ParticleSetting_t;
    Particles(const std::shared_ptr<IrrlichtController> &ctrl, ParticleSetting_t settings);
    ~Particles();
    void Init();
    void clear(void);
    void setPosition(irr::core::vector3df position);
    void Delete(void);
private:
    const std::shared_ptr<IrrlichtController> &_ctrl;
    irr::scene::IParticleSystemSceneNode *_particle;
    scene::IParticleAffector *_paf;
//    irr::scene::IParticleEmitter *_emitter;
    ParticleSetting_t _settings;
};

#endif