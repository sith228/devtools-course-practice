#include <gtest/gtest.h>

#include "include/statistical_moments.h"

using std::string;

class StatisticalMomentsTest : public ::testing::Test {
protected:
    statisticalMoments moments;
};

TEST(Kiseleva_Olga_StatisticalMomentsTest,
    Do_Throw_When_Two_Vectors_Are_Empty) {
    // Arrange
    std::vector<double> values;
    std::vector<double> changes;
    // Act+Assert
    EXPECT_ANY_THROW(statisticalMoments(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest, Do_Throw_When_Values_Is_Empty) {
    // Arrange
    std::vector<double> values;
    std::vector<double> changes = { 0.25,0.3 };
    // Act+Assert
    EXPECT_ANY_THROW(statisticalMoments(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest, Do_Throw_When_Changes_Is_Empty) {
    // Arrange
    std::vector<double> values = { 0,1,2 };
    std::vector<double> changes;
    // Act+Assert
    EXPECT_ANY_THROW(statisticalMoments(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest, Do_Throw_When_One_Change_Not_Valid) {
    // Arrange
    std::vector<double> values = { 0,1,2 };
    std::vector<double> changes = { 0.25,5,0.35 };
    // Act+Assert
    EXPECT_ANY_THROW(statisticalMoments(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest, Do_Throw_When_Sum_Change_Not_Equals_1) {
    // Arrange
    std::vector<double> values = { 0,1,2 };
    std::vector<double> changes = { 0.25,0.1,0.35 };
    // Act+Assert
    EXPECT_ANY_THROW(statisticalMoments(values, changes));
}



