/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** [enter description here]
*/

#include "MapGenerator.hpp"

mapGenerator::mapGenerator()
{
    this->_pos = vector3df(0, 0, 0);
    this->_spacing = 0;
    this->_width = 0;
    this->_lenght = 0;
}

mapGenerator::mapGenerator(const vector3df &pos, float spacing, unsigned int width, unsigned int lenght)
{
    this->_pos = pos;
    this->_spacing = spacing;
    this->_width = width;
    this->_lenght = lenght;

    _meshes =  new (std::nothrow) std::shared_ptr<IGameObject> *[width + 1];
    for (unsigned int i = 0; i < width; i++) {
        _meshes[i] = new (std::nothrow) std::shared_ptr<IGameObject>[lenght + 1];
        for (unsigned int j = 0; j < lenght; j++)
            _meshes[i][j] = NULL;
        _meshes[i][lenght] = NULL;
    }
    _meshes[width] = NULL;
}

mapGenerator::~mapGenerator() {}


void mapGenerator::setPosition(const vector3df &pos)
{
    this->_pos = pos;
}

void mapGenerator::setSize(unsigned int width, unsigned int lenght)
{
    this->_width = width;
    this->_lenght = lenght;
}

void mapGenerator::setSpacing(float spacing)
{
    this->_spacing = spacing;
}

std::shared_ptr<IGameObject> mapGenerator::setMesh(const std::shared_ptr<IrrlichtController> &ctrl, vector3df pos, std::string name, IAnimatedMesh *mesh)
{
    std::shared_ptr<BlockMap> node = std::make_shared<BlockMap>(ctrl, name);
    node->Init(mesh);
    node->SetPosition(pos);
    //node->GetCollider()->SetPosition(pos);
    return node;
}

std::vector<std::shared_ptr<GameObject>> mapGenerator::generateBorder(const std::shared_ptr<IrrlichtController> &ctrl, std::vector<std::shared_ptr<IGameObject>> &list, const std::string &pathMesh)
{
    float *axe = (float *) ::operator new (sizeof(float) * 3);
    _pos.getAs3Values(axe);
    float x = axe[0] - this->_spacing;
    float y = axe[1];
    float z = axe[2] - this->_spacing;
    IAnimatedMesh *mesh = ctrl->_scene_mgr->getMesh(pathMesh.c_str());
    std::vector<std::shared_ptr<GameObject>> mapped_mesh;

    for (unsigned int i = 0; i < this->_width; i++) {
        if (i == 0 || (i + 1 == this->_width)) {
            for (unsigned int j = 0; j < this->_lenght; j++) {
                this->_meshes[j][i] = this->setMesh(ctrl, vector3df(x, y, z), "border", mesh);
                list.push_back(this->_meshes[j][i]);
                if (j + 1 < this->_lenght)
                    x += this->_spacing;
            }
        } else {
            this->_meshes[0][i] = this->setMesh(ctrl, vector3df(x, y, z), "border", mesh);
            this->_meshes[this->_lenght - 1][i] = this->setMesh(ctrl, vector3df(x + (this->_spacing * (this->_lenght - 1)), y, z), "border", mesh);
            list.push_back(this->_meshes[0][i]);
            list.push_back(this->_meshes[this->_lenght - 1][i]);
        }
        if (i + 1 < this->_width)
            z += this->_spacing;
        x = axe[0] - this->_spacing;
    }
    delete(axe);
    return mapped_mesh;
}

int mapGenerator::checkCorner(unsigned int i, unsigned int j)
{
    if ((j == 1 && i == 1) || (j == 2 && i == 1) || (j == 1 && i == 2))
        return 1;
    if ((j == 1 && (i + 1 == this->_width - 1)) || (j == 2 && (i + 1 == this->_width - 1)) || (j == 1 && (i + 2 == this->_width - 1)))
        return 1;
    if (((j + 1 == this->_lenght - 1) && i == 1) || ((j + 2 == this->_lenght - 1) && i == 1) || ((j + 1 == this->_lenght - 1) && i == 2))
        return 1;
    if (((j + 1 == this->_lenght - 1) && (i + 1 == this->_width - 1)) || ((j + 2 == this->_lenght - 1) && (i + 1 == this->_width - 1)) || ((j + 1 == this->_lenght - 1) && (i + 2 == this->_width - 1)))
        return 1;
    return 0;
}

