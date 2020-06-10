/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/10/2020.
*/

#include "Storage.hpp"

Storage::Storage() {
    this->BasePath = fs::current_path() /= "indie-settings";
}

Storage::~Storage() {

}

fs::path Storage::getBasePath() const {
    // TODO: debug or release
    // Debug: fs::current_path() /= "indie-settings";
    // Release: Linux: get env variable $XDG_CONFIG_HOME /= "indie-settings";

    return this->BasePath;
}