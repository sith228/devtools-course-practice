
#include <gtest/gtest.h>
#include "include/area_converter.h"

static const double Neighbourhood = 0.0000001;

TEST(AreaConverterTest, check_create_converter_unit)
{
    AreaConverter c = AreaConverter(AreaConverter::centimeter, AreaConverter::meter);

    double r1 = c(123);
    double r2 = 0.0123;

    ASSERT_NEAR(r1, r2, Neighbourhood);
}

TEST(AreaConverterTest, check_acr_to_yard_convertion)
{
   
    double r1 = AreaConverter(AreaConverter::acr, AreaConverter::yard)(3.1415);
    double r2 = 15204.86;

    ASSERT_NEAR(r1, r2, Neighbourhood);
}

TEST(AreaConverterTest, can_operate_with_zero_size_areas)
{

    double r1 = AreaConverter(AreaConverter::meter, AreaConverter::inch)(0.);
    double r2 = 0.;

    EXPECT_DOUBLE_EQ(r1, r2);
}

TEST(AreaConverterTest, is_negative_size_area_works_correct)
{
    AreaConverter c = AreaConverter(AreaConverter::meter, AreaConverter::inch);
    
    EXPECT_ANY_THROW(c(-2.1718));
}