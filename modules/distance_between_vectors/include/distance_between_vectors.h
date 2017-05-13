// Copyright 2017 Gorozhanin Mihail
#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_

#include <math.h>
#include <vector.h>

enum TypeMetric { L1 = 1, L2, L3, L4, LInf };

// Metric or the distance measure is non-negative, symmetric.
// The Minkowski metric (L3, L4).
// The Euclidean metric (L2).
// Manhattan distance (L1).
// The metric Chebyshev (LInf).

enum TypeMetric { L1 = 1, L2, L3, L4, LInf };
TypeMetric Type_Metric;
int Size_Vector;

class DistanceBetweenVectors {
 public:
   static float CalculateDistance(float *vector1,
   float *vector2, TypeMetric TypeM, int SizeV);
};

// #endif MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
