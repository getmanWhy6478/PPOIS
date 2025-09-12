#include "Vector.h"
#include <gtest/gtest.h>
#include <sstream>
using namespace std;
TEST(VectorTest, null_constructor) {
    Vector vector;
    double x, y, z;

    vector.get_start_point(x, y, z);
    EXPECT_DOUBLE_EQ(0.0, x);
    EXPECT_DOUBLE_EQ(0.0, y);
    EXPECT_DOUBLE_EQ(0.0, z);

    vector.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(0.0, x);
    EXPECT_DOUBLE_EQ(0.0, y);
    EXPECT_DOUBLE_EQ(0.0, z);

    EXPECT_DOUBLE_EQ(0.0, vector.length());
}

TEST(VectorTest, constructor) {
    Vector vector(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    double x, y, z;

    vector.get_start_point(x, y, z);
    EXPECT_DOUBLE_EQ(1.0, x);
    EXPECT_DOUBLE_EQ(2.0, y);
    EXPECT_DOUBLE_EQ(3.0, z);

    vector.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(4.0, x);
    EXPECT_DOUBLE_EQ(5.0, y);
    EXPECT_DOUBLE_EQ(6.0, z);
}

TEST(VectorTest, copy_constructor) {
    Vector original(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    Vector copy(original);

    double x1, y1, z1, x2, y2, z2;

    original.get_start_point(x1, y1, z1);
    copy.get_start_point(x2, y2, z2);
    EXPECT_DOUBLE_EQ(x1, x2);
    EXPECT_DOUBLE_EQ(y1, y2);
    EXPECT_DOUBLE_EQ(z1, z2);

    original.get_end_point(x1, y1, z1);
    copy.get_end_point(x2, y2, z2);
    EXPECT_DOUBLE_EQ(x1, x2);
    EXPECT_DOUBLE_EQ(y1, y2);
    EXPECT_DOUBLE_EQ(z1, z2);
}

TEST(VectorTest, length) {
    Vector vector(0.0, 0.0, 0.0, 3.0, 4.0, 0.0);
    EXPECT_DOUBLE_EQ(5.0, vector.length());

    Vector vector2(1.0, 2.0, 3.0, 4.0, 6.0, 9.0);
    double len_x = 3.0, len_y = 4.0, len_z = 6.0;
    double expected = sqrt(len_x * len_x + len_y * len_y + len_z * len_z);
    EXPECT_DOUBLE_EQ(expected, vector2.length());
}

TEST(VectorTest, addition_operator) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
    Vector vector2(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);

    Vector result = vector1 + vector2;

    double x, y, z;
    result.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(5.0, x);
    EXPECT_DOUBLE_EQ(7.0, y);
    EXPECT_DOUBLE_EQ(9.0, z);
}

TEST(VectorTest, addition) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
    Vector vector2(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);

    vector1 += vector2;

    double x, y, z;
    vector1.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(5.0, x);
    EXPECT_DOUBLE_EQ(7.0, y);
    EXPECT_DOUBLE_EQ(9.0, z);
}

TEST(VectorTest, subtraction_operator) {
    Vector vector1(0.0, 0.0, 0.0, 5.0, 7.0, 9.0);
    Vector vector2(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);

    Vector result = vector1 - vector2;

    double x, y, z;
    result.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(1.0, x);
    EXPECT_DOUBLE_EQ(2.0, y);
    EXPECT_DOUBLE_EQ(3.0, z);
}

TEST(VectorTest, subtraction) {
    Vector vector1(0.0, 0.0, 0.0, 5.0, 7.0, 9.0);
    Vector vector2(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);

    vector1 -= vector2;

    double x, y, z;
    vector1.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(1.0, x);
    EXPECT_DOUBLE_EQ(2.0, y);
    EXPECT_DOUBLE_EQ(3.0, z);
}

TEST(VectorTest, scolar_multiple) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
    Vector vector2(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);

    double result = vector1 * vector2;
    EXPECT_DOUBLE_EQ(32.0, result); // 1*4 + 2*5 + 3*6 = 4 + 10 + 18 = 32
}

TEST(VectorTest, vector_multiple) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    Vector vector2(0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    Vector result = vector1 % vector2;

    double x, y, z;
    result.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(0.0, x);
    EXPECT_DOUBLE_EQ(0.0, y);
    EXPECT_DOUBLE_EQ(1.0, z);
}

TEST(VectorTest, num_multiple_operator) {
    Vector vector(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);

    Vector result = vector * 2.5;

    double x, y, z;
    result.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(2.5, x);
    EXPECT_DOUBLE_EQ(5.0, y);
    EXPECT_DOUBLE_EQ(7.5, z);
}

