#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath> // For sqrt function
#include <iostream> // For std::ostream

class Vector3d
{
public:
    // Constructors
    Vector3d() : x_(0), y_(0), z_(0) {}
    Vector3d(double x, double y, double z) : x_(x), y_(y), z_(z) {}

    Vector3d(const Vector3d &other) : x_(other.x_), y_(other.y_), z_(other.z_) {} // Copy constructor
    Vector3d &operator=(const Vector3d &other)
    { // Copy assignment operator
        if (this != &other)
        {
            x_ = other.x_;
            y_ = other.y_;
            z_ = other.z_;
        }
        return *this;
    }

    Vector3d(const Vector3d &p0, const Vector3d &p1)
    { // Constructor from two points
        x_ = p1.x_ - p0.x_;
        y_ = p1.y_ - p0.y_;
        z_ = p1.z_ - p0.z_;
    }

    double Magnitude() const
    { // Calculate the magnitude of the vector
        return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
    }

    Vector3d Normalize() const
    { // Normalize the vector
        double mag = Magnitude();
        if (mag < 1e-6)
            return Vector3d(0, 0, 0); // Avoid division by zero
        return Vector3d(x_ / mag, y_ / mag, z_ / mag);
    }

    ~Vector3d() {} // Destructor

    // Getters
    double GetX() const { return x_; }
    double GetY() const { return y_; }
    double GetZ() const { return z_; }

    // Setters
    void SetX(double x) { this->x_ = x; }
    void SetY(double y) { this->y_ = y; }
    void SetZ(double z) { this->z_ = z; }

    friend Vector3d operator+(const Vector3d &a, const Vector3d &b)
    {
        return Vector3d(a.GetX() + b.GetX(), a.GetY() + b.GetY(), a.GetZ() + b.GetZ());
    }

    friend Vector3d operator-(const Vector3d &a, const Vector3d &b)
    {
        return Vector3d(a.GetX() - b.GetX(), a.GetY() - b.GetY(), a.GetZ() - b.GetZ());
    }

    friend Vector3d operator*(const Vector3d &v, double scalar)
    {
        return Vector3d(v.GetX() * scalar, v.GetY() * scalar, v.GetZ() * scalar);
    }

    friend Vector3d operator*(double scalar, const Vector3d &v)
    {
        return Vector3d(v.GetX() * scalar, v.GetY() * scalar, v.GetZ() * scalar);
    }

    friend double Dot(const Vector3d &a, const Vector3d &b)
    {
        return a.GetX() * b.GetX() + a.GetY() * b.GetY() + a.GetZ() * b.GetZ();
    }

    friend Vector3d Cross(const Vector3d &a, const Vector3d &b)
    {
        return Vector3d(a.GetY() * b.GetZ() - a.GetZ() * b.GetY(),
                        a.GetZ() * b.GetX() - a.GetX() * b.GetZ(),
                        a.GetX() * b.GetY() - a.GetY() * b.GetX());
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3d& v)
    {
        os << "Vector3d(x=" << v.x_ << ", y=" << v.y_ << ", z=" << v.z_ << ")";
        return os;
    }

private:
    double x_, y_, z_;
};

#endif