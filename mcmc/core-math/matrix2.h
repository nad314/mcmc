struct mat2 {
  float m[4];
  inline float& operator[](const int& a) {return m[a];}
  inline const float operator[](const int& a) const {return m[a];}
  inline vec2 operator *(const vec2& a){return vec2(a.x*m[0] + a.y*m[1], a.x*m[2] + a.y*m[3]);}
  inline void init(){m[0] = 1.0f; m[1] = 0.0f; m[2] = 0.0f; m[3] = 1.0f;}
  mat2(){init();}

  inline mat2& operator* (const mat2& a) {
    mat2 t;
    t[0] = m[0]*a[0] + m[1]*a[2];
    t[1] = m[0]*a[1] + m[1]*a[3];
    t[2] = m[2]*a[0] + m[3]*a[2];
    t[3] = m[2]*a[1] + m[3]*a[3];
    return (*this = t);
  }

  inline mat2& rotate(const float& phi) {
    float c = std::cos(phi);
    float s = std::sin(phi);
    mat2 t;
    t[0] = c;
    t[1] = -s;
    t[2] = s;
    t[3] = c;
    return *this = *this*t;
  }
};
