// Copyright 2017 Kiparenko Ilya

#include "gtest/gtest.h"
#include "include/symbolic_function.h"

TEST(symbolic_derivativeTest, Can_Parse_Simple_Expression) {
  EXPECT_NO_THROW(symbolic_function sym("a + b"));
}

TEST(symbolic_derivativeTest, Can_Parse_Simple_Expression_With_Function) {
  EXPECT_NO_THROW(symbolic_function sym("a + b*c/sin(d)"));
}

TEST(symbolic_derivativeTest, Cant_Parse_Expression_With_Unknown_Token) {
  EXPECT_ANY_THROW(symbolic_function sym("a $ b"));
}

TEST(symbolic_derivativeTest, Can_Parse_Expression_With_Right_Braces) {
  EXPECT_NO_THROW(symbolic_function sym("(a + b)"));
}

TEST(symbolic_derivativeTest, Cant_Parse_Expression_With_Wrong_Braces) {
  EXPECT_ANY_THROW(symbolic_function sym("(a + b"));
}

TEST(symbolic_derivativeTest,
     Cant_Parse_Expression_With_Wrong_Number_Of_Arguments) {
  EXPECT_ANY_THROW(symbolic_function sym("a + "));
}

TEST(symbolic_derivativeTest,
     Cant_Parse_Expression_With_Wrong_Number_Of_Arguments_More) {
  EXPECT_ANY_THROW(symbolic_function sym("(a + b) c"));
}

TEST(symbolic_derivativeTest, Can_Parse_Its_Own_Representation) {
  symbolic_function sym("a/e + b*c^d");
  symbolic_function sym_2(sym.to_string());

  EXPECT_EQ(sym_2.to_string(), sym.to_string());
}

TEST(symbolic_derivativeTest, Derivative_Of_X_Is_One) {
  symbolic_function sym("x");
  symbolic_function sym_dx;

  EXPECT_NO_THROW(sym_dx = sym.derivative("x"));
  EXPECT_EQ(stod(sym_dx.to_string()), 1.0);
}

TEST(symbolic_derivativeTest, Derivative_Of_Not_X_Is_Zero) {
  symbolic_function sym("a+b/c");
  symbolic_function sym_dx;

  EXPECT_NO_THROW(sym_dx = sym.derivative("x"));
  EXPECT_EQ(stod(sym_dx.to_string()), 0.0);
}
