/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/10/2020.
*/

#include "Storage.hpp"

#include <iostream>

#if defined(STORAGE_RELEASE) && defined(_WIN32)
#include <windows.h>
#include <shlobj.h>
#endif

Storage::Storage() {
    this->BasePath = constructBasePath();

    if (this->BasePath.empty() == true)
        abort();
}

Storage::~Storage() {

}

fs::path Storage::constructBasePath() {

    fs::path path;

#ifdef STORAGE_DEBUG
    /* Debug implementation, use only for development */
    path = fs::current_path() /= STORAGE_FOLDER_NAME;
#endif

#if defined(STORAGE_RELEASE) && defined(_WIN32)
    /* Windows implementation */

    PWSTR path_tmp;

    /* Attempt to get user's AppData folder */
    auto get_folder_path_ret = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &path_tmp);

    /* Error check */
    if (get_folder_path_ret != S_OK) {
        CoTaskMemFree(path_tmp);
        return path;
    }

    /* Convert the Windows path type to a C++ path */
    path = path_tmp;

    /* Free memory :) */
    CoTaskMemFree(path_tmp);

    path /= STORAGE_FOLDER_NAME;
#endif

#if defined(STORAGE_RELEASE) && defined(__linux__)
    // Linux: get env variable $XDG_CONFIG_HOME /= STORAGE_FOLDER_NAME;
#endif

    return path;
}

const fs::path &Storage::getBasePath() const {
    return BasePath;
}
