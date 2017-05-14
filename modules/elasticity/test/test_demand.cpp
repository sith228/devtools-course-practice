// Copyright 2017 Zemlyanskiy Nikita

#include <gtest/gtest.h>
#include "include/Demand.h"

TEST(Demand, Can_Return_Value_Of_Check) {
  Demand dem(2.3, 3.2, 4.4, 8.9);

  ASSERT_NO_THROW(dem.checkforelasticity());
}

TEST(Demand, Can_Return_Same_Values_Of_Check) {
  Demand dem1(13.0, 16.4, 6.4, 3.4);
  Demand dem2(13.0, 16.4, 6.4, 3.4);

  EXPECT_EQ(dem1.checkforelasticity(), dem2.checkforelasticity());
}

TEST(Demand, Can_Return_Same_Values_Of_Revenue) {
  Demand dem1(13.0, 16.4, 6.4, 3.4);
  Demand dem2(13.0, 16.4, 6.4, 3.4);

  EXPECT_EQ(dem1.revenuechange(65.0), dem2.revenuechange(65.0));
}

TEST(Demand, Can_Create_Obj_With_Positive_Values) {
  ASSERT_NO_THROW(Demand dem(13.0, 16.4, 6.4, 3.4));
}

TEST(Demand, Can_Not_Create_Obj_With_Negative_Values) {
  ASSERT_ANY_THROW(Demand dem(-1.0, 3.4, 5.6, 9.0));
}

TEST(Demand, Can_Change_Revenue) {
  Demand dem1(13.0, 16.4, 6.4, 3.4);
  Demand dem2(17.3, 6.5, 8.7, 8.4);

  EXPECT_NE(dem1.revenuechange(120.0), dem2.revenuechange(120.0));
}

TEST(Demand, Can_Create_Obj_With_Null_Values) {
  // oldprice != newprice
  ASSERT_NO_THROW(Demand dem(0.0, 3.0, 0.0, 0.0));
}

TEST(Demand, Can_Not_Create_Obj_Oldp_Eq_Newp) {
  ASSERT_ANY_THROW(Demand dem1(13.0, 13.0, 6.4, 3.4));
}

TEST(Demand, Can_Return_Diff_Values_Of_Check) {
  Demand dem1(13.0, 14.0, 6.4, 3.4);
  Demand dem2(10.0, 8.0 , 5.6, 3.2);

  EXPECT_NE(dem1.checkforelasticity(), dem2.checkforelasticity());
}

TEST(Demand, Can_Return_Value_Of_Revenue) {
  Demand dem(12.2, 10.3, 6.7, 2.3);

  ASSERT_NO_THROW(dem.revenuechange(12.2));
}
