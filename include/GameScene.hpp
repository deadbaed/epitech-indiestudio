/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include <vector>
#include <memory>
#include <string>
#include "GameObject.hpp"
#include "IrrlichtController.hpp"

class GameScene {
    public:
        GameScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        virtual void Init(void);
        virtual void Update(void);
        virtual void Render(void);
        virtual void Delete(void);
        virtual const std::string &GetId(void);
        virtual void AddGameObject(const std::shared_ptr<GameObject> &obj);
        ~GameScene();
    protected:
        std::vector<std::shared_ptr<GameObject>> _obj_list;
        const std::string _id;
        const std::shared_ptr<IrrlichtController> &_ctrl;

};

#endif /* !GAMESCENE_HPP_ */
