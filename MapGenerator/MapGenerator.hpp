/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** [enter description here]
*/

#ifndef MAPGENERATOR_HPP_
#define MAPGENERATOR_HPP_

#include "irrlicht.h"
#include <vector>
#include <random>
#include "blockMap.hpp"


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class mapGenerator {
private:
    vector3df _pos;
    unsigned int _width;
    unsigned int _lenght;
    float _spacing;
    std::vector<std::vector<IAnimatedMeshSceneNode *>> _meshes;
    int checkCorner(unsigned int i, unsigned int j);
public:
    mapGenerator();
    mapGenerator(const vector3df &pos, float spacing, unsigned int width, unsigned int lenght);
    ~mapGenerator();
    void setPosition(const vector3df &pos);
    void setSize(unsigned int width, unsigned int lenght);
    void setSpacing(float spacing);
    std::vector<std::shared_ptr<GameObject>> generateBorder(const std::shared_ptr<IrrlichtController> &ctrl, std::vector<std::shared_ptr<IGameObject>> &list, const std::string &pathMesh);
    std::vector<std::shared_ptr<GameObject>> generateBlock(const std::shared_ptr<IrrlichtController> &ctrl, std::vector<std::shared_ptr<IGameObject>> &list, const std::string &pathMesh, unsigned int prob);
    std::shared_ptr<GameObject> setMesh(const std::shared_ptr<IrrlichtController> &ctrl, vector3df pos, std::string name, IAnimatedMesh *mesh);
    std::vector<std::shared_ptr<GameObject>> generateWall(const std::shared_ptr<IrrlichtController> &ctrl, std::vector<std::shared_ptr<IGameObject>> &list, const std::string &pathMesh);
    std::vector<std::shared_ptr<GameObject>> generate(const std::shared_ptr<IrrlichtController> &ctrl, std::vector<std::shared_ptr<IGameObject>> &list, const std::string &pathMesh, unsigned int prob);
    //std::vector<IAnimatedMeshSceneNode *> generateBlock(ISceneManager* &smgr, IAnimatedMesh* &mesh, int prob);
    //std::vector<IAnimatedMeshSceneNode *> generateBorder(ISceneManager* &smgr, IAnimatedMesh* &mesh);
    //std::vector<IAnimatedMeshSceneNode *> generateWall(ISceneManager* &smgr, IAnimatedMesh* &mesh);
    //std::vector<IAnimatedMeshSceneNode *> generate(ISceneManager* &smgr, IAnimatedMesh* &mesh, int prob);
    vector3df getPos(void);
    unsigned int getSize(void);
    float getSpacing(void);
    void getMap(unsigned int i);
};

#endif // MAPGENERATOR_HPP_
