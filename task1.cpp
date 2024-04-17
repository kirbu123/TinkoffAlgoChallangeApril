#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
  std::unordered_map<int64_t, int64_t> map;
  int64_t n;
  std::cin >> n;
  std::vector<int64_t> data(n);
  int64_t count = -1;
  for (auto i = 0; i < n; ++i) {
    std::cin >> data[i];
  }
  if (n >= 7) {
    for (auto i = 0; i < 7; ++i) {
      ++map[data[i]];
    }
    if (map[1] == 0 && map[2] == 0 && map[3] == 0) {
      count = std::max(count, map[5]);
    }
    int64_t r = 6;
    int64_t l = 0;
    while (r < n) {
      ++map[data[r]];
      --map[data[l]];
      if (map[1] == 0 && map[2] == 0 && map[3] == 0) {
        count = std::max(count, map[5]);
      }
      ++r;
      ++l;
    }
  }
  std::cout << count;
  return 0;
}