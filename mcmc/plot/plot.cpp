#include <main>
#include <plot/matplotlib.h>
namespace plt = matplotlibcpp;

int Plot::plot(std::vector<float>& x, std::vector<float>& y, const char* style) {
  try {
    plt::plot(x, y, style);
    return 0;
  } catch (std::exception e) {
    printf("%s\n", e.what());
    return 1;
  }
}

int Plot::plot(std::vector<float>& x, const char* style) {
  try {
    plt::plot(x, style);
    return 0;
  } catch (std::exception e) {
    printf("%s\n", e.what());
    return 1;
  }
}

int Plot::plot(std::vector<float>& x) {
  try {
    plt::plot(x);
    return 0;
  } catch (std::exception e) {
    printf("%s\n", e.what());
    return 1;
  }
}

void Plot::show() {
  plt::show();
}

void Plot::save(const char* path) {
  plt::save(path);
}

void Plot::legend() {
   plt::legend();
}
