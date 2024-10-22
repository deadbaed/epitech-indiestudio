/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** [enter description here]
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "GameObject.hpp"
#include "AssetSelector.hpp"
#include <iostream>

#define BLOCK_PATH "../assets/map/wall_2.obj"
#define WALL_PATH  "../assets/map/wall_1.obj"
#define GROUND_PATH "../assets/map/floor.obj"

class BlockMap : public GameObject {
    public:
        BlockMap(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        void Init(IAnimatedMesh* &mesh);
        void Init();
        void Update(std::vector<std::shared_ptr<IGameObject>> &obj);
        void Delete();
        void SetPosition(irr::core::vector3df position);
        const IGameObject::type_e GetType(void);
        ~BlockMap();
    private:
        irr::scene::IAnimatedMeshSceneNode *_node;
};

#endif /* !BLOCK_HPP_ */
