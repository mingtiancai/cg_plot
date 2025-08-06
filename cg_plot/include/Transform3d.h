#ifndef TRANSFORM3D_H
#define TRANSFORM3D_H

#include "Point3d.h"
#include "Vector3d.h"

class Transform3d {
public:
    Transform3d() {
        // Initialize to identity matrix
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }

    Transform3d(const double mat[4][4]) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] = mat[i][j];
            }
        }
    }   

    Transform3d(const Transform3d &other) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    Transform3d &operator=(const Transform3d &other) {
        if (this != &other) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }
        return *this;
    }

    ~Transform3d() {}

    void Multiply(const double mat[4][4]) {
        double result[4][4] = {0};
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    result[i][j] += mat[i][k]*matrix[k][j] ;
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] = result[i][j];
            }
        }
    }

    void RotateX(double angle) {
        double rad = angle * 3.14159265358979323846 / 180.0;
        double c = cos(rad);
        double s = sin(rad);
        double rotation[4][4] = {
            {1, 0, 0, 0},
            {0, c, -s, 0},
            {0, s, c, 0},
            {0, 0, 0, 1}
        };
        Multiply(rotation);
    }

    void RotateY(double angle) {
        double rad = angle * 3.14159265358979323846 / 180.0;
        double c = cos(rad);
        double s = sin(rad);
        double rotation[4][4] = {
            {c, 0, s, 0},
            {0, 1, 0, 0},
            {-s, 0, c, 0},
            {0, 0, 0, 1}
        };
        Multiply(rotation);
    }

    void RotateZ(double angle) {
        double rad = angle * 3.14159265358979323846 / 180.0;
        double c = cos(rad);
        double s = sin(rad);
        double rotation[4][4] = {
            {c, -s, 0, 0},
            {s, c, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        };
        Multiply(rotation);
    }
    
    void Translate(double tx, double ty, double tz) {
        double translation[4][4] = {
            {1, 0, 0, tx},
            {0, 1, 0, ty},
            {0, 0, 1, tz},
            {0, 0, 0, 1}
        };
        Multiply(translation);
    }

    friend std::ostream &operator<<(std::ostream &os, const Transform3d &transform) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                os << transform.matrix[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    Point3d TransformPoint(const Point3d &point) const {
        double x = point.GetX();
        double y = point.GetY();
        double z = point.GetZ();
        double w = 1.0; // Homogeneous coordinate

        double newX = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3] * w;
        double newY = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3] * w;
        double newZ = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3] * w;

        return Point3d(newX, newY, newZ);
    }

    Vector3d TransformVector(const Vector3d &vector) const {
        double x = vector.GetX();
        double y = vector.GetY();
        double z = vector.GetZ();

        double newX = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
        double newY = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
        double newZ = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;

        return Vector3d(newX, newY, newZ);
    }

private:
    double matrix[4][4]; // 4x4 transformation matrix
};


#endif