#include <vector>
#include <iostream>

int main() {
  int64_t h, w;
  std::cin >> h >> w;
  std::vector<std::vector<int64_t>> matrix(h, std::vector<int64_t>(w));
  for (size_t i = 0; i < h; ++i) {
    for (size_t j = 0; j < w; ++j) {
      std::cin >> matrix[i][j];
    }
  }
  for (int64_t i = 0; i < w; ++i) {
    for (int64_t j = h - 1; j >= 0; --j) {
      std::cout << matrix[j][i] << ' ';
    }
    std::cout << std::endl;
  }
}
