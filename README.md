### The Maze

## overview

The Maze is a 3D Maze game that uses ray casting to render a 2D map into a 3D navigable world!
The Maze was written was written in C using SDL2 library.

### About SDL2

SDL2 is a powerful library used for multimedia and game development. It provides low-level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.

## Instalation
```sh
$ git clone https://github.com/mostsfa538/the_maze.git
```


## How to Compile and Run
- [SDL2](https://www.libsdl.org/download-2.0.php) and is required to compile and use this program
- Compile with `gcc 4.8.4` with the following flags:
    ``gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm -o maze `sdl2-config --cflags` `sdl2-config --libs`` `` OR `make`
- Run the maze: `./maze`

#### Controls
- `W` : move forward
- `S` : move backward
- `A` : rotate camera left
- `D` : rotate camera right
- `/' : enable/disable map
- `F` : toggle fullscreen
- `ESC` : quit


## Demo for maze project

https://drive.google.com/file/d/1eStEf60qLwoZx2aUmuAJob5KdXvQYVrk/view?usp=sharing