std::vector<std::shared_ptr<GameObject>> mapGenerator::generateBlock(const std::shared_ptr<IrrlichtController> &ctrl, std::vector<std::shared_ptr<IGameObject>> &list, const std::string &pathMesh, unsigned int prob)
{
    std::random_device dev;
    std::mt19937 _prob(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(1,100);

    float *axe = (float *) ::operator new (sizeof(float) * 3);
    _pos.getAs3Values(axe);
    float x = axe[0];
    float y = axe[1];
    float z = axe[2];
    IAnimatedMesh *mesh = ctrl->_scene_mgr->getMesh(pathMesh.c_str());
    std::vector<std::shared_ptr<GameObject>> mapped_mesh;

    for (unsigned int i = 0; i < this->_width - 2; i++) {
        if (i % 2 != 0) {
            for (unsigned int j = 0; j < this->_lenght - 2; j++) {
                if (checkCorner(i + 1, j + 1) == 1) {
                    if (j + 1 < this->_lenght - 2)
                        x += this->_spacing;
                    continue;
                }
                if (j % 2 == 0 && distribution(_prob) <= prob) {
                    this->_meshes[j + 1][i + 1] = this->setMesh(ctrl, vector3df(x, y, z), "block", mesh);
                    list.push_back(this->_meshes[j + 1][i + 1]);
                }
                    //list.push_back(this->setMesh(ctrl, vector3df(x, y, z), "block", mesh));
                if (j + 1 < this->_lenght - 2)
                    x += this->_spacing;
            }
        } else {
            for (unsigned int j = 0; j < this->_lenght - 2; j++) {
                if (checkCorner(i + 1, j + 1) == 1) {
                    if (j + 1 < this->_lenght - 2)
                        x += this->_spacing;
                    continue;
                }
                if (distribution(_prob) <= prob) {
                    this->_meshes[j + 1][i + 1] = this->setMesh(ctrl, vector3df(x, y, z), "block", mesh);
                    list.push_back(this->_meshes[j + 1][i + 1]);
                }//mapped_mesh.push_back(this->setMesh(ctrl, vector3df(x, y, z), "block", mesh));
                if (j + 1 < this->_lenght - 2)
                    x += this->_spacing;
            }
        }
        if (i + 1 < this->_width - 2)
            z += this->_spacing;
        x = axe[0];
    }
    delete(axe);
    //this->_meshes.push_back(mapped_mesh);
    return mapped_mesh;
}

std::vector<std::shared_ptr<GameObject>> mapGenerator::generateWall(const std::shared_ptr<IrrlichtController> &ctrl, std::vector<std::shared_ptr<IGameObject>> &list, const std::string &pathMesh)
{
    float *axe = (float *) ::operator new (sizeof(float) * 3);
    _pos.getAs3Values(axe);
    float x = axe[0];
    float y = axe[1];
    float z = axe[2];
    IAnimatedMesh *mesh = ctrl->_scene_mgr->getMesh(pathMesh.c_str());
    std::vector<std::shared_ptr<GameObject>> mapped_mesh;

    for (unsigned int i = 0; i < this->_width - 2; i++) {
        if (i % 2 != 0)
            for (unsigned int j = 0; j < this->_lenght - 2; j++) {
                if (j % 2 != 0) {
                    this->_meshes[j + 1][i + 1] = this->setMesh(ctrl, vector3df(x, y, z), "wall", mesh);
                    list.push_back(this->_meshes[j + 1][i + 1]);
                    //printf("push\n");
                }
                //mapped_mesh.push_back(this->setMesh(ctrl, vector3df(x, y, z), "wall", mesh));
                if (j + 1 < this->_lenght - 2)
                    x += this->_spacing;
            }
        if (i + 1 < this->_width - 2)
            z += this->_spacing;
        x = axe[0];
    }
    delete(axe);
    //this->setLightning(mapped_mesh);
    //this->_meshes.push_back(mapped_mesh);
    return mapped_mesh;
}

std::vector<std::shared_ptr<GameObject>> mapGenerator::generate(const std::shared_ptr<IrrlichtController> &ctrl, std::vector<std::shared_ptr<IGameObject>> &list, const std::string &pathMesh, unsigned int prob)
{
    std::random_device dev;
    std::mt19937 _prob(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(1,100);
    float *axe = (float *) ::operator new (sizeof(float) * 3);
    _pos.getAs3Values(axe);
    float x = axe[0];
    float y = axe[1];
    float z = axe[2];
    IAnimatedMesh *mesh = ctrl->_scene_mgr->getMesh(pathMesh.c_str());
    std::vector<std::shared_ptr<GameObject>> mapped_mesh;

    for (unsigned int i = 0; i < this->_width - 2; i++) {
        for (unsigned int j = 0; j < this->_lenght - 2; j++) {
            if (distribution(_prob) <= prob)
                if (this->_meshes[j + 1][i + 1] == NULL) {
                    this->_meshes[j + 1][i + 1] = this->setMesh(ctrl, vector3df(x, y, z), "ground", mesh);
                    list.push_back(this->_meshes[j + 1][i + 1]);
                } else {
                    list.push_back(this->setMesh(ctrl, vector3df(x, y, z), "ground", mesh));
                }
            //    mapped_mesh.push_back(this->setMesh(ctrl, vector3df(x, y, z), "ground", mesh));
            if (j + 1 < this->_lenght - 2)
                x += this->_spacing;
        }
        if (i + 1 < this->_width - 2)
            z += this->_spacing;
        x = axe[0];
    }
    delete(axe);
    return mapped_mesh;
}

vector3d<float> mapGenerator::getPos(void)
{
    return this->_pos;
}

unsigned int mapGenerator::getSize(void)
{
    return this->_width * this->_lenght;
}

float mapGenerator::getSpacing(void)
{
    return this->_spacing;
}

std::shared_ptr<IGameObject> **mapGenerator::getMap(void)
{
    return this->_meshes;
}
