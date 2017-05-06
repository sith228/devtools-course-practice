// Copyright Kildishev Maxim 2017
#include <gtest/gtest.h>
#include "include/dichotomy.h"


TEST(Kildishev_Maxim_DichotomyMethod_Tests, First)
{
    Dichotomy obj;
    EXPECT_NO_THROW(obj.findMin(1,0,0,-1,-1,0.01));
}
