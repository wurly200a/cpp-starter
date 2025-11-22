#include <chrono>
#include <filesystem>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

long long sum(const std::vector<int> &xs) {
  long long total = 0;

  for (int v : xs) {
    total += v;
  }

  return total;
}

int main(int argc, char *argv[]) {
  std::cout << "cpp-starter running.\n";

  std::cout << "Args (" << argc << "):";
  for (int i = 0; i < argc; ++i) {
    std::cout << ' ' << argv[i];
  }
  std::cout << "\n";

  try {
    const auto cwd = std::filesystem::current_path();
    std::cout << "Current path: " << cwd << "\n";
  } catch (const std::filesystem::filesystem_error &e) {
    std::cerr << "Failed to get current path: " << e.what() << "\n";
  }

  const auto now = std::chrono::system_clock::now();
  const auto secs =
      std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch())
          .count();
  std::cout << "Epoch seconds: " << secs << "\n";

  const std::vector<int> xs{1, 2, 3, 4, 5};
  const auto value = sum(xs);
  std::cout << "Sum = " << value << "\n";

  std::cout << "OK.\n";

  return 0;
}
