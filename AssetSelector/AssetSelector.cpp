/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/14/20
*/

#include "AssetSelector.hpp"

fs::path AssetSelector(const std::string &asset) {
    fs::path AssetPath;

#if defined(ASSET_SELECTOR_RELEASE) && defined(__linux__)
    if (fs::current_path() == std::getenv("HOME"))
        AssetPath = "/usr/share/IndieStudio/assets";
#endif

#if defined(ASSET_SELECTOR_RELEASE) && defined(_WIN32)
    /* win32 implementation will go here */
#endif

    if (AssetPath.empty()) {
        /* look for the assets folder in current directory */
        AssetPath = fs::current_path() /= "assets";

        if (!fs::exists(AssetPath)) {
            /* try the parent directory */
            AssetPath = fs::current_path().parent_path() /= "assets";
        }
    }

    AssetPath /= asset;

    return AssetPath;
}