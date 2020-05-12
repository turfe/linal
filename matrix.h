//
// Created by admin on 11.04.2020.
//

#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

class Matrix3D {
private:
    double matrix[3][3];
public:
    Matrix3D();

    Matrix3D (double a, double b, double c, double d, double e, double f, double g, double h, double i);

    ~Matrix3D();

    Matrix3D operator*(const double a) const;

    Matrix3D operator+(const Matrix3D &m) const;

    Matrix3D operator-(const Matrix3D &m) const;

    Matrix3D operator*(const Matrix3D &m) const;

    Vector3D operator*(const Vector3D &v) const;

    double det() const ;

    friend Matrix3D operator*(const double a, const Matrix3D &m);
    friend std::ostream &operator<<(std::ostream &os, const Matrix3D &m);
    friend std::istream &operator>>(std::istream &is, Matrix3D &m);

};

Matrix3D operator*(const double a, const Matrix3D &m);

std::ostream &operator<<(std::ostream &os, const Matrix3D &m);

std::istream &operator>>(std::istream &is, Matrix3D &m);

#endif //LINAL_MATRIX_H
