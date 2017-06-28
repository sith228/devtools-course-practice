// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>
#include"include/field.h"

TEST(Field, Can_creat_obj_by_defult) {
    ASSERT_NO_THROW(Field app);
}

TEST(Field, Can_print_in_console) {
    Field app(10, 10, 10);

    app.GenerateField();

    ASSERT_FALSE(app.OpenCurrentCell(1000, 10000));
    ASSERT_TRUE(app.OpenCurrentCell(1, 1));
}

TEST(Field, Can_win_lose) {
    Field app, app1;

    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            if (!app[i][k].isBomb)
                app.OpenCurrentCell(i, k);

    ASSERT_FALSE(app1.IsWin());
    ASSERT_TRUE(app.IsWin());
}

TEST(Field, Can_mark) {
    Field app;

    app.MarkCell(-20, 200);
    app.MarkCell(0, 0);

    ASSERT_EQ(app[0][0].viewCell, '!');
}


