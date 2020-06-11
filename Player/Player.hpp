/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include "GameObject.hpp"
#include "MyEventReceiver.hpp"
#include "Collider.hpp"

/* Timing for animations */
#define BEGIN       0
#define WIN_BEGIN   5
#define WIN_END     60
#define POSE_BEGIN  70
#define POSE_END    120
#define DEAD_BEGIN  180
#define DEAD_END    250

/* Path for models */
#define WHITE_PATH  "../assets/players/white.b3d"
#define BLUE_PATH   "../assets/players/blue.b3d"
#define GREEN_PATH  "../assets/players/green.b3d"
#define BLACK_PATH  "../assets/players/black.b3d"

/* Key configuration */
#define LEFT_KEY    "ZQSDE"
#define RIGHT_KEY   "OKLMP"

/* Speed */
#define SPEED 20

class Player : public GameObject {
    public:
        enum BomberType {
            WHITE = 1,
            GREEN = 2,
            BLUE = 3,
            BLACK = 4
        };
        enum KeyConfig {
            LEFT = 1,
            RIGHT = 2
        };
        Player(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        Player(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name, BomberType type, KeyConfig conf);
        ~Player() = default;
        void Init();
        void Init(const std::string texture);
        void Update(std::vector<std::shared_ptr<IGameObject>> obj);
        void Delete();
    private:
        void animationWin(void);
        void animationPose(void);
        void animationDead(void);
        void updateAnimations(void);
        void setPosition(irr::core::vector3df const position);
        f32 GetTime(void);
        BomberType _type;
        KeyConfig _conf;
        bool _alive;
        u32 _old;
        u32 _now;
        f32 _frameDeltaTime;
        irr::scene::IAnimatedMeshSceneNode *_node;
        /* Animations */
        bool _win;
        bool _pose;
        bool _dead;
        //std::shared_ptr<Collider> _collider;
};

#endif /* !PLAYER_HPP_ */