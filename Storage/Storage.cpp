/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/10/2020.
*/

#include "Storage.hpp"
#include <iostream>

Storage::Storage() {
    BasePath = constructBasePath();

    if (BasePath.empty())
        abort();

    if (!fs::exists(BasePath)) {
        fs::create_directories(BasePath);
        std::cout << "Storage: " << "created folder " << BasePath << std::endl;
    }
}

Storage::~Storage() {

}
