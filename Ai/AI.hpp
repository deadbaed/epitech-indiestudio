/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** Player
*/

#ifndef AI_HPP_
#define AI_HPP_

#include <iostream>
#include "GameObject.hpp"
#include "MyEventReceiver.hpp"
#include "Collider.hpp"
#include "Bomb.hpp"

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

class AI : public GameObject {
    public:
        enum direction_e {
            IDLE = 0,
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
        AI(const std::shared_ptr<IrrlichtController> &ctrl, const std::string name);
        ~AI() = default;
        void Init();
        void Update(std::vector<std::shared_ptr<IGameObject>> &obj);
        void Delete();
        const IGameObject::type_e GetType(void);
    private:
        void animationWin(void);
        void animationPose(void);
        void animationDead(void);
        void updateAnimations(void);
        void setPosition(irr::core::vector3df const position);
        void setRotation(irr::core::vector3df const rotation);
        bool calculateCollision(void);
        void poseBomb(void);
        void UpdateDirection(void);
        f32 GetTime(void);

        bool _alive;
        u32 _old;
        u32 _now;
        f32 _frameDeltaTime;
        irr::scene::IAnimatedMeshSceneNode *_node;
        /* Animations */
        bool _win;
        bool _pose;
        bool _dead;
        /* Bomb increase */
        int _nb;
        std::vector<std::shared_ptr<IGameObject>> *_obj;
        AI::direction_e _direction;
};

#endif /* !AI_HPP_ */