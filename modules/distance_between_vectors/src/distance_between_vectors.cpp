// Copyright 2017 Gorozhanin Mihail
#include <include/distance_between_vectors.h>

float DistanceBetweenVectors::CalculateDistance(float *vector1,
float *vector2, int TypeM, int SizeV) {
  float distance;
  Size_Vector = SizeV;
  if (sizeof vector1 == sizeof vector2) {
      vector<float>vect1(Size_Vector);
      vector<float>vect2(Size_Vector);
      if (sizeof vector1 == Size_Vector)
            vector<float>vect1(Size_Vector, *vector1);
      if (sizeof vector2 == Size_Vector)
            vector<float>vect2(Size_Vector, *vector2);

      if (TypeM == LInf) {
          float max = 0;
          for (int i = 0; i < Size_Vector; i++)
              if (max < fabs(vect1[i] - vect2[i]))
                  max = (float)(fabs(vect1[i] - vect2[i]));
          distance = max;
      }
      else {
          float Sum_Of_Components = 0;
          for (int i = 0; i < Size_Vector; i++)
              Sum_Of_Components += powf(
                  (float)(fabs(vect1[i] - vect2[i])),
                  1.0f * (float)(TypeM));
          distance = powf(Sum_Of_Components,
              1.0f / (float)(TypeM));
      }
      return distance;
  }
  else {
      return 0;
  }
}

