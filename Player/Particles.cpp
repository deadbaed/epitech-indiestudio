/*
** EPITECH PROJECT, 2020
** Indie studio
** File description:
** Particles
*/

#include "Particles.hpp"
#include "AssetSelector.hpp"

Particles::Particles(const std::shared_ptr<IrrlichtController> &ctrl, ParticleSetting_t settings) : _ctrl(ctrl)
{
    _particle = this->_ctrl->_scene_mgr->addParticleSystemSceneNode(false);
    this->_settings = settings;
}

void Particles::Init()
{
    irr::scene::IParticleEmitter * _emitter= _particle->createBoxEmitter(
            _settings._box,
            _settings._direction,
            _settings._minParticles,
            _settings._maxParticles,
            video::SColor(10,255,255,255),
            video::SColor(10,255,255,255),
            _settings._minLifeTime,
            _settings._maxLifeTime);
    _emitter->setMinStartSize(_settings._minStartSize);
    _emitter->setMaxStartSize(_settings._maxStartSize);

    _particle->setEmitter(_emitter);
    _emitter->drop();

    _paf = _particle->createFadeOutParticleAffector();
    _particle->addAffector(_paf);
    this->_paf->drop();
    _particle->setMaterialFlag(video::EMF_LIGHTING, false);
    _particle->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
    _particle->setMaterialTexture(0, this->_ctrl->_driver->getTexture(AssetSelector(PARTICLE_PATH).c_str()));
    _particle->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
}

Particles::~Particles()
{
}

void Particles::clear()
{
    this->_particle->clearParticles();
}

void Particles::setPosition(irr::core::vector3df position)
{
    this->_particle->setPosition(position);
}

void Particles::Delete() {
    //this->clear();
    //this->_particle->removeAllAffectors();
    //this->_particle->removeAll();
    //this->_particle->removeAll();
//    std::cout << "Particles" << std::endl;
    if (this->_particle) {
        this->_particle->remove();
        this->_particle = NULL;
        //this->_particle->remove();
        //this->_particle->drop();
    }
}