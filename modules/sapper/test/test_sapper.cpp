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

	std::vector<std::string> args = { "0", "0", "0" };
	std::vector<const char*> options;

	options.push_back("appname");
	for (size_t i = 0; i < args.size(); ++i)
		options.push_back(args[i].c_str());
	const char** argv = &options.front();
	int argc = static_cast<int>(args.size()) + 1;

	output_ = app_(argc, argv);
	EXPECT_TRUE(output_ == "asd");
}
