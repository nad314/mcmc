template <class _t> class vector2 {
public:
	_t x, y;
	vector2() :x(), y() {}
	vector2(_t _x, _t _y) :x(_x), y(_y) {}
	vector2(_t *a) :x(a[0]), y(a[1]) {}
	vector2(_t a) :x(a), y(a) {}
	inline operator _t*() { return &x; }
	inline operator const _t*() const { return &x; }

	inline vector2 &operator = (const vector2 &a) { x = a.x; y = a.y; return *this; }

	inline vector2 operator + (const vector2 &a) const { return vector2(x + a.x, y + a.y); }
	inline vector2 operator - (const vector2 &a) const { return vector2(x - a.x, y - a.y); }
	inline vector2 operator * (const vector2 &a) const { return vector2(x*a.x, y*a.y); }
	inline vector2 operator / (const vector2 &a) const { return vector2(x / a.x, y / a.y); }

	inline vector2 &operator + (const _t &a) const { return vector2(x + a, y + a); }
	inline vector2 &operator - (const _t &a) const { return vector2(x - a, y - a); }
	inline vector2 &operator * (const _t &a) const { return vector2(x*a, y*a); }
	inline vector2 &operator / (const _t &a) const { return vector2(x / a, y / a); }

	inline vector2 &operator += (const vector2 &a) { return *this = vector2(x + a.x, y + a.y); }
	inline vector2 &operator -= (const vector2 &a) { return *this = vector2(x - a.x, y - a.y); }
	inline vector2 &operator *= (const vector2 &a) { return *this = vector2(x*a.x, y*a.y); }
	inline vector2 &operator /= (const vector2 &a) { return *this = vector2(x / a.x, y / a.y); }

	inline vector2 &operator += (const _t &a) { return *this = vector2(x + a, y + a); }
	inline vector2 &operator -= (const _t &a) { return *this = vector2(x - a, y - a); }
	inline vector2 &operator *= (const _t &a) { return *this = vector2(x*a, y*a); }
	inline vector2 &operator /= (const _t &a) { return *this = vector2(x / a, y / a); }

	inline bool operator == (const vector2 &a) const { return (x == a.x) && (y == a.y); }

	inline vector2 &operator = (const _t a) { return *this = vector(a, a); }
	inline vector2 &operator = (const _t *a) { return *this = vector2(a[0], a[1]); }

	inline bool isNull() const { return (x == 0) && (y == 0); }
	inline _t magnitude() const { return (x*x + y*y); }
	inline _t length() const { return sqrt(magnitude()); }
	inline vector2 normalize() { return *this /= length(); }

	inline vector2 min(const vector2 &a) const { return vector2(x < a.x ? x : a.x, y < a.y ? y : a.y); }
	inline vector2 max(const vector2 &a) const { return vector2(x > a.x ? x : a.x, y > a.y ? y : a.y); }
};

typedef vector2<float>	vec2;
typedef vector2<double>	vec2d;
typedef vector2<int>	vec2i;
