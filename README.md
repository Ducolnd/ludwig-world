
# ludwig-world

Ludwig World is an open world roguelike game. Procedually generated, infinite worlds in 3d space with a 2d view from atop. ECS (EnTT) used for entities, Perlin noise (FastNoise) used for world generation and SFML used for graphics.

## Screenshots
![Screenshot]
(https://imgur.com/a/1HgLusv)

## Installing
#### Installing from source Linux

 1. `git clone https://github.com/Ducolnd/ludwig-world`
 2. `sudo  apt-get  install libsfml-dev`
 3. Navigate to repository `cd ludwig-world`
 4. Make build directory `mkdir build & cd build`
 5. Make using `cmake ..` then `make`
 6. You can now run the game by typing `./ludwig_world`

#### Installing from source Windows
Needs testing

#### Installing from source Mac
Needs testing

## Contributing
Contributing is welcome. A few things that need work:
- World generation
- Entites
- UI elements (loading screen and such)
- Faster perlin noise
- Entity AI (pathfinding etc.)
- CMake
