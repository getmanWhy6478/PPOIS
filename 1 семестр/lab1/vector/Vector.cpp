#include "Vector.h"
#include <UnitTest++/UnitTest++.h>
using namespace std;
Vector::Vector() : x_start(0), y_start(0), z_start(0), x_end(0), y_end(0), z_end(0) {}

Vector::Vector(double start_x, double start_y, double start_z,
    double end_x, double end_y, double end_z)
    : x_start(start_x), y_start(start_y), z_start(start_z), x_end(end_x), y_end(end_y), z_end(end_z) {
};

Vector::Vector(const Vector& second_vector)
    : x_start(second_vector.x_start), y_start(second_vector.y_start), z_start(second_vector.z_start),
    x_end(second_vector.x_end), y_end(second_vector.y_end), z_end(second_vector.z_end) {
};

void Vector::get_start_point(double& x, double& y, double& z) const {
    x = x_start;
    y = y_start;
    z = z_start;
}

void Vector::get_end_point(double& x, double& y, double& z) const {
    x = x_end;
    y = y_end;
    z = z_end;
}

double Vector::length() const {
    double len_x = x_end - x_start;
    double len_y = y_end - y_start;
    double len_z = z_end - z_start;
    return sqrt(len_x * len_x + len_y * len_y + len_z * len_z);
}

Vector Vector::operator+(const Vector& second_vector) const {
    return Vector(x_start, y_start, z_start,
        x_end + second_vector.x_end - second_vector.x_start,
        y_end + second_vector.y_end - second_vector.y_start,
        z_end + second_vector.z_end - second_vector.z_start);
}

Vector& Vector::operator+=(const Vector& second_vector) {
    x_end += second_vector.x_end - second_vector.x_start;
    y_end += second_vector.y_end - second_vector.y_start;
    z_end += second_vector.z_end - second_vector.z_start;
    return *this;
}

Vector Vector::operator-(const Vector& second_vector) const {
    return Vector(x_start, y_start, z_start,
        x_end - (second_vector.x_end - second_vector.x_start),
        y_end - (second_vector.y_end - second_vector.y_start),
        z_end - (second_vector.z_end - second_vector.z_start));
}

Vector& Vector::operator-=(const Vector& second_vector) {
    x_end -= second_vector.x_end - second_vector.x_start;
    y_end -= second_vector.y_end - second_vector.y_start;
    z_end -= second_vector.z_end - second_vector.z_start;
    return *this;
}

double Vector::operator*(const Vector& second_vector) const {
    double len_x = x_end - x_start;
    double len_y = y_end - y_start;
    double len_z = z_end - z_start;

    double len_x_second_vector = second_vector.x_end - second_vector.x_start;
    double len_y_second_vector = second_vector.y_end - second_vector.y_start;
    double len_z_second_vector = second_vector.z_end - second_vector.z_start;

    return len_x * len_x_second_vector + len_y * len_y_second_vector + len_z * len_z_second_vector;
}

Vector Vector::operator%(const Vector& second_vector) const {
    double len_x = x_end - x_start;
    double len_y = y_end - y_start;
    double len_z = z_end - z_start;

    double len_x_second_vector = second_vector.x_end - second_vector.x_start;
    double len_y_second_vector = second_vector.y_end - second_vector.y_start;
    double len_z_second_vector = second_vector.z_end - second_vector.z_start;

    double res_x = len_y * len_z_second_vector - len_z * len_y_second_vector;
    double res_y = len_z * len_x_second_vector - len_x * len_z_second_vector;
    double res_z = len_x * len_y_second_vector - len_y * len_x_second_vector;

    return Vector(0, 0, 0, res_x, res_y, res_z);
}

Vector Vector::operator*(double num) const {
    return Vector(x_start, y_start, z_start,
        x_start + (x_end - x_start) * num,
        y_start + (y_end - y_start) * num,
        z_start + (z_end - z_start) * num);
}

Vector& Vector::operator*=(double num) {
    x_end = x_start + (x_end - x_start) * num;
    y_end = y_start + (y_end - y_start) * num;
    z_end = z_start + (z_end - z_start) * num;
    return *this;
}

Vector Vector::operator/(double num) const {
    if (num == 0) {
        throw runtime_error("Division by zero");
    }
    return *this * (1.0 / num);
}

Vector& Vector::operator/=(double num) {
    if (num == 0) {
        throw runtime_error("Division by zero");
    }
    return *this *= (1.0 / num);
}

double Vector::operator^(const Vector& second_vector) const {
    double dotProduct = *this * second_vector;
    double length1 = this->length();
    double length2 = second_vector.length();

    if (length1 == 0 || length2 == 0) {
        throw runtime_error("Zero vector length");
    }

    return dotProduct / (length1 * length2);
}

bool Vector::operator==(const Vector& second_vector) const {
    return (x_start == second_vector.x_start && y_start == second_vector.y_start && z_start == second_vector.z_start &&
        x_end == second_vector.x_end && y_end == second_vector.y_end && z_end == second_vector.z_end);
}

bool Vector::operator!=(const Vector& second_vector) const {
    return !(*this == second_vector);
}

bool Vector::operator>(const Vector& second_vector) const {
    return this->length() > second_vector.length();
}

bool Vector::operator>=(const Vector& second_vector) const {
    return this->length() >= second_vector.length();
}

bool Vector::operator<(const Vector& second_vector) const {
    return this->length() < second_vector.length();
}

bool Vector::operator<=(const Vector& second_vector) const {
    return this->length() <= second_vector.length();
}

Vector& Vector::operator=(const Vector& second_vector) {
    if (this != &second_vector) {
        x_start = second_vector.x_start;
        y_start = second_vector.y_start;
        z_start = second_vector.z_start;
        x_end = second_vector.x_end;
        y_end = second_vector.y_end;
        z_end = second_vector.z_end;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Vector& vec) {
    os << "Start: (" << vec.x_start << ", " << vec.y_start << ", " << vec.z_start << "), "
        << "End: (" << vec.x_end << ", " << vec.y_end << ", " << vec.z_end << ")";
    return os;
}

istream& operator>>(istream& is, Vector& vec) {
    is >> vec.x_start >> vec.y_start >> vec.z_start >> vec.x_end >> vec.y_end >> vec.z_end;
    return is;
}
int main() {
    return UnitTest::RunAllTests();
}
