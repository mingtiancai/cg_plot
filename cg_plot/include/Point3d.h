#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>

class Point3d{

    public:
        // Constructors
        Point3d() : x_(0), y_(0), z_(0) {}
        Point3d(double x, double y, double z) : x_(x), y_(y), z_(z) {}

        Point3d(const Point3d &other) : x_(other.x_), y_(other.y_), z_(other.z_) {} // Copy constructor
        Point3d &operator=(const Point3d &other)
        { // Copy assignment operator
            if (this != &other)
            {
                x_ = other.x_;
                y_ = other.y_;
                z_ = other.z_;
            }
            return *this;
        }

        ~Point3d() {} // Destructor

        // Getters
        double GetX() const { return x_; }
        double GetY() const { return y_; }
        double GetZ() const { return z_; }

        void setX(double x) { this->x_ = x; }
        void setY(double y) { this->y_ = y; }
        void setZ(double z) { this->z_ = z; }

        friend std::ostream &operator<<(std::ostream &os, const Point3d &point) {
            os << "Point3d(" << point.x_ << ", " << point.y_ << ", " << point.z_ << ")";
            return os;
        }
    private:
        double x_, y_, z_;
};

#endif