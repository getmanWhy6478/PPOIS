#include "Vector.h"
#include <UnitTest++/UnitTest++.h>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

TEST(Vector_default_constructor) {
    Vector vector;
    double x, y, z;

    vector.get_start_point(x, y, z);
    CHECK_EQUAL(0.0, x);
    CHECK_EQUAL(0.0, y);
    CHECK_EQUAL(0.0, z);

    vector.get_end_point(x, y, z);
    CHECK_EQUAL(0.0, x);
    CHECK_EQUAL(0.0, y);
    CHECK_EQUAL(0.0, z);
}

TEST(Vector_parameterized_constructor) {
    Vector vector(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    double x, y, z;

    vector.get_start_point(x, y, z);
    CHECK_EQUAL(1.0, x);
    CHECK_EQUAL(2.0, y);
    CHECK_EQUAL(3.0, z);

    vector.get_end_point(x, y, z);
    CHECK_EQUAL(4.0, x);
    CHECK_EQUAL(5.0, y);
    CHECK_EQUAL(6.0, z);
}

TEST(Vector_copy_constructor) {
    Vector original(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    Vector copy(original);

    double x1, y1, z1, x2, y2, z2;

    original.get_start_point(x1, y1, z1);
    copy.get_start_point(x2, y2, z2);
    CHECK_EQUAL(x1, x2);
    CHECK_EQUAL(y1, y2);
    CHECK_EQUAL(z1, z2);

    original.get_end_point(x1, y1, z1);
    copy.get_end_point(x2, y2, z2);
    CHECK_EQUAL(x1, x2);
    CHECK_EQUAL(y1, y2);
    CHECK_EQUAL(z1, z2);
}

TEST(Vector_length_calculation) {
    Vector vector1(0.0, 0.0, 0.0, 3.0, 4.0, 0.0);
    CHECK_EQUAL(5.0, vector1.length());

    Vector vector2(0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
    CHECK_CLOSE(sqrt(3.0), vector2.length(), 1e-10);

    Vector vector3(1.0, 2.0, 3.0, 4.0, 6.0, 9.0);
    double dx = 3.0, dy = 4.0, dz = 6.0;
    double expected = sqrt(dx * dx + dy * dy + dz * dz);
    CHECK_EQUAL(expected, vector3.length());
}

TEST(Vector_addition) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
    Vector vector2(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);

    Vector result = vector1 + vector2;

    double x, y, z;
    result.get_end_point(x, y, z);
    CHECK_EQUAL(5.0, x);
    CHECK_EQUAL(7.0, y);
    CHECK_EQUAL(9.0, z);
}

TEST(Vector_addition_assignment) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
    Vector vector2(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);

    vector1 += vector2;

    double x, y, z;
    vector1.get_end_point(x, y, z);
    CHECK_EQUAL(5.0, x);
    CHECK_EQUAL(7.0, y);
    CHECK_EQUAL(9.0, z);
}

TEST(Vector_subtraction) {
    Vector vector1(0.0, 0.0, 0.0, 5.0, 7.0, 9.0);
    Vector vector2(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);

    Vector result = vector1 - vector2;

    double x, y, z;
    result.get_end_point(x, y, z);
    CHECK_EQUAL(1.0, x);
    CHECK_EQUAL(2.0, y);
    CHECK_EQUAL(3.0, z);
}

TEST(Vector_subtraction_assignment) {
    Vector vector1(0.0, 0.0, 0.0, 5.0, 7.0, 9.0);
    Vector vector2(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);

    vector1 -= vector2;

    double x, y, z;
    vector1.get_end_point(x, y, z);
    CHECK_EQUAL(1.0, x);
    CHECK_EQUAL(2.0, y);
    CHECK_EQUAL(3.0, z);
}

TEST(Vector_scalar) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
    Vector vector2(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);

    double result = vector1 * vector2;
    CHECK_EQUAL(32.0, result);
}

