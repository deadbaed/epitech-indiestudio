/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include <string>
#include <memory>
#include "IGameObject.hpp"
#include "GameObject.hpp"

class IScene {
    public:
        virtual ~IScene() = default;
        virtual void Init(void) = 0;
        virtual void Update(void) = 0;
        virtual void Render(void) = 0;
        virtual void Clear(void) = 0;
        virtual const std::string &GetId(void) = 0;
        virtual IGameObject *GetGameObject(std::string id) = 0;
        virtual void AddGameObject(const std::shared_ptr<IGameObject> &obj) = 0;
        virtual const irr::video::SColor &GetBackgroundColor(void) = 0;
        virtual void SetBackgroundColor(const irr::video::SColor color) = 0;
    protected:
    private:
};

#endif /* !ISCENE_HPP_ */
