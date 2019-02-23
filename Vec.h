template <class T>
class vec2 {
  public:
  T x;
  T y;

  vec2()
      : x(0)
      , y(0)
  {
  }
  vec2(T _x, T _y)
      : x(_x)
      , y(_y)
  {
  }

  vec2 operator+(const vec2<T>& other)
  {
    return vec2<T>(this->x + other.x, this->y + other.y);
  }

  vec2 operator-(const vec2& other)
  {
    return vec2<T>(this->x - other.x, this->y - other.y);
  }

  vec2 operator*(const T& factor)
  {
    return vec2<T>(this->x * factor, this->y * factor);
  }

  vec2 operator/(const T& factor)
  {
    return vec2<T>(this->x / factor, this->y / factor);
  }

  vec2 operator+=(const vec2<T>& other)
  {
    this->x += other.x;
    this->y += other.y;
  }

  vec2 operator-=(const vec2<T>& other)
  {
    this->x -= other.x;
    this->y -= other.y;
  }

  vec2 operator*=(const T& factor)
  {
    this->x *= factor;
    this->y *= factor;
  }

  vec2 operator/=(const T& factor)
  {
    this->x /= factor;
    this->y /= factor;
  }

  vec2<T> invert() {
    return vec2<T>(-x, -y);
  }

  float magnitude()
  {
    return sqrt(x * x + y * y);
  }

  void limit(float length)
  {
    float mag = magnitude();

    if (mag > length || abs(mag) > length) {
      x /= mag;
      y /= mag;
      x *= length;
      y *= length;
    }
  }
};

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;