TEST(Vector_cross) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    Vector vector2(0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    Vector result = vector1 % vector2;

    double x, y, z;
    result.get_end_point(x, y, z);
    CHECK_EQUAL(0.0, x);
    CHECK_EQUAL(0.0, y);
    CHECK_EQUAL(1.0, z);
}

TEST(Vector_miltiplication_num) {
    Vector vector(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);

    Vector result = vector * 2.5;

    double x, y, z;
    result.get_end_point(x, y, z);
    CHECK_CLOSE(2.5, x, 1e-10);
    CHECK_CLOSE(5.0, y, 1e-10);
    CHECK_CLOSE(7.5, z, 1e-10);
}

TEST(Vector_miltiplication_num_assignment) {
    Vector vector(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);

    vector *= 2.0;

    double x, y, z;
    vector.get_end_point(x, y, z);
    CHECK_EQUAL(2.0, x);
    CHECK_EQUAL(4.0, y);
    CHECK_EQUAL(6.0, z);
}

TEST(Vector_division) {
    Vector vector(0.0, 0.0, 0.0, 4.0, 6.0, 8.0);

    Vector result = vector / 2.0;

    double x, y, z;
    result.get_end_point(x, y, z);
    CHECK_EQUAL(2.0, x);
    CHECK_EQUAL(3.0, y);
    CHECK_EQUAL(4.0, z);
}

TEST(Vector_division_assignment) {
    Vector vector(0.0, 0.0, 0.0, 4.0, 6.0, 8.0);

    vector /= 2.0;

    double x, y, z;
    vector.get_end_point(x, y, z);
    CHECK_EQUAL(2.0, x);
    CHECK_EQUAL(3.0, y);
    CHECK_EQUAL(4.0, z);
}

TEST(Vector_division_by_zero) {
    Vector vector(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);

    CHECK_THROW(vector / 0.0, runtime_error);
    CHECK_THROW(vector /= 0.0, runtime_error);
}

TEST(Vector_cosine) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    Vector vector2(0.0, 0.0, 0.0, 1.0, 1.0, 0.0);

    double cos = vector1 ^ vector2;
    double expected = 1.0 / sqrt(2.0);

    CHECK_CLOSE(expected, cos, 1e-10);
}

TEST(Vector_comparison) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
    Vector vector2(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
    Vector vector3(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);
    Vector vector4(1.0, 1.0, 1.0, 2.0, 3.0, 4.0);

    CHECK(vector1 == vector2);
    CHECK(!(vector1 == vector3));

    CHECK(vector1 != vector3);
    CHECK(!(vector1 != vector2));

    CHECK(vector3 > vector1);
    CHECK(!(vector1 > vector3));

    CHECK(vector3 >= vector1);
    CHECK(vector1 >= vector2);
    CHECK(!(vector1 >= vector3));

    CHECK(vector1 < vector3);
    CHECK(!(vector3 < vector1));

    CHECK(vector1 <= vector3);
    CHECK(vector1 <= vector2);
    CHECK(!(vector3 <= vector1));

    CHECK(vector1 <= vector4);
    CHECK(vector1 >= vector4);
    CHECK(!(vector1 < vector4));
    CHECK(!(vector1 > vector4));
}