TEST(VectorTest, num_multiple) {
    Vector vector(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);

    vector *= 2.0;

    double x, y, z;
    vector.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(2.0, x);
    EXPECT_DOUBLE_EQ(4.0, y);
    EXPECT_DOUBLE_EQ(6.0, z);
}

TEST(VectorTest, num_division_operator) {
    Vector vector(0.0, 0.0, 0.0, 4.0, 6.0, 8.0);

    Vector result = vector / 2.0;

    double x, y, z;
    result.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(2.0, x);
    EXPECT_DOUBLE_EQ(3.0, y);
    EXPECT_DOUBLE_EQ(4.0, z);
}

TEST(VectorTest, num_division) {
    Vector vector(0.0, 0.0, 0.0, 4.0, 6.0, 8.0);

    vector /= 2.0;

    double x, y, z;
    vector.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(2.0, x);
    EXPECT_DOUBLE_EQ(3.0, y);
    EXPECT_DOUBLE_EQ(4.0, z);
}

TEST(VectorTest, division_by_zero) {
    Vector vector(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);

    EXPECT_THROW(vector / 0.0, runtime_error);
    EXPECT_THROW(vector /= 0.0, runtime_error);
}

TEST(VectorTest, cos) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    Vector vector2(0.0, 0.0, 0.0, 1.0, 1.0, 0.0);

    double cos = vector1 ^ vector2;
    double expected = 1.0 / sqrt(2.0);

    EXPECT_NEAR(expected, cos, 1e-10);
}

TEST(VectorTest, comparison) {
    Vector vector1(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
    Vector vector2(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
    Vector vector3(0.0, 0.0, 0.0, 4.0, 5.0, 6.0);
    Vector vector4(1.0, 1.0, 1.0, 2.0, 3.0, 4.0);

    EXPECT_TRUE(vector1 == vector2);
    EXPECT_FALSE(vector1 == vector3);

    EXPECT_TRUE(vector1 != vector3);
    EXPECT_FALSE(vector1 != vector2);

    EXPECT_TRUE(vector3 > vector1);
    EXPECT_FALSE(vector1 > vector3);

    EXPECT_TRUE(vector3 >= vector1);
    EXPECT_TRUE(vector1 >= vector2);
    EXPECT_FALSE(vector1 >= vector3);

    EXPECT_TRUE(vector1 < vector3);
    EXPECT_FALSE(vector3 < vector1);

    EXPECT_TRUE(vector1 <= vector3);
    EXPECT_TRUE(vector1 <= vector2);
    EXPECT_FALSE(vector3 <= vector1);

    EXPECT_TRUE(vector1 <= vector4);
    EXPECT_TRUE(vector1 >= vector4);
    EXPECT_FALSE(vector1 < vector4);
    EXPECT_FALSE(vector1 > vector4);
}

TEST(VectorTest, assignment_operator) {
    Vector original(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    Vector copy;

    copy = original;

    double x1, y1, z1, x2, y2, z2;

    original.get_start_point(x1, y1, z1);
    copy.get_start_point(x2, y2, z2);
    EXPECT_DOUBLE_EQ(x1, x2);
    EXPECT_DOUBLE_EQ(y1, y2);
    EXPECT_DOUBLE_EQ(z1, z2);

    original.get_end_point(x1, y1, z1);
    copy.get_end_point(x2, y2, z2);
    EXPECT_DOUBLE_EQ(x1, x2);
    EXPECT_DOUBLE_EQ(y1, y2);
    EXPECT_DOUBLE_EQ(z1, z2);
}

TEST(VectorTest, output_operator) {
    Vector vector(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);

    stringstream ss;
    ss << vector;

    string expected = "Start: (1, 2, 3), End: (4, 5, 6)";
    EXPECT_EQ(expected, ss.str());
}

TEST(VectorTest, input_operator) {
    Vector vector;

    stringstream ss("1.0 2.0 3.0 4.0 5.0 6.0");
    ss >> vector;

    double x, y, z;
    vector.get_start_point(x, y, z);
    EXPECT_DOUBLE_EQ(1.0, x);
    EXPECT_DOUBLE_EQ(2.0, y);
    EXPECT_DOUBLE_EQ(3.0, z);

    vector.get_end_point(x, y, z);
    EXPECT_DOUBLE_EQ(4.0, x);
    EXPECT_DOUBLE_EQ(5.0, y);
    EXPECT_DOUBLE_EQ(6.0, z);
}

//int main(int argc, char** argv) {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}