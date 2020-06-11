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
#include <iostream>

namespace fs = std::filesystem;

#define STORAGE_FOLDER_NAME "IndieStudio-storage"
#define STORAGE_FILENAME_EXT ".IndieStudio"

class Storage {
public:
    Storage();

    ~Storage();

    template<typename T>
    bool Load(const std::string &key, T *value) {
        fs::path filepath = constructFileName(key);
        std::ifstream inputFile(filepath);

        if (!inputFile) {
            std::cerr << "Storage: " << "could not read from file " << filepath << "." << std::endl;
            return false;
        }
        inputFile >> *value;
        inputFile.close();
        return true;
    }

    template<typename T>
    bool Save(const std::string &key, T *value) {
        fs::path filepath = constructFileName(key);
        std::ofstream outputFile(filepath);

        if (!outputFile) {
            std::cerr << "Storage: " << "could not write to file " << filepath << "." << std::endl;
            return false;
        }
        outputFile << *value;
        outputFile.close();
        return true;
    }

private:
    fs::path BasePath;

    [[nodiscard]] const fs::path &getBasePath() const;

    fs::path constructBasePath();

    fs::path constructFileName(const std::string &name);
};


#endif //BOMBERMAN_STORAGE_HPP
