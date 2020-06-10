/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** [enter description here]
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "GameObject.hpp"

#include <iostream>

class BlockMap : public GameObject {
    public:
        BlockMap(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(IAnimatedMesh* &mesh);
        void Update();
        void Delete();
        void SetPosition(irr::core::vector3df position);
        ~BlockMap();
        void test(void);
    private:
        irr::scene::IAnimatedMeshSceneNode *_node;
};

#endif /* !BLOCK_HPP_ */
