# indie studio

bomberman clone, epitech 2nd year project

## install

supported operating systems:

- Ubuntu 20.04
- Fedora 32
- Windows 10

[Download it now!](https://github.com/x4m3/epitech-indiestudio/releases/tag/1.0.0)

## how to play

### Player 1

- `z`: Go up
- `q`: Go left
- `s`: Go down
- `d`: Go right
- `e`: Place bomb

### Player 2

- `o`: Go up
- `k`: Go left
- `l`: Go down
- `m`: Go right
- `p`: Place bomb

## authors

- Baptiste Mottin
- Peter Bessone
- Philippe Loctaux
- Pierre Barillec
- Rémi Balbous
- Victor Simon

## dependencies

- Irrlicht (version 1.8.4)
- SFML (version 2.5.0)

### install instructions

- linux: install via your package manager
- windows: libraries are shipped (no need to install anything)

you can also build these libraries from source

## building instructions

64 bit only, using cmake

replace `$BUILD_TYPE` with either `Debug` or `Release`

### linux

- `mkdir build && cd build`
- `cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE`
- `make`

### windows

tested with Visual Studio 16 (2019)

- `mkdir build && cd build`
- `cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE`
- open the visual studio solution (.sln) and build the target `bomberman` 