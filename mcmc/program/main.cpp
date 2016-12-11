#include <main>

int main(void) {
	const int n = 5000;
	std::vector<float> x(n);
	std::vector<float> y(n);
	for(int i=0; i<n; ++i) {
    x.at(i) = i;
		y.at(i) = i*i;
  }
	Plot::plot(x, y, "r-");
	Plot::plot(x, "b-");
	Plot::show();
	return 0;
}
