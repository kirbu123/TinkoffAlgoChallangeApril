#include <vector>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  char id;
  std::cin >> id;
  std::vector<std::vector<int64_t>> matrix(n, std::vector<int64_t>(n));
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      std::cin >> matrix[i][j];
    }
  }
  std::cout << n * n << '\n';
  if (id == 'R') {
    int x = 0;
    int y = 0;
    for (int64_t i = 0; i < n; ++i) {
      for (int64_t j = n - 1; j >= 0; --j) {
        std::cout << x << ' ' << y << ' ' << j << ' ' << i << '\n';
        ++y;
      }
      y = 0;
      ++x;
    }
  } else if (id == 'L') {
    int x = 0;
    int y = 0;
    for (int64_t i = n - 1; i >= 0; --i) {
      for (int64_t j = 0; j < n; ++j) {
        std::cout << x << ' ' << y << ' ' << j << ' ' << i << '\n';
        ++y;
      }
      y = 0;
      ++x;
    }
  }
}