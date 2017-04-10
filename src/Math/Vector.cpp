#include "Math/Vector.h"

Vector Vector::operator+(const Vector &vec) {
  return Vector(m_x + vec.m_x, m_y + vec.m_y);
}

Vector Vector::operator+=(const Vector &vec) {
  return Vector(m_x + vec.m_x, m_y + vec.m_y);
}

Vector Vector::operator-(const Vector &vec) {
  return Vector(m_x - vec.m_x, m_y - vec.m_y);
}

Vector Vector::operator-=(const Vector &vec) {
  return Vector(m_x - vec.m_x, m_y - vec.m_y);
}

Vector Vector::operator*(float scalar) {
  return Vector(m_x * scalar, m_y * scalar);
}

Vector Vector::operator/(float scalar) {
  return Vector(m_x / scalar, m_y / scalar);
}

float Vector::GetLength() { return sqrt(m_x * m_x + m_y * m_y); }

Vector Vector::GetNormalized() {
  float l = GetLength();
  if (l > 0) {
    Vector normalized = (*this) * (1 / l);
    return normalized;
  }
  return Vector(0, 0);
}
