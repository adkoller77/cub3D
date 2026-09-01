*This project has been created as part of the 42 curriculum by adnajja, hudescam.*

# cub3D

## Description

cub3D is a graphical project from the 42 curriculum inspired by the
world-famous Wolfenstein 3D game.

The goal of the project is to create a dynamic first-person view inside a
maze using ray-casting principles. The program parses a `.cub` scene
description file, loads the required textures and colors, and renders the
maze from the player's point of view.

The project was developed in C using MiniLibX and Libft.

### Features

- First-person 3D rendering using raycasting
- Four different wall textures for North, South, East and West walls
- Customizable floor and ceiling colors
- `.cub` scene file parsing
- Map validation
- Player spawning and orientation
- WASD movement
- Left and right arrow keys for camera rotation
- Clean window and program termination
- Error handling for invalid configurations

## Instructions

### Requirements

The project requires:

- `cc`
- MiniLibX
- Libft
- the math library

### Compilation

Clone the repository and compile the project with:

```bash
make
```

### Execution

Run the program with a `.cub` map file:

```bash
./cub3D ./maps/map.cub
```

### Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `A` | Move left |
| `S` | Move backward |
| `D` | Move right |
| `←` | Look left |
| `→` | Look right |
| `ESC` | Exit the program |

## Resources

### Raycasting

The main technical concept behind this project is raycasting. It is used
to determine the distance between the player and the walls in order to
create the illusion of a 3D environment from a 2D map.

Useful references include:

- Wolfenstein 3D and its original raycasting approach
- Lode's Computer Graphics Tutorial — Raycasting
- MiniLibX documentation
- Linux `man` pages for system calls and library functions
- 42 Libft documentation and project resources

### AI Usage

AI tools were mainly used as a debugging aid during development.

They were used to help identify and understand bugs, investigate unexpected
behaviour, and discuss possible solutions when problems were encountered.
The generated suggestions were reviewed, adapted and tested by the authors.

## Authors

- **adnajja**
- **hudescam**
