<a id="top"></a>

![Demo](./demo/demo.gif)

# cub3D
`cub3D` is a 3D game engine project inspired by the classic Wolfenstein 3D. Developed in C, it uses raycasting techniques to render a 2D map as a 3D environment, providing an immersive first-person perspective. The project emphasizes low-level graphics programming and game mechanics implementation.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)

## Introduction
This project is a small 3D game engine that showcases fundamental concepts of computer graphics, such as raycasting, texture mapping, and sprite rendering. Players navigate through a maze-like environment with the goal of exploring and interacting with the virtual world. It uses the MinilibX library for graphics rendering and input handling, and it runs on macOS or Linux systems.

## Features
- **3D Raycasting Engine:** Converts 2D maps into a first-person 3D experience.

- **Texture Mapping:** Realistic walls, floors, and ceilings with detailed textures.

- **Interactive Doors and Objects:** Open doors and interact with the environment.

- **Dynamic Sprite Rendering and Animation:** Adds animated objects and effects for a lively experience.

- **Dialogs:** In-game conversations.

- **Minimap:** A handy minimap to guide players through the maze.

- **Custom Maps:** Load your own .cub files to create unique environments.

- **Keyboard and Mouse Controls:** Smooth and responsive player movement and camera rotation.

- **Error Handling:** Ensures map validity and provides meaningful feedback.

- **Cross-Platform Compatibility:** Runs on both macOS and Linux.

- **Fuzzy Mushroom Effect:** Eat a special mushroom to experience a blurry "trippy" screen effect.

## Technologies Used

### Programming Language
- **C:** Provides precise control over memory and system-level operations.

### Libraries
- **MinilibX:** Lightweight library for rendering and handling user input.
- **Math Library (libm):** Supports mathematical computations for raycasting.

### Development Tools
- **Make:** Automates the build process.

## Installation
1. Clone this repository to your local machine:
	```sh
	git clone https://github.com/KarlQuerel/42-cub3.git
	cd 42-cub3D
	```

2. Compile the program using the Makefile:

	```sh
	make bonus
	```

## Usage
Run the game with a valid .cub map file, located in the `maps` directory:
```sh
./cub3D_bonus maps/bonus/map_1.cub
```

## Controls
- **W/A/S/D or Up/Down Arrows:** Move forward, left, backward, and right.
- **Mouse or Left/Right Arrows:** Rotate the camera.
- **O:** Open and close doors.
- **ESC:** Exit the game.

For more information, refer to the [subject PDF](https://github.com/KarlQuerel/42-cub3D/blob/main/docs/en.subject.pdf).

[Back to Top](#top)