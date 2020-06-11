/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** Collider
*/

#ifndef COLLIDER_HPP_
#define COLLIDER_HPP_

#include "irrlicht.h"

class Collider {
    public:
        Collider(const irr::core::vector3df position, const int width, const int length, const int heigth);
        //bool operator==(const Collider col);
        bool Collide(const Collider col);
        Collider &operator=(const Collider &col);
        void SetPosition(const irr::core::vector3df position);
        ~Collider();
    public:
        irr::core::vector3df _position;
        int _length;
        int _width;
        int _heigth;

};

#endif /* !COLLIDER_HPP_ */
