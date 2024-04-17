#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> FK = {0, 1, 1, 1, -1, -1, -1, 0};
std::vector<int> SK = {1, 0, 1, -1, 1, -1, 0, -1};

std::vector<int> FKK = {1, 2, -1, -2, 1, 2, -1, -2};
std::vector<int> SKK = {2, 1, 2, 1, -2, -1, -2, -1};

int main() {
  size_t n = 0;
  std::cin >> n;
  std::vector<std::vector<char>> input(n, std::vector<char>(n));
  for (auto& num : input) {
    for (auto& el : num) {
      std::cin >> el;
    }
  }
  std::queue<std::vector<int>> queue;

  if (input.size() > 2) {
    queue.push({2, 1, 1, 1});
    queue.push({1, 2, 1, 1});
  }

  while (!queue.empty()) {
    auto element = queue.front();
    int state = element[2];
    queue.pop();
    if (input[element[0]][element[1]] == 'F') {
      std::cout << element[3];
      return 0;
    }
    if (input[element[0]][element[1]] == 'G') {
      state = 0;
    }
    if (input[element[0]][element[1]] == 'K') {
      state = 1;
    }

    if (state != 0) {
      for (int i = 0; i < 8; ++i) {
        if (element[0] + FKK[i] >= 0 && element[0] + FKK[i] < input.size()) {
          if (element[1] + SKK[i] >= 0 && element[1] + SKK[i] < input.size())
            queue.push({element[0] + FKK[i], element[1] + SKK[i], state,
                        element[3] + 1});
        }
      }
    } else {
      for (int i = 0; i < 8; ++i) {
        if (element[0] + FK[i] >= 0 && element[0] + FK[i] < input.size()) {
          if (element[1] + SK[i] >= 0 && element[1] + SK[i] < input.size())
            queue.push({element[0] + FK[i], element[1] + SK[i], state,
                        element[3] + 1});
        }
      }
    }
  }
  std::cout << -1;
}
