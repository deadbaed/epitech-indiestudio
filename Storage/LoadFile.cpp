/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/11/2020.
*/

#include <fstream>
#include <iostream>
#include "Storage.hpp"

bool Storage::LoadFile(const std::string &FileName, std::ifstream *inputFile) {
    fs::path filepath = constructFileName(FileName);

    inputFile->open(filepath);

    if (!inputFile->is_open()) {
        std::cerr << "Storage: " << "could not read from file " << filepath << "." << std::endl;
        return false;
    }

    return true;
}
