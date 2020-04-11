//
// Created by admin on 11.04.2020.
//

#include "iostream"
#include "matrix.h"
#include "vector.h"


Matrix3D::Matrix3D() : Matrix3D(0, 0, 0, 0, 0, 0, 0, 0, 0) {}

Matrix3D::Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    matrix[0][0] = a, matrix[0][1] = b, matrix[0][2] = c,
    matrix[1][0] = d, matrix[1][1] = e, matrix[1][2] = f,
    matrix[2][0] = g, matrix[2][1] = h, matrix[2][2] = i;
}

Matrix3D::~Matrix3D() {
}

Matrix3D Matrix3D::operator*(const double a) {
    return Matrix3D(matrix[0][0] * a, matrix[0][1] * a, matrix[0][2] * a,
                    matrix[1][0] * a, matrix[1][1] * a, matrix[1][2] * a,
                    matrix[2][0] * a, matrix[2][1] * a, matrix[2][2] * a);
}

Matrix3D Matrix3D::operator+(const Matrix3D &m) {
    return Matrix3D(matrix[0][0] + m.matrix[0][0], matrix[0][1] + m.matrix[0][1], matrix[0][2] + m.matrix[0][2],
                    matrix[1][0] + m.matrix[1][0], matrix[1][1] + m.matrix[1][1], matrix[1][2] + m.matrix[1][2],
                    matrix[2][0] + m.matrix[2][0], matrix[2][1] + m.matrix[2][1], matrix[2][2] + m.matrix[2][2]);
}

Matrix3D Matrix3D::operator-(const Matrix3D &m) {
    return Matrix3D(matrix[0][0] - m.matrix[0][0], matrix[0][1] - m.matrix[0][1], matrix[0][2] - m.matrix[0][2],
                    matrix[1][0] - m.matrix[1][0], matrix[1][1] - m.matrix[1][1], matrix[1][2] - m.matrix[1][2],
                    matrix[2][0] - m.matrix[2][0], matrix[2][1] - m.matrix[2][1], matrix[2][2] - m.matrix[2][2]);
}

Matrix3D Matrix3D::operator*(const Matrix3D &m) {
    return Matrix3D(matrix[0][0] * m.matrix[0][0] + matrix[0][1] * m.matrix[1][0] + matrix[0][2] * m.matrix[2][0],
                    matrix[0][0] * m.matrix[0][1] + matrix[0][1] * m.matrix[1][1] + matrix[0][2] * m.matrix[2][1],
                    matrix[0][0] * m.matrix[0][2] + matrix[0][1] * m.matrix[1][2] + matrix[0][2] * m.matrix[2][2],
                    matrix[1][0] * m.matrix[0][0] + matrix[1][1] * m.matrix[1][0] + matrix[1][2] * m.matrix[2][0],
                    matrix[1][0] * m.matrix[0][1] + matrix[1][1] * m.matrix[1][1] + matrix[1][2] * m.matrix[2][1],
                    matrix[1][0] * m.matrix[0][2] + matrix[1][1] * m.matrix[1][2] + matrix[1][2] * m.matrix[2][2],
                    matrix[2][0] * m.matrix[0][0] + matrix[2][1] * m.matrix[1][0] + matrix[2][2] * m.matrix[2][0],
                    matrix[2][0] * m.matrix[0][1] + matrix[2][1] * m.matrix[1][1] + matrix[2][2] * m.matrix[2][1],
                    matrix[2][0] * m.matrix[0][2] + matrix[2][1] * m.matrix[1][2] + matrix[2][2] * m.matrix[2][2]);
}

Vector3D Matrix3D::operator*(const Vector3D &v) {
    return Vector3D(matrix[0][0] * v.getX() + matrix[0][1] * v.getY() + matrix[0][2] * v.getZ(),
                    matrix[1][0] * v.getX() + matrix[1][1] * v.getY() + matrix[1][2] * v.getZ(),
                    matrix[2][0] * v.getX() + matrix[2][1] * v.getY() + matrix[2][2] * v.getZ());
}

double Matrix3D::det() {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
}

Matrix3D operator*(const double a, const Matrix3D &m) {
    return Matrix3D(m.matrix[0][0] * a, m.matrix[0][1] * a, m.matrix[0][2] * a,
                    m.matrix[1][0] * a, m.matrix[1][1] * a, m.matrix[1][2] * a,
                    m.matrix[2][0] * a, m.matrix[2][1] * a, m.matrix[2][2] * a);
}

std::ostream &operator<<(std::ostream &os, const Matrix3D &m) {
    os << "\n(" << m.matrix[0][0] << " " << m.matrix[0][1] << " " << m.matrix[0][2] << ")\n" <<
       "(" << m.matrix[1][0] << " " << m.matrix[1][1] << " " << m.matrix[1][2] << ")\n" <<
       "(" << m.matrix[2][0] << " " << m.matrix[2][1] << " " << m.matrix[2][2] << ")\n";
    return os;
}

std::istream &operator>>(std::istream &is, Matrix3D &m) {
    double a, b, c, d, e, f, g, h, i;
    is >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    m.matrix[0][0] = a;
    m.matrix[0][1] = b;
    m.matrix[0][2] = c;
    m.matrix[1][0] = d;
    m.matrix[1][1] = e;
    m.matrix[1][2] = f;
    m.matrix[2][0] = g;
    m.matrix[2][1] = h;
    m.matrix[2][2] = i;
    return is;
}

