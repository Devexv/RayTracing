#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

constexpr int consoleWidth = 80;
constexpr int consoleHeight = 24;

const char sphereChars[] = {' ', '.', ':', ';', 'o', '8', '@'};

struct Vec3 {
    float x, y, z;

    Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    float dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vec3 normalize() const {
        float len = length();
        return Vec3(x / len, y / len, z / len);
    }
};

class Sphere {
private:
    Vec3 center;
    float radius;

public:
    Sphere(const Vec3& center_, float radius_) : center(center_), radius(radius_) {}

    bool intersects(const Vec3& rayOrigin, const Vec3& rayDir, float& t) const {
        Vec3 oc = rayOrigin - center;
        float a = rayDir.dot(rayDir);
        float b = 2.0f * oc.dot(rayDir);
        float c = oc.dot(oc) - radius * radius;
        float discriminant = b * b - 4 * a * c;

        if (discriminant < 0) return false;

        float t0 = (-b - std::sqrt(discriminant)) / (2 * a);
        float t1 = (-b + std::sqrt(discriminant)) / (2 * a);

        if (t0 > t1) std::swap(t0, t1);

        if (t0 < 0) {
            t0 = t1; // if t0 is negative, let's use t1 instead
            if (t0 < 0) return false; // both t0 and t1 are negative
        }

        t = t0;
        return true;
    }
};

void clearConsole() {
    std::cout << "\x1B[2J\x1B[H";
}

char getSphereChar(float t) {
    int index = static_cast<int>(t * (sizeof(sphereChars) / sizeof(sphereChars[0])));
    index = std::min(std::max(index, 0), static_cast<int>(sizeof(sphereChars) / sizeof(sphereChars[0])) - 1);
    return sphereChars[index];
}

int main() {
    const int numFrames = 100;
    const float angleDelta = 2 * M_PI / numFrames;
    const Vec3 rayOrigin(consoleWidth / 2, consoleHeight / 2, -100); // Position of the "camera"

    Sphere sphere(Vec3(consoleWidth / 2, consoleHeight / 2, 0), 10);

    for (int frame = 0; frame < numFrames; ++frame) {
        clearConsole();

        float angle = angleDelta * frame;
        Vec3 rayDir(std::cos(angle), std::sin(angle), 0);

        for (int y = 0; y < consoleHeight; ++y) {
            for (int x = 0; x < consoleWidth; ++x) {
                float t;
                if (sphere.intersects(rayOrigin, rayDir, t)) {
                    char sphereChar = getSphereChar(t);
                    std::cout << sphereChar;
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << '\n';
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
