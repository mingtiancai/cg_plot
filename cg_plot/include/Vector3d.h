#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath> // For sqrt function
#include <iostream> // For std::ostream

class Vector3d
{
public:
    // Constructors
    Vector3d() : x(0), y(0), z(0) {}
    Vector3d(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3d(const Vector3d &other) : x(other.x), y(other.y), z(other.z) {} // Copy constructor
    Vector3d &operator=(const Vector3d &other)
    { // Copy assignment operator
        if (this != &other)
        {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    Vector3d(const Vector3d &p0, const Vector3d &p1)
    { // Constructor from two points
        x = p1.x - p0.x;
        y = p1.y - p0.y;
        z = p1.z - p0.z;
    }

    double Magnitude() const
    { // Calculate the magnitude of the vector
        return sqrt(x * x + y * y + z * z);
    }

    Vector3d Normalize() const
    { // Normalize the vector
        double mag = Magnitude();
        if (mag < 1e-6)
            return Vector3d(0, 0, 0); // Avoid division by zero
        return Vector3d(x / mag, y / mag, z / mag);
    }

    ~Vector3d() {} // Destructor

    // Getters
    double GetX() const { return x; }
    double GetY() const { return y; }
    double GetZ() const { return z; }

    // Setters
    void SetX(double x) { this->x = x; }
    void SetY(double y) { this->y = y; }
    void SetZ(double z) { this->z = z; }

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
        os << "Vector3d(x=" << v.x << ", y=" << v.y << ", z=" << v.z << ")";
        return os;
    }

private:
    double x, y, z;
};

#endif