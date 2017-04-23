// Copyright 2017 Grechukhin Nikita

#include <gtest/gtest.h>

#include "include/integration_methods.h"

TEST(INTEGRATION, canCreateIntegrationMethod) {
    // Act
    IntegrationMethod im(3.0, 1.5);

    // Assert
    EXPECT_EQ(3.0, im.getUpperLimit());
    EXPECT_EQ(1.5, im.getLowerLimit());
}

TEST(INTEGRATION, canSetLimits) {
    // Act
    IntegrationMethod im;

    im.setUpperLimit(2.5);
    im.setLowerLimit(0.5);

    // Assert
    EXPECT_EQ(2.5, im.getUpperLimit());
    EXPECT_EQ(0.5, im.getLowerLimit());
}
