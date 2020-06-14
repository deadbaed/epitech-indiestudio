# indie studio

epitech second year project

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

### linux

- `mkdir build && cd build`
- `cmake ..`
- `make`

### windows

tested with Visual Studio 16 (2019)

- `mkdir build && cd build`
- `cmake ..`
- open the visual studio solution (.sln) and build the target `bomberman` 