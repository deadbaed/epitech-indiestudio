/*
** EPITECH PROJECT, 2020
** Indie
** File description:
** main
*/

#include <iostream>
#include <SFML/Audio.hpp>

int main(void)
{
    // Load a music to play
    sf::Music music;
    std::cout << "loading music file" << std::endl;
    std::string filename = "../src/abc.ogg";
    if (!music.openFromFile(filename))
        return EXIT_FAILURE;

    // Play the music
    std::cout << "starting to play music" << std::endl;
    music.play();

    while (music.getStatus())
        std::cout << "looping" << std::endl;

    return 0;
}
