/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include <vector>
#include <memory>
#include <string>
#include <irrlicht.h>
#include "IGameObject.hpp"
#include "IrrlichtController.hpp"
#include "GameObject.hpp"
#include "IScene.hpp"

#define FD_GAME_ASSET "map/fd_fight.jpg"

class AScene : public IScene {
    public:
        AScene(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        virtual void Init(void);
        virtual void Update(void);
        virtual void Render(void);
        virtual void Clear(void);
        virtual const std::string &GetId(void);
        virtual IGameObject *GetGameObject(std::string id);
        virtual void AddGameObject(const std::shared_ptr<IGameObject> &obj);
        virtual const irr::video::SColor &GetBackgroundColor(void);
        virtual void SetBackgroundColor(const irr::video::SColor color);
        ~AScene();
    protected:
        std::vector<std::shared_ptr<IGameObject>> _obj_list;
        const std::string _id;
        const std::shared_ptr<IrrlichtController> &_ctrl;
        irr::video::SColor _background_color = irr::video::SColor(0, 0, 0, 0);
        ITexture *_background;
};

#endif /* !ASCENE_HPP_ */