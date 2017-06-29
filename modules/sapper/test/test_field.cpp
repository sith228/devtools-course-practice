// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>
#include"include/field.h"
// construct
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
// print
TEST(Field, can_print) {
    Field app(2, 2, 1);
    
    ASSERT_NO_THROW(app.PrintField());
}


TEST(Field, print_predict) {
    Field app(2, 2, 1);
    
    std::cout << app.PrintField() << std::endl;

    ASSERT_EQ(" |0 1 |\n-+----+\n0|* * |\n1|* * |\n-+----+\n", app.PrintField());
}
