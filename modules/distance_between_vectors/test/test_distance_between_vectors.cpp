// Copyright 2017 Gorozhanin Mihail

#include <gtest/gtest.h>
#include "include/distance_between_vectors.h"

using namespace Distance;

TEST(DistanceBetweenVectors, Different_Size_Vectors) {
	vector<float> V1(4);
	for (int i = 0; i < 4; i++)
	{
		V1[i] = static_cast<float>(i*(0.3+0.01*i));
	}
	vector<float> V2(5);
	for (int i = 0; i < 5; i++)
	{
		V2[i] = static_cast<float>(i+2);
	}
	TypeMetric Type = L2;
	float result = DistanceBetweenVectors::CalculateDistance(V1, V2, Type);
	EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(DistanceBetweenVectors, Different_Size_Vectors_With_Different_Metric) {
	vector<float> V1(4);
	for (int i = 0; i < 4; i++)
	{
		V1[i] = static_cast<float>(i*(0.3+0.01*i));
	}
	vector<float> V2(5);
	for (int i = 0; i < 5; i++)
	{
		V2[i] = static_cast<float>(i+2);
	};
	TypeMetric Type = L2;
	float result1 = DistanceBetweenVectors::CalculateDistance(V1, V2, Type);
	TypeMetric Type = LInf;
	float result2 = DistanceBetweenVectors::CalculateDistance(V1, V2, Type);
	EXPECT_FLOAT_EQ(result1, result2);
}

TEST(DistanceBetweenVectors, Equal_Size_Vectors_Final) {
	vector<float> V1(4);
	for (int i = 0; i < 4; i++)
	{
		V1[i] = static_cast<float>(i+2);
	}
	vector<float> V2(4);
	for (int i = 0; i < 4; i++)
	{
		V2[i] = static_cast<float>(i);
	};
	TypeMetric Type = L1;
	float result2 = DistanceBetweenVectors::CalculateDistance(V1, V2, Type);
	EXPECT_FLOAT_EQ(result, 8.0f);
}