TEST(Vector_assignment) {
    Vector original(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    Vector copy;

    copy = original;

    double x1, y1, z1, x2, y2, z2;

    original.get_start_point(x1, y1, z1);
    copy.get_start_point(x2, y2, z2);
    CHECK_EQUAL(x1, x2);
    CHECK_EQUAL(y1, y2);
    CHECK_EQUAL(z1, z2);

    original.get_end_point(x1, y1, z1);
    copy.get_end_point(x2, y2, z2);
    CHECK_EQUAL(x1, x2);
    CHECK_EQUAL(y1, y2);
    CHECK_EQUAL(z1, z2);
}

TEST(Vector_output) {
    Vector vector(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);

    stringstream ss;
    ss << vector;

    string expected = "Start: (1, 2, 3), End: (4, 5, 6)";
    CHECK_EQUAL(expected, ss.str());
}

TEST(Vector_input) {
    Vector vector;

    stringstream ss("1.0 2.0 3.0 4.0 5.0 6.0");
    ss >> vector;

    double x, y, z;
    vector.get_start_point(x, y, z);
    CHECK_EQUAL(1.0, x);
    CHECK_EQUAL(2.0, y);
    CHECK_EQUAL(3.0, z);

    vector.get_end_point(x, y, z);
    CHECK_EQUAL(4.0, x);
    CHECK_EQUAL(5.0, y);
    CHECK_EQUAL(6.0, z);
}

TEST(Vector_float) {
    Vector vector1(0.0, 0.0, 0.0, 1.0000001, 2.0000001, 3.0000001);
    Vector vector2(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);

    CHECK(vector1 != vector2);
}

TEST(VectorFloatingPointInequality) {
    Vector vector1(0.0, 0.0, 0.0, 1.1, 2.0, 3.0);
    Vector vector2(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);

    CHECK(vector1 != vector2);
}

TEST(Vector_zero_length) {
    Vector vector;
    CHECK_EQUAL(0.0, vector.length());
}

TEST(Vector_perp) {
    Vector vector1(0.0, 0.0, 0.0, 3.0, 0.0, 0.0);
    Vector vector2(0.0, 0.0, 0.0, 0.0, 4.0, 0.0);

    Vector result = vector1 % vector2;

    double x, y, z;
    result.get_end_point(x, y, z);
    CHECK_EQUAL(0.0, x);
    CHECK_EQUAL(0.0, y);
    CHECK_EQUAL(12.0, z);
}

TEST(Vector_parallel) {
    Vector vector1(0.0, 0.0, 0.0, 2.0, 0.0, 0.0);
    Vector vector2(0.0, 0.0, 0.0, 5.0, 0.0, 0.0);

    double cos = vector1 ^ vector2;
    CHECK_EQUAL(1.0, cos);
}
TEST(Vector_opposite) {
    Vector vector1(0.0, 0.0, 0.0, 2.0, 0.0, 0.0);
    Vector vector2(0.0, 0.0, 0.0, -3.0, 0.0, 0.0);

    double cos = vector1 ^ vector2;
    CHECK_EQUAL(-1.0, cos);
}

TEST(Vector_perp_cosine) {
    Vector vector1(0.0, 0.0, 0.0, 3.0, 0.0, 0.0);
    Vector vector2(0.0, 0.0, 0.0, 0.0, 4.0, 0.0);

    double cos = vector1 ^ vector2;
    CHECK_EQUAL(0.0, cos);
}

TEST(Vector_negative_coordinates) {
    Vector vector1(1.0, 2.0, 3.0, -1.0, -2.0, -3.0);
    Vector vector2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);

    Vector result = vector1 + vector2;

    double x, y, z;
    result.get_end_point(x, y, z);
    CHECK_EQUAL(2.0, x);
    CHECK_EQUAL(1.0, y);
    CHECK_EQUAL(0.0, z);
}
TEST(Vector_negative_multiplication) {
    Vector vector(0.0, 0.0, 0.0, 2.0, -3.0, 4.0);

    Vector result = vector * -2.0;

    double x, y, z;
    result.get_end_point(x, y, z);
    CHECK_EQUAL(-4.0, x);
    CHECK_EQUAL(6.0, y);
    CHECK_EQUAL(-8.0, z);
}

TEST(Vector_negative_assighnment) {
    Vector vector(0.0, 0.0, 0.0, 2.0, -3.0, 4.0);
    double x, y, z;
    vector *= -1.0;
    vector.get_end_point(x, y, z);
    CHECK_EQUAL(-2.0, x);
    CHECK_EQUAL(3.0, y);
    CHECK_EQUAL(-4.0, z);
}

