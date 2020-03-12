#include <iostream>

using namespace std;

class Vector3D {
private:
    double x, y, z;
public:
    Vector3D() : Vector3D(0, 0, 0) {
    }

    Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {

    }

    ~Vector3D() {
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    void setZ(double z) {
        this->z = z;
    }

    bool operator==(const Vector3D &v) const {
        return v.x == x && v.y == y && v.z == z;
    }

    bool operator!=(const Vector3D &v) const {
        return v.x != x || v.y != y || v.z != z;
    }

    Vector3D operator+(const Vector3D &v) const {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    Vector3D operator-(const Vector3D &v) const {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }

    Vector3D operator*(const int a) const {
        return Vector3D(x * a, y * a, z * a);
    }

    double operator*(const Vector3D &v) const {
        return x * v.x + y * v.y + z * v.z;
    }
};

Vector3D operator*(int a, const Vector3D &v) {
    return Vector3D(v.getX() * a, v.getY() * a, v.getZ() * a);
}

std::ostream &operator<<(std::ostream &os, const Vector3D &v) {
    os << "(" << v.getX() << "; " << v.getY() << "; " << v.getZ() << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Vector3D &v) {
    double x, y, z;
    is >> x >> y >> z;
    v.setX(x);
    v.setY(y);
    v.setZ(z);
    return is;
}

class Matrix3D {
private:
    double matrix[3][3];
public:
    Matrix3D() : Matrix3D (0,0,0,0,0,0,0,0,0) {}

    Matrix3D (double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    matrix[0][0] = a, matrix[0][1] = b, matrix[0][2] = c,
    matrix[1][0] = d, matrix[1][1] = e, matrix[1][2] = f,
    matrix[2][0] = g, matrix[2][1] = h, matrix[2][2] = i;
    }

    Matrix3D operator*(const double a){
        return Matrix3D(matrix[0][0] * a, matrix[0][1] * a, matrix[0][2] * a,
                        matrix[1][0] * a, matrix[1][1] * a, matrix[1][2] * a,
                        matrix[2][0] * a, matrix[2][1] * a, matrix[2][2] * a);
    }

    Matrix3D operator+(const Matrix3D &m) {
        return Matrix3D(matrix[0][0] + m.matrix[0][0], matrix[0][1] + m.matrix[0][1], matrix[0][2] + m.matrix[0][2],
                        matrix[1][0] + m.matrix[1][0], matrix[1][1] + m.matrix[1][1], matrix[1][2] + m.matrix[1][2],
                        matrix[2][0] + m.matrix[2][0], matrix[2][1] + m.matrix[2][1], matrix[2][2] + m.matrix[2][2]);
    }

    Matrix3D operator-(const Matrix3D &m) {
        return Matrix3D(matrix[0][0] - m.matrix[0][0], matrix[0][1] - m.matrix[0][1], matrix[0][2] - m.matrix[0][2],
                        matrix[1][0] - m.matrix[1][0], matrix[1][1] - m.matrix[1][1], matrix[1][2] - m.matrix[1][2],
                        matrix[2][0] - m.matrix[2][0], matrix[2][1] - m.matrix[2][1], matrix[2][2] - m.matrix[2][2]);
    }

    Matrix3D operator*(const Matrix3D &m) {
        return Matrix3D(matrix[0][0] * m.matrix[0][0] + matrix[0][1] * m.matrix[1][0] + matrix[0][2] * m.matrix[2][0], matrix[0][0] * m.matrix[0][1] + matrix[0][1] * m.matrix[1][1] + matrix[0][2] * m.matrix[2][1], matrix[0][0] * m.matrix[0][2] + matrix[0][1] * m.matrix[1][2] + matrix[0][2] * m.matrix[2][2],
                        matrix[1][0] * m.matrix[0][0] + matrix[1][1] * m.matrix[1][0] + matrix[1][2] * m.matrix[2][0], matrix[1][0] * m.matrix[0][1] + matrix[1][1] * m.matrix[1][1] + matrix[1][2] * m.matrix[2][1], matrix[1][0] * m.matrix[0][2] + matrix[1][1] * m.matrix[1][2] + matrix[1][2] * m.matrix[2][2],
                        matrix[2][0] * m.matrix[0][0] + matrix[2][1] * m.matrix[1][0] + matrix[2][2] * m.matrix[2][0], matrix[2][0] * m.matrix[0][1] + matrix[2][1] * m.matrix[1][1] + matrix[2][2] * m.matrix[2][1], matrix[2][0] * m.matrix[0][2] + matrix[2][1] * m.matrix[1][2] + matrix[2][2] * m.matrix[2][2]);
    }

    Vector3D operator*(const Vector3D &v) {
        return Vector3D(matrix[0][0] * v.getX() + matrix[0][1] * v.getY() + matrix[0][2] * v.getZ(),
                        matrix[1][0] * v.getX() + matrix[1][1] * v.getY() + matrix[1][2] * v.getZ(),
                        matrix[2][0] * v.getX() + matrix[2][1] * v.getY() + matrix[2][2] * v.getZ());
    }

    double det(){
        return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
    }

    friend Matrix3D operator*(const double a, const Matrix3D &m);
    friend std::ostream &operator<<(std::ostream &os, const Matrix3D &m);
    friend std::istream &operator>>(std::istream &is, Matrix3D &m);

};

Matrix3D operator*(const double a, const Matrix3D &m){
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
    m.matrix[0][0] = a; m.matrix[0][1] = b; m.matrix[0][2] = c;
    m.matrix[1][0] = d; m.matrix[1][1] = e; m.matrix[1][2] = f;
    m.matrix[2][0] = g; m.matrix[2][1] = h; m.matrix[2][2] = i;
    return is;
}

int main() {
    // Вектор задан в коде
    Vector3D A(1, 2, 3);
    // Вектор читается из cin
    Vector3D B;
    cin >> B;

    // Базовые операции с векторами
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A * 3 = " << A * 3 << endl;
    cout << "2 * B = " << 2 * B << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;


    // Матрица задана в коде
    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    // Матрица читается из cin
    Matrix3D D;
    cin >> D;

    // Базовые операции с матрицами
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "C * 3 = " << C * 3 << endl;
    cout << "2 * D = " << 2 * D << endl;
    cout << "C + D = " << C + D << endl;
    cout << "C - D = " << C - D << endl;
    cout << "C * D = " << C * D << endl;

    // Детерминант матрицы
    cout << "det(D) = " << D.det() << endl;

    // Умножение матрицы на вектор
    cout << "D * B = " << D * B << endl;

    return 0;
};