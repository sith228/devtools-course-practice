
#include <gtest/gtest.h>
#include "include/area_converter.h"

TEST(AreaConverterTest, check_create_converter_unit)
{
    AreaConverter c = AreaConverter(AreaConverter::centimeter, AreaConverter::meter);

    double r1 = c(123);
    double r2 = 0.0123;

    EXPECT_DOUBLE_EQ(r1, r2);
}
