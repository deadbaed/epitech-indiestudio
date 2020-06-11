/*
** EPITECH PROJECT, 2020
** epitech-indiestudio
** File description:
** Collider
*/

#include "Collider.hpp"

Collider::Collider(const irr::core::vector3df position, const int width, const int length, const int heigth)
{
    _position = position;
    _heigth = heigth;
    _width = width;
    _length = length;
}

bool Collider::Collide(const Collider col)
{
    irr::core::vector3df v1 = _position;
    irr::core::vector3df v2 = col._position;

    //printf("[1] %0.2f %0.2f %0.2f %d\n", v1.X, v1.Y, v1.Z, _heigth);
    //printf("[2] %0.2f %0.2f %0.2f %d\n", v2.X, v2.Y, v2.Z, col._heigth);

    if ((v1.Y >= v2.Y && v1.Y <= v2.Y + v2.Y + col._heigth) || (v1.Y + _heigth >= v2.Y &&  v1.Y + _heigth <= v2.Y + col._heigth)) {
        if ((v1.X + _width >= v2.X && v1.X + _width <= v2.X + col._width) || (v1.X > v2.X && v1.X <= v2.X + col._width)) {
            if ((v1.Z + _length > v2.Z && v1.Z + _length <= v2.Z + col._length) || (v1.Z > v2.Z && v1.Z <= v2.Z + col._length)) {
                //printf("->%0.2f %0.2f %0.2f %d\n", v1.X, v1.Y, v1.Z, _heigth);
                //printf("->%0.2f %0.2f %0.2f %d\n", v2.X, v2.Y, v2.Z, col._heigth);
                return true;
            }
        }
    }
    return false;
}

Collider &Collider::operator=(const Collider &obj)
{
    return *this;
}

void Collider::SetPosition(const irr::core::vector3df position)
{
    _position = position;
}

Collider::~Collider()
{
}

