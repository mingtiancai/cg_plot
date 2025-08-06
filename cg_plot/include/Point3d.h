#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>

class Point3d{

    public:
        // Constructors
        Point3d() : x(0), y(0), z(0) {}
        Point3d(double x, double y, double z) : x(x), y(y), z(z) {}

        Point3d(const Point3d &other) : x(other.x), y(other.y), z(other.z) {} // Copy constructor
        Point3d &operator=(const Point3d &other)
        { // Copy assignment operator
            if (this != &other)
            {
                x = other.x;
                y = other.y;
                z = other.z;
            }
            return *this;
        }

        ~Point3d() {} // Destructor

        // Getters
        double GetX() const { return x; }
        double GetY() const { return y; }
        double GetZ() const { return z; }

        void setX(double x) { this->x = x; }
        void setY(double y) { this->y = y; }
        void setZ(double z) { this->z = z; }

        friend std::ostream &operator<<(std::ostream &os, const Point3d &point) {
            os << "Point3d(" << point.x << ", " << point.y << ", " << point.z << ")";
            return os;
        }
    private:
        double x, y, z;
};

#endif