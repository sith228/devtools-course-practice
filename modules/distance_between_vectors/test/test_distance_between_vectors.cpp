// Copyright 2017 Gorozhanin Mihail

#include <gtest/gtest.h>
#include "include/distance_between_vectors.h"

TEST(DistanceBetweenVectors, Different_Size_Vectors) {
	float Vector1[5];
	for (int i = 0; i < 5; i++) {
		Vector1[i] = (float)(i + 1);
	}
	float Vector2[6];
	for (int i = 0; i < 6; i++) {
		Vector1[i] = (float)(i * 2 + 1);
	}
	float result = DistanceBetweenVectors::CalculateDistance(Vector1, Vector2, 2, 5);
	EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(DistanceBetweenVectors, Different_Size_Vectors_With_Size) {
	float Vector1[5];
	for (int i = 0; i < 5; i++) {
		Vector1[i] = (float)(i + 1);
	}
	float Vector2[5];
	for (int i = 0; i < 6; i++) {
		Vector1[i] = (float)(i * 2 + 1);
	}
	float result = DistanceBetweenVectors::CalculateDistance(Vector1, Vector2, 2, 15);
	EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(DistanceBetweenVectors, Equal_Size_Vectors_With_Size) {
	float Vector1[5];
	for (int i = 0; i < 5; i++) {
		Vector1[i] = (float)(i + 1);
	}
	float Vector2[5];
	for (int i = 0; i < 5; i++) {
		Vector1[i] = (float)(i * 2 + 1);
	}
	float result = DistanceBetweenVectors::CalculateDistance(Vector1, Vector2, 5, 5);
	EXPECT_FLOAT_EQ(result, 4.0f);
}
