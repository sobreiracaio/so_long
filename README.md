# so_long

The **so_long** project is a simple 2D game developed in C using the MiniLibX graphics library. The goal of the game is to guide a character through a maze, collecting items along the way and find an exit. The player must complete the game with the fewest number of moves possible.

## Prerequisites
In order to run this project, MiniLibX installation is needed in project folder. (Link for minilibx here: [Link](https://github.com/42Paris/minilibx-linux)

## Compilation
To compile the project, run:
```shell
make
```
This will compile the source files and generate the `so_long` executable.

## Execution
After compilation, you can run the game using the following command:

```shell
./so_long <map>
```

Replace `<map>` with the path to the map file you want to use. The map file should have the `.ber` extension and follow the format specified in the project. Inside the `assets/maps` folder there are some examples of valid and invalid maps.

## Game Rules
- The player starts at an initial position marked by a character.
- The goal is to collect all the items represented by collectibles (`C`) on the map.
- The player must avoid obstacles represented by walls (`1`).
- The player can move in the up, down, left, and right directions using the arrow keys.
- The game ends when the player collects all the items and finds an exit, otherwise the exit won't be available.
- The number of moves made by the player is displayed on the terminal.

## Controls
- `W`, `S`, `D`, `A` and `Arrow keys`: move the character in the up, down, left, and right directions.
- `ESC` key: exit the game.

