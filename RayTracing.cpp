#include <iostream>
#include <cmath>

const int WIDTH = 80;
const int HEIGHT = 40;

const double sphere_radius = 10.0;
const double sphere_center_x = WIDTH / 2;
const double sphere_center_y = HEIGHT / 2;
const double sphere_center_z = 20.0;

bool isPointInsideSphere(double x, double y, double z) {
    double distance_squared = (x - sphere_center_x) * (x - sphere_center_x) +
                              (y - sphere_center_y) * (y - sphere_center_y) +
                              (z - sphere_center_z) * (z - sphere_center_z);
    return distance_squared <= (sphere_radius * sphere_radius);
}

int main() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (isPointInsideSphere(x, y, 0))
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
