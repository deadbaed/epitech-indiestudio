/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/14/20
*/

#include <iostream>
#include "AssetSelector.hpp"

fs::path AssetSelector(const std::string &asset) {
    fs::path AssetPath;

#if defined(ASSET_SELECTOR_RELEASE) && defined(__linux__)
    if (fs::current_path() == std::getenv("HOME"))
        AssetPath = "/usr/share/IndieStudio/assets";
    else
        std::cerr << "not in installed mode (with package)" << std::endl;
#endif

#if defined(ASSET_SELECTOR_RELEASE) && defined(_WIN32)
    std::cout << "win32 implementation will go here" << std::endl;
#endif

    if (AssetPath.empty()) {
        AssetPath = fs::current_path();
        std::cout << "current path: " << AssetPath << std::endl;
        fs::path tmp = AssetPath;
        tmp /= "assets";
        if (!fs::exists(tmp)) {
            std::cout << tmp << "does not exist" << std::endl;
            AssetPath = AssetPath.parent_path();
        }
    }

    std::cout << "current path: " << AssetPath << std::endl;
    AssetPath /= asset;

    return AssetPath;
}