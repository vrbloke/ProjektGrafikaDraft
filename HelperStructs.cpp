#include "HelperStructs.h"

Matrix4 Matrix4::operator* (const Matrix4& rhs)
{
  int i, j, k;
  Matrix4 tmp;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
    {
      tmp.d[i][j] = 0.0;
      for (k = 0; k < 4; k++)
        tmp.d[i][j] = tmp.d[i][j] + (d[i][k] * rhs.d[k][j]);
    }
  return tmp;
}

Vector4 operator* (const Vector4& gVector, const Matrix4& gMatrix)
{
  unsigned int i, j;
  Vector4 tmp;

  for (i = 0; i < 4; i++)
  {
    tmp.d[i] = 0.0;
    for (j = 0; j < 4; j++) tmp.d[i] = tmp.d[i] + (gMatrix.d[i][j] * gVector.d[j]);
  }
  return tmp;
}

Vector4 Matrix4::operator* (const Vector4& gVector)
{
  unsigned int i, j;
  Vector4 tmp;

  for (i = 0; i < 4; i++)
  {
    tmp.d[i] = 0.0;
    for (j = 0; j < 4; j++) tmp.d[i] = tmp.d[i] + (d[i][j] * gVector.d[j]);
  }
  return tmp;
}