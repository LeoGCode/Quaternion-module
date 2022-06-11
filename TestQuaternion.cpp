#include "Quaternion.hpp"
#include <vector>
#include <gtest/gtest.h>

// Struct tu test the constructor of the Quaternion class
struct QuaternionTest : testing::Test {
    Quaternion* emptyQuaternion;
    Quaternion* emptyQuaternion2;
    Quaternion* positeQuaternion;
    Quaternion* negativeQuaternion;
    QuaternionTest() {
        emptyQuaternion = new Quaternion();
        emptyQuaternion2 = new Quaternion();
        positeQuaternion = new Quaternion(1,2,3,4);
        negativeQuaternion = new Quaternion(-1,-2,-3,-4);
    }
    ~QuaternionTest() {
        delete emptyQuaternion;
        delete emptyQuaternion2;
        delete positeQuaternion;
        delete negativeQuaternion;
    }
};

// Test of empty constructor
TEST_F(QuaternionTest, EmptyConstructor) {
    EXPECT_EQ(emptyQuaternion->a, 0);
    EXPECT_EQ(emptyQuaternion->b, 0);
    EXPECT_EQ(emptyQuaternion->c, 0);
    EXPECT_EQ(emptyQuaternion->d, 0);
};

// Test of the constructor with positive parameters
TEST_F(QuaternionTest, ConstructorWithParametersPositive) {
    EXPECT_EQ(positeQuaternion->a, 1);
    EXPECT_EQ(positeQuaternion->b, 2);
    EXPECT_EQ(positeQuaternion->c, 3);
    EXPECT_EQ(positeQuaternion->d, 4);
};

// Test of the constructor with negative parameters
TEST_F(QuaternionTest, ConstructorWithParametersNegative) {
    EXPECT_EQ(negativeQuaternion->a, -1);
    EXPECT_EQ(negativeQuaternion->b, -2);
    EXPECT_EQ(negativeQuaternion->c, -3);
    EXPECT_EQ(negativeQuaternion->d, -4);
};

// Struct to do several tests of the Quaternion class
// inicial is the first Quaternion, inicial2 is the second Quaternion
// and final is the expected result of the operation
struct quaternion_state {
    float inicial[4];
    float inicial2[4];
    float final[4];
};

struct QuaternionSumTest : QuaternionTest, 
    testing::WithParamInterface<quaternion_state> 
{
    QuaternionSumTest() {
        emptyQuaternion->a = GetParam().inicial[0];
        emptyQuaternion->b = GetParam().inicial[1];
        emptyQuaternion->c = GetParam().inicial[2];
        emptyQuaternion->d = GetParam().inicial[3];

        emptyQuaternion2->a = GetParam().inicial2[0];
        emptyQuaternion2->b = GetParam().inicial2[1];
        emptyQuaternion2->c = GetParam().inicial2[2];
        emptyQuaternion2->d = GetParam().inicial2[3];
    };
};

TEST_P(QuaternionSumTest, Sum) {
    auto ast = GetParam();
    auto quaternionSum = (*emptyQuaternion) + (*emptyQuaternion2);
    EXPECT_EQ(quaternionSum.a, ast.final[0]);
    EXPECT_EQ(quaternionSum.b, ast.final[1]);
    EXPECT_EQ(quaternionSum.c, ast.final[2]);
    EXPECT_EQ(quaternionSum.d, ast.final[3]);
}

INSTANTIATE_TEST_CASE_P(QuaternionTestSuit, QuaternionSumTest, testing::Values(
    quaternion_state{{0,0,0,0},{0,0,0,0},{0,0,0,0}},
    quaternion_state{{1,2,3,4},{0,0,0,0},{1,2,3,4}},
    quaternion_state{{0,0,0,0},{1,2,3,4},{1,2,3,4}},
    quaternion_state{{1,2,3,4},{1,2,3,4},{2,4,6,8}},
    quaternion_state{{-1,-2,-3,-4},{1,2,3,4},{0,0,0,0}},
    quaternion_state{{1,2,3,4},{-1,-2,-3,-4},{0,0,0,0}},
    quaternion_state{{-1,-2,-3,-4},{-1,-2,-3,-4},{-2,-4,-6,-8}}
));

struct QuaternionMultTest : QuaternionTest, testing::WithParamInterface<quaternion_state> {
    QuaternionMultTest() {
        emptyQuaternion->a = GetParam().inicial[0];
        emptyQuaternion->b = GetParam().inicial[1];
        emptyQuaternion->c = GetParam().inicial[2];
        emptyQuaternion->d = GetParam().inicial[3];

        emptyQuaternion2->a = GetParam().inicial2[0];
        emptyQuaternion2->b = GetParam().inicial2[1];
        emptyQuaternion2->c = GetParam().inicial2[2];
        emptyQuaternion2->d = GetParam().inicial2[3];
    };
};

