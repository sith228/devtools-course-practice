// Copyright 2017 Kuchkov Ivan

#include <gtest/gtest.h>
#include <vector>
#include "include/area_converter.h"

static const double Neighbourhood = 0.0000001;

TEST(AreaConverterTest, can_create_converter_unit) {
    EXPECT_NO_THROW(new AreaConverter(AreaConverter::centimeter,
        AreaConverter::meter));
}


TEST(AreaConverterTest, check_create_converter_unit) {
    AreaConverter c = AreaConverter(AreaConverter::centimeter,
                                    AreaConverter::meter);

    double r1 = c(123);
    double r2 = 0.0123;

    ASSERT_NEAR(r1, r2, Neighbourhood);
}

TEST(AreaConverterTest, check_acr_to_yard_convertion) {
    double r1 = AreaConverter(AreaConverter::acr,
                                AreaConverter::yard)(3.1415);
    double r2 = 15204.86;

    ASSERT_NEAR(r1, r2, Neighbourhood);
}

TEST(AreaConverterTest, can_operate_with_zero_size_areas) {
    double r1 = AreaConverter(AreaConverter::meter,
                                AreaConverter::inch)(0.);
    double r2 = 0.;

    EXPECT_DOUBLE_EQ(r1, r2);
}

TEST(AreaConverterTest, is_negative_size_area_works_correct) {
    AreaConverter c = AreaConverter(AreaConverter::meter,
                                    AreaConverter::inch);

    EXPECT_ANY_THROW(c(-2.1718));
}

TEST(AreaConverterTest, check_convert_multiple_times_with_different_arguments) {
    AreaConverter c = AreaConverter(AreaConverter::centimeter,
                                    AreaConverter::acr);
    int size = 10;
    double delta = 0.25;
    std::vector<double> r1(size);
    std::vector<double> r2(size);

    for (int i = 0; i < size; ++i) {
        r1.push_back(c(i * delta));
        r2.push_back(AreaConverter(AreaConverter::centimeter,
                                    AreaConverter::acr)(i * delta));
    }

    ASSERT_TRUE(r1 == r2);
}

TEST(AreaConverterTest, check_meter_to_anything_convertion) {
    std::vector<double> r1;
    std::vector<double> r2;
    double temp = 1;

    r2.push_back(0.0002471054); //acr
    r1.push_back(AreaConverter(AreaConverter::meter,
        AreaConverter::acr)(temp));
    r2.push_back(10000.);//centimeter
    r1.push_back(AreaConverter(AreaConverter::meter,
        AreaConverter::centimeter)(temp));
    r2.push_back(100.);//decimeter
    r1.push_back(AreaConverter(AreaConverter::meter,
        AreaConverter::decimeter)(temp));
    r2.push_back(0.0001);//hectare
    r1.push_back(AreaConverter(AreaConverter::meter,
        AreaConverter::hectare)(temp));
    r2.push_back(1550.0031);//inch
    r1.push_back(AreaConverter(AreaConverter::meter,
        AreaConverter::inch)(temp));
    r2.push_back(1.);//meter
    r1.push_back(AreaConverter(AreaConverter::meter,
        AreaConverter::meter)(temp));
    r2.push_back(1.1959900463);//yard
    r1.push_back(AreaConverter(AreaConverter::meter,
        AreaConverter::yard)(temp));

    for (auto &v : r1) {
        v = (std::trunc(v * Neighbourhood) / Neighbourhood);
    }
    for (auto &v : r2) {
        v = (std::trunc(v * Neighbourhood) / Neighbourhood);
    }

    ASSERT_TRUE(r1 == r2);
}
