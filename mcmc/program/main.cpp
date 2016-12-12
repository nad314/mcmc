#include <main>

float hi(const std::vector<vec2>& v1, const std::vector<vec2>& v2, mat2 mat) {
	float x = 0.0f;
	for(int i=0;i<v1.size();++i) {
		vec2 point = v1.at(i);
		float dist = (mat*v2.at(0)-point).magnitude();
		for (int j=1;j<v2.size();++j)
			dist = std::min(dist, (mat*v2.at(j)-point).magnitude());
		x += dist;
	}
	return x;
}

inline float sqr(const float& f) {return f*f;}
inline float normalDistribution(const float &x, const float &u, const float &o) {
	return (float)(exp(-sqr(x - u)/(2.0f*sqr(o)))/(o*sqrt(2.0f*M_PI)));
}

float mcmc(const std::vector<vec2>& original, const std::vector<vec2>& offset, const int& iterations, vector<float>& out) {
	mat2 m1, m2; //matrices
	float a1, a2; //angles for the corresponding rotation matrices
	float d1, d2; //distances
	a1 = a2 = 0.0f;
	d1 = hi(original, offset, m1);

	const float o = 1.0f;
	const float mi = 0.0f;


	for (int i=0;i<iterations;++i) {
		a2 = a1 + (float)(rand()%100-50)/10000.0f;
		m2.init();
		m2.rotate(a2);
		d2 = hi(original, offset, m2);
		float p = std::min(1.0f, normalDistribution(sqrt(d2-d1), mi, o));
		if (p > 0.5f) {
			d1 = d2;
			a1 = a2;
			m1 = m2;
		}
		printf("Step %d: %f (%f, %f)\n", i, a1, a2, p);
		out.push_back(a1);
	}
	return d1;
}


int main(void) {

	const int n = 50;
	std::vector<float> x(n);
	std::vector<float> y(n);
	std::vector<vec2> original(n);
	std::vector<vec2> rotated(n);

	mat2 m;
	m.rotate(-0.2f);
	for(int i=0; i<n; ++i) {
		const float fi = (float)i/n;
    x.at(i) = fi-0.5;
		y.at(i) = (fi-0.5)*(fi-0.5)*4.0f;
		original.at(i) = vec2(x.at(i), y.at(i));
		rotated.at(i) = m*original.at(i);
  }

	x.clear();
	y.clear();
	x.reserve(50);
	y.reserve(50);
	for (float i = -1.0f; i<=1.0f; i+=0.05f) {
		mat2 m;
		m.init();
		m.rotate(i);
		x.push_back(i);
		y.push_back(hi(original, rotated, m));
		//printf("%.2f: %.2f\n", *x.end(), *y.end());
	}

	vector<float> out;
	float rot = mcmc(original, rotated, 200, out);

	Plot::plot(out, "b-");
	Plot::save("./p1.png");
	//Plot::plot(x, y, "g-");
	//Plot::save("p2.png");
	//Plot::show();
	return 0;
}
