# RayTracing

# Console Sphere Renderer

This is a simple C++ program that renders a sphere within the console window using ASCII characters.

## Description

The program utilizes basic geometry to determine whether each pixel in the console window falls within the volume of a sphere. If a pixel is inside the sphere, it is represented by a character (e.g., '*'); otherwise, it is an empty space.

## Prerequisites

To compile and run this program, you need:

- C++ compiler (supporting C++11 or later)
- Standard C++ library

## How to Use

1. Clone this repository or download the source code files.
2. Compile the program using your preferred C++ compiler.
3. Run the compiled executable.
4. You will see the sphere rendered in the console window.

## Configuration

You can customize the sphere's properties such as radius and center coordinates by modifying the constants defined in the source code.

```cpp
// Define the dimensions of the console window
const int WIDTH = 80;
const int HEIGHT = 40;

// Define the sphere parameters
const double sphere_radius = 10.0;
const double sphere_center_x = WIDTH / 2;
const double sphere_center_y = HEIGHT / 2;
const double sphere_center_z = 20.0;



You can include this `README.md` file in your project repository alongside your source code. Feel free to modify it as needed to provide additional information or instructions specific to your project.
