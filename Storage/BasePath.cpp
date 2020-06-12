/*
** EPITECH PROJECT, 2020
** bomberman
** File description:
** Created by phil on 6/11/2020.
*/

#include "Storage.hpp"

#if defined(STORAGE_RELEASE) && defined(_WIN32)
#include <windows.h>
#include <shlobj.h>
#endif

fs::path Storage::constructBasePath() {

    fs::path path;

#ifdef STORAGE_DEBUG
    /* Debug implementation, use only for development */

    path = fs::current_path();
#endif

#if defined(STORAGE_RELEASE) && defined(_WIN32)
    /* Windows implementation */

    PWSTR path_tmp;

    /* Attempt to get user's AppData folder
     *
     * Microsoft Docs:
     * https://docs.microsoft.com/en-us/windows/win32/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath
     * https://docs.microsoft.com/en-us/windows/win32/shell/knownfolderid
     */
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
#endif

#if defined(STORAGE_RELEASE) && defined(__linux__)
    /* Linux implementation */

    /* Construct storage path with user's "HOME" folder
     * following the XDG Base Directory Specification:
     * https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html
     */

    path = std::getenv("HOME");
    path /= ".config";
#endif

#if defined(_WIN32)
    /* If we are on windows and the path is not present already,
     * that means Visual Studio is being used to build and it sucks
     *
     * Use current folder as a base path
     */

    if (path.empty())
        path = fs::current_path();
#endif

    /* If no path is defined, operating system is not supported */
    if (path.empty())
        return path;

    /* Append storage folder name to base path */
    path /= STORAGE_FOLDER_NAME;

    return path;
}

const fs::path &Storage::getBasePath() const {
    return BasePath;
}
