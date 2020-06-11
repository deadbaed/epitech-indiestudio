/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/11/2020.
*/

#include "Storage.hpp"

fs::path Storage::constructFileName(const std::string &name) {
    fs::path filepath = getBasePath();

    filepath /= name + STORAGE_FILENAME_EXT;

    return filepath;
}
