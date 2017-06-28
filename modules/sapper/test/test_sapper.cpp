// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>

#include<vector>
#include <string>

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


TEST(Saper, Can_help) {
    std::string output_;
    Saper app_;
    std::vector<const char*> args = {"appname", "0", "0", "0", "0" };
    const char** argv = &args.front();
    int argc = static_cast<int>(args.size());

    output_ = app_(argc, argv);
    EXPECT_EQ(output_, "error");
}

TEST(Saper, Can_touch_and_lose) {
    std::string output_;
    Saper app_(3, 3, 9);
    std::vector<const char*> args = {"appname", "1", "1", "1" };

    const char** argv = &args.front();
    int argc = static_cast<int>(args.size());
    output_ = app_(argc, argv);
    app_.Print();

    ASSERT_EQ(output_, "You lose");
}


TEST(Saper, Can_touch_and_win) {
    std::string output_;
    Saper app_(3, 3, 0);
    std::vector<const char*> args = { "appname", "1", "1", "1" };

    const char** argv = &args.front();
    int argc = static_cast<int>(args.size());
    output_ = app_(argc, argv);
    app_.Print();

    ASSERT_EQ(output_, "You win!");
}

TEST(Saper, Can_touch_and_not_lose) {
    std::string output_;
    Saper app_(10, 10, 6);
    std::vector<const char*> args = { "appname", "5", "4", "1" };

    const char** argv = &args.front();
    int argc = static_cast<int>(args.size());
    output_ = app_(argc, argv);

    ASSERT_EQ(output_, "Good move!");
}

TEST(Saper, Can_make_flag) {
    std::string output_;
    Saper app_;
    std::vector<const char*> args = {"appname", "0", "0", "0" };
    std::vector<const char*> options = { "appname", "0", "0", "0" };

    //  options.push_back();
    //  for (size_t i = 0; i < args.size(); ++i)
    //      options.push_back(args[i].c_str());
    //  const char** argv = &options.front();
    const char** argv = &args.front();

    int argc = static_cast<int>(args.size());

    output_ = app_(argc, argv);

    ASSERT_EQ(output_, "You make a flag");
}

TEST(Saper, Can_throw_parce) {
    std::string output_;
    Saper app_(10, 10, 11);
    std::vector<const char*> args = { "appname", "-19", "-20", "1" };

    const char** argv = &args.front();
    int argc = static_cast<int>(args.size());
    // output_ = app_(argc, argv);

    ASSERT_ANY_THROW(output_ = app_(argc, argv));
    //  ASSERT_EQ(output_,"Wrong number format!");
}


TEST(Saper, Can_exit) {
    std::string output_;
    Saper app_(10, 10, 11);
    std::vector<const char*> args = { "appname", "0", "0", "2" };

    const char** argv = &args.front();
    int argc = static_cast<int>(args.size());
    output_ = app_(argc, argv);

    ASSERT_EQ(output_, "exit");
}


TEST(Saper, Can_exit_by_1_args) {
    std::string output_;
    Saper app_(10, 10, 11);
    std::vector<const char*> args = { "appname"};

    const char** argv = &args.front();
    int argc = static_cast<int>(args.size());
    output_ = app_(argc, argv);

    ASSERT_EQ(output_, "exit");
}
