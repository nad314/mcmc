struct Plot {
  static int plot(std::vector<float>& x);
  static int plot(std::vector<float>& x, const char* style);
  static int plot(std::vector<float>& x, std::vector<float>&y, const char* style);
  static void show();
  static void save(const char* path);
  static void legend();
};
