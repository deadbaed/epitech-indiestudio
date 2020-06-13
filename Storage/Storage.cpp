/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/10/2020.
*/

#include "Storage.hpp"
#include "Error.hpp"
#include <iostream>

Storage::Storage() {
    BasePath = constructBasePath();

    if (BasePath.empty()) {
        std::cerr << "Storage: " << "ERROR! Could not find your operating system" << std::endl;
        std::cerr << "Storage: " << "ERROR! Can't recover, Aborting now" << std::endl;
        throw StorageError("Could not find your operating system");
        //abort();
    }

    if (!fs::exists(BasePath)) {
        fs::create_directories(BasePath);
        std::cout << "Storage: " << "created folder " << BasePath << std::endl;
    }
}

Storage::~Storage() {

}
