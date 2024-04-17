#include <iostream>
#include <vector>

bool check(int64_t i, int64_t j, int n, const std::vector<std::vector<std::pair<char, int>>>& forest) {
  return (0 <= j && j < 3 && i >= 0 && i < n && forest[i][j].first != 'W');
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<std::pair<char, int>>> forest(n, std::vector<std::pair<char, int>>(3));
  for (size_t i = 0; i < n; ++i) {
    for (auto j = 0; j < 3; ++j) {
      std::cin >> forest[i][j].first;
      forest[i][j].second = 0;
    }
  }
  for (int64_t i = n - 1; i >= 0; --i) {
    for (int64_t j = 0; j < 3; ++j) {
      if (forest[i][j].first == 'W') {
        forest[i][j].second = 0;
      } else {
        if (check(i + 1, j - 1, n, forest)) {
          forest[i][j].second = std::max(forest[i][j].second, forest[i + 1][j - 1].second);
        }
        if (check(i + 1, j, n, forest)) {
          forest[i][j].second = std::max(forest[i][j].second, forest[i + 1][j].second);
        }
        if (check(i + 1, j + 1, n, forest)) {
          forest[i][j].second = std::max(forest[i][j].second, forest[i + 1][j + 1].second);
        }
        if (forest[i][j].first == 'C') {
          ++forest[i][j].second;
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < 3; ++i) {
    res = std::max(res, forest[0][i].second);
  }
  std::cout << res;
  return 0;
}