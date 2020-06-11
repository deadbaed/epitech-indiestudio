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
#include <fstream>

namespace fs = std::filesystem;

#define STORAGE_FOLDER_NAME "IndieStudio-storage"
#define STORAGE_FILENAME_EXT ".IndieStudio"

class Storage {
public:
    Storage();

    ~Storage();

    template<typename T>
    bool Load(const std::string &key, T *value) {
        std::ifstream inputFile;
        bool ret = LoadFile(key, &inputFile);

        if (!ret)
            return false;

        inputFile >> *value;

        inputFile.close();

        return true;
    }

private:
    fs::path BasePath;

    [[nodiscard]] const fs::path &getBasePath() const;

    fs::path constructBasePath();

    fs::path constructFileName(const std::string &name);

    bool LoadFile(const std::string &FileName, std::ifstream *inputFile);
};


#endif //BOMBERMAN_STORAGE_HPP
