 // Copyright 2017 Korniakov Kirill

#include <gtest\gtest.h>

#include "include\saper.h"

TEST(Saper, create_obj) {
	ASSERT_NO_THROW(Saper a());
}

TEST(Saper, create_obj1) {
	Saper a(20,20,20);
	
	ASSERT_TRUE(a.TouchResult(0,0));
}

TEST(Saper, create_obj2) {
	ASSERT_NO_THROW(Saper a());
}
