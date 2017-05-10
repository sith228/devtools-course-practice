// Copyright 2017 Kiparenko Ilya

#include <string>
#include "gtest/gtest.h"
#include "include/symbolic_function.h"

TEST(SymbolicDerivativeTest, Can_Parse_Simple_Expression) {
  EXPECT_NO_THROW(SymbolicFunction sym("a + b"));
}

TEST(SymbolicDerivativeTest, Can_Parse_Simple_Expression_With_Function) {
  EXPECT_NO_THROW(SymbolicFunction sym("a + b*c/sin(d)"));
}

TEST(SymbolicDerivativeTest, Cant_Parse_Expression_With_Unknown_Token) {
  EXPECT_ANY_THROW(SymbolicFunction sym("a $ b"));
}

TEST(SymbolicDerivativeTest, Can_Parse_Expression_With_Right_Braces) {
  EXPECT_NO_THROW(SymbolicFunction sym("(a + b)"));
}

TEST(SymbolicDerivativeTest, Cant_Parse_Expression_With_Wrong_Braces) {
  EXPECT_ANY_THROW(SymbolicFunction sym("a + b)"));
}

TEST(SymbolicDerivativeTest,
     Cant_Parse_Expression_With_Wrong_Number_Of_Arguments) {
  EXPECT_ANY_THROW(SymbolicFunction sym("a + "));
}

TEST(SymbolicDerivativeTest,
     Cant_Parse_Expression_With_Wrong_Number_Of_Arguments_More) {
  EXPECT_ANY_THROW(SymbolicFunction sym("(a + b) c"));
}

TEST(SymbolicDerivativeTest, Can_Parse_Its_Own_Representation) {
  SymbolicFunction sym("a/e + b*c^d");
  SymbolicFunction sym_2(sym.ToString());

  EXPECT_EQ(sym_2.ToString(), sym.ToString());
}

TEST(SymbolicDerivativeTest, Can_Parse_Really_Complex_Expression) {
  std::string s = "1 + 3/4/sin(x+log(x)/2.0)*cos(4.0)^(5.0-x)";
  s +=            "-(1-x)^(x) + sin(2*x*3*cos(2*x))";
  SymbolicFunction sym(s);
  SymbolicFunction sym_2(sym.ToString());

  EXPECT_EQ(sym_2.ToString(), sym.ToString());
}

TEST(SymbolicDerivativeTest, Derivative_Of_X_Is_One) {
  SymbolicFunction sym("x");
  SymbolicFunction sym_dx;

  EXPECT_NO_THROW(sym_dx = sym.Derivative("x"));
  EXPECT_EQ(stod(sym_dx.ToString()), 1.0);
}

TEST(SymbolicDerivativeTest, Derivative_Of_Not_X_Is_Zero) {
  SymbolicFunction sym("a+b/c");
  SymbolicFunction sym_dx;

  EXPECT_NO_THROW(sym_dx = sym.Derivative("x"));

  EXPECT_EQ(std::stod(sym_dx.ToString()), 0.0);
}

TEST(SymbolicDerivativeTest, Can_Differentiate_Really_Complex_Expression) {
  std::string s = "2^x*x + 3/4/sin(x+log(x)/2.0)*cos(4.0)^(5.0-x)";
  s +=            "-(1-x)^(x) + sin(2*x*3*cos(2*x))-3+2*x-4+(1+x)";
  s +=            "-x/(2-x^4)";
  SymbolicFunction sym(s);
  SymbolicFunction sym_dx;

  EXPECT_NO_THROW(sym_dx = sym.Derivative("x"));
}
