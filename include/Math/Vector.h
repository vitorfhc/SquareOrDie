#ifndef __VECTOR__
#define __VECTOR__

#include <math.h>

class Vector
{
  public:
    // x and y position
    float m_x, m_y;
    // constructor
    Vector(float x, float y) : m_x(x), m_y(y){};
    // operator overloads
    Vector operator+(const Vector &vec);
    Vector operator+=(const Vector &vec);
    Vector operator-(const Vector &vec);
    Vector operator-=(const Vector &vec);
    Vector operator*(float scalar);
    Vector operator/(float scalar);
    // vector maths
    float GetLength();
    Vector GetNormalized();
};

#endif // __VECTOR__