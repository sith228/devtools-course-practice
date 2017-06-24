// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>

#include"include/saper.h"

TEST(Saper, Can_creat_obj_by_defult) {
    ASSERT_NO_THROW(Saper app);
}

TEST(Saper, Can_creat_obj_width_less_height) {
    ASSERT_NO_THROW(Saper app(10, 20, 10));
}

TEST(Saper, Can_creat_obj_height_less_width) {
    ASSERT_NO_THROW(Saper app(20, 10, 10));
}

TEST(Saper, Can_creat_obj_with_equal_size) {
    ASSERT_NO_THROW(Saper app(20, 20, 10));
}

TEST(Saper, throw_when_negative_width) {
    ASSERT_ANY_THROW(Saper app(-10, 20, 10));
}

TEST(Saper, throw_when_negative_hight) {
    ASSERT_ANY_THROW(Saper app(20, -20, 10));
}

TEST(Saper, throw_when_negative_size) {
    ASSERT_ANY_THROW(Saper app(-10, -20, 10));
}

TEST(Saper, throw_when_a_lot_bomb) {
    ASSERT_ANY_THROW(Saper app(20, 20, 1000));
}

TEST(Saper, Can_print_in_console) {
    Saper app;

    ASSERT_NO_THROW(app.Print());
}

TEST(Saper, Can_recognize_all_bomb) {
    Saper app;
    int count = 0;

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            if (!app.TouchResult(i, k))
                count++;

    ASSERT_EQ(count, 10);
}

TEST(Saper, Can_win) {
    Saper app;

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            if (!app.TouchResult(i, k))
                app.MarkCell(i, k);

    ASSERT_TRUE(app.IsWin());
}

TEST(Saper, Can_create_new_level) {
    Saper app;

    ASSERT_NO_THROW(app.NewLVL());
}
TEST(Saper, Can_create_new_level) {
    Saper app;

    app.Gaming();

    ASSERT_NO_THROW(app.NewLVL());
}
