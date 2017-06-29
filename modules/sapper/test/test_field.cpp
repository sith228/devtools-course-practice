// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>
#include"include/field.h"

TEST(Field, Can_creat_obj_by_defult) {
    ASSERT_NO_THROW(Field app);
}

TEST(Field, Can_creat_obj_width_less_height) {
    ASSERT_NO_THROW(Field app(10, 10, 30));
}

TEST(Field, Can_creat_obj_with_equal_size) {
    ASSERT_ANY_THROW(Field app(-20, -20, 10));
}

TEST(Field, throw_when_negative_hight) {
    ASSERT_ANY_THROW(Field app(-20, -20, -10));
}
