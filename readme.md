# indie studio

epitech second year project

## credits

- Baptiste Mottin
- Peter Bessone
- Philippe Loctaux
- Pierre Barillec
- Rémi Balbous
- Victor Simon

## dependencies

- Irrlicht (version 1.8.4)
- SFML (version 2.5.0)

please note that only the audio component is used from the SFML.

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