TEST_P(QuaternionMultTest, Mult) {
    auto ast = GetParam();
    auto quaternionMult = (*emptyQuaternion) * (*emptyQuaternion2);
    EXPECT_EQ(quaternionMult.a, ast.final[0]);
    EXPECT_EQ(quaternionMult.b, ast.final[1]);
    EXPECT_EQ(quaternionMult.c, ast.final[2]);
    EXPECT_EQ(quaternionMult.d, ast.final[3]);
}

INSTANTIATE_TEST_CASE_P(QuaternionTestSuit, QuaternionMultTest, testing::Values(
    quaternion_state{{0,0,0,0},{0,0,0,0},{0,0,0,0}},
    quaternion_state{{1,2,3,4},{0,0,0,0},{0,0,0,0}},
    quaternion_state{{0,0,0,0},{1,2,3,4},{0,0,0,0}},
    quaternion_state{{1,2,3,4},{1,2,3,4},{-28,4,6,8}},
    quaternion_state{{-1,-2,-3,-4},{1,2,3,4},{28,-4,-6,-8}},
    quaternion_state{{1,2,3,4},{-1,-2,-3,-4},{28,-4,-6,-8}},
    quaternion_state{{-1,-2,-3,-4},{-1,-2,-3,-4},{-28,4,6,8}}
));

struct quaternion_state_unary_operator {
    float inicial[4];
    float final[4];
};

struct QuaternionConjugateTest : QuaternionTest, 
    testing::WithParamInterface<quaternion_state_unary_operator> 
{
    QuaternionConjugateTest() {
        emptyQuaternion->a = GetParam().inicial[0];
        emptyQuaternion->b = GetParam().inicial[1];
        emptyQuaternion->c = GetParam().inicial[2];
        emptyQuaternion->d = GetParam().inicial[3];
    };
};

TEST_P(QuaternionConjugateTest, Conjugate) {
    auto ast = GetParam();
    auto quaternionConjugate = ~(*emptyQuaternion);
    EXPECT_EQ(quaternionConjugate.a, ast.final[0]);
    EXPECT_EQ(quaternionConjugate.b, ast.final[1]);
    EXPECT_EQ(quaternionConjugate.c, ast.final[2]);
    EXPECT_EQ(quaternionConjugate.d, ast.final[3]);
}


INSTANTIATE_TEST_CASE_P(QuaternionTestSuit, QuaternionConjugateTest, 
    testing::Values(
    quaternion_state_unary_operator{{0,0,0,0},{0,0,0,0}},
    quaternion_state_unary_operator{{1,2,3,4},{1,-2,-3,-4}},
    quaternion_state_unary_operator{{-1,-2,-3,-4},{-1,2,3,4}},
    quaternion_state_unary_operator{{-1,-2,3,4},{-1,2,-3,-4}},
    quaternion_state_unary_operator{{-1,2,-3,-4},{-1,-2,3,4}},
    quaternion_state_unary_operator{{1,2,-3,-4},{1,-2,3,4}},
    quaternion_state_unary_operator{{1,-2,3,4},{1,2,-3,-4}}
));

struct quaternion_state_real_return {
    float inicial[4];
    float final;
};

struct QuaternionNormTest : QuaternionTest, 
testing::WithParamInterface<quaternion_state_real_return> 
{
    QuaternionNormTest() {
        emptyQuaternion->a = GetParam().inicial[0];
        emptyQuaternion->b = GetParam().inicial[1];
        emptyQuaternion->c = GetParam().inicial[2];
        emptyQuaternion->d = GetParam().inicial[3];
    };
};

TEST_P(QuaternionNormTest, Norm) {
    auto ast = GetParam();
    auto quaternionNorm = &(*emptyQuaternion);
    EXPECT_NEAR(quaternionNorm, ast.final, 0.001);
}

INSTANTIATE_TEST_CASE_P(QuaternionTestSuit, QuaternionNormTest, 
testing::Values(
    quaternion_state_real_return{{0,0,0,0},0},
    quaternion_state_real_return{{1,0,0,0},1},
    quaternion_state_real_return{{0,1,0,0},1},
    quaternion_state_real_return{{0,0,1,0},1},
    quaternion_state_real_return{{0,0,0,1},1},
    quaternion_state_real_return{{1,2,3,4},5.477},
    quaternion_state_real_return{{-1,-2,-3,-4},5.477},
    quaternion_state_real_return{{-1,-2,3,4},5.477},
    quaternion_state_real_return{{6,7,8,9},15.166},
    quaternion_state_real_return{{9,8,7,6},15.166}
));

// Main function to run all the tests
int main(int argc, char** argv) {
    
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}