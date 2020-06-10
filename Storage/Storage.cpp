/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/10/2020.
*/

#include "Storage.hpp"

Storage::Storage() {
    this->BasePath = constructBasePath();
}

Storage::~Storage() {

}

fs::path Storage::constructBasePath() {

    fs::path path;

#ifdef STORAGE_DEBUG
    path = fs::current_path() /= STORAGE_FOLDER_NAME;
#endif

#ifdef STORAGE_RELEASE
    path = fs::current_path() /= "release mode";
    // Linux: get env variable $XDG_CONFIG_HOME /= STORAGE_FOLDER_NAME;
    // Windows: get env variable APPDATA /= STORAGE_FOLDER_NAME;
#endif

    return path;
}

const fs::path &Storage::getBasePath() const {
    return BasePath;
}
