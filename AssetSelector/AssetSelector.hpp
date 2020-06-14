/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/14/20
*/

#ifndef BOMBERMAN_ASSETSELECTOR_HPP
#define BOMBERMAN_ASSETSELECTOR_HPP

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

fs::path AssetSelector(const std::string &asset);

#endif //BOMBERMAN_ASSETSELECTOR_HPP
