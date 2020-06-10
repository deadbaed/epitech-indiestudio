/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/10/2020.
*/

#ifndef BOMBERMAN_STORAGE_HPP
#define BOMBERMAN_STORAGE_HPP

#include <string>
#include <filesystem>

namespace fs = std::filesystem;

#define STORAGE_FOLDER_NAME "IndieStudio-storage"

class Storage {
public:
    Storage();

    ~Storage();

    fs::path constructBasePath();

    const fs::path &getBasePath() const;

private:
    fs::path BasePath;
};


#endif //BOMBERMAN_STORAGE_HPP
