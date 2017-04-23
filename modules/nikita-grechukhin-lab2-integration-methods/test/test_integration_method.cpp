// Copyright 2016 Nikita Grechukhin

#include <gtest/gtest.h>

#include <string>
#include <stdexcept>

#include "include/integration_methods.h"

TEST(INTEGRATION, can_create_integration_method)
{
	IntegrationMethod im(2.1, 1.4);

	EXPECT_EQ(2.1, im.upper_limit());
	EXPECT_EQ(1.4, im.lower_limit());
}