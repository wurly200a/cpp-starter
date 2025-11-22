#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <filesystem>

using namespace std;

long long sum(vector<int> xs){
  long long sum = 0;

  for (int v : xs){
    sum += v;
  }

  return sum;
}

int main(int argc, char* argv[]) {

    cout << "cpp-starter running.\n";
    cout << "Args (" << argc << "):";
    for (int i = 0; i < argc; ++i) cout << ' ' << argv[i];
    cout << "\n";
    
    cout << "Current path: " << std::filesystem::current_path() << "\n";

    auto now = chrono::system_clock::now();
    auto secs = chrono::time_point_cast<chrono::seconds>(now).time_since_epoch().count();
    cout << "Epoch seconds: " << secs << "\n";

    vector<int> xs = {1, 2, 3, 4, 5};
    auto value = sum(xs);
    cout << "Sum = " << value << "\n";
    cout << "OK.\n";
    
    return 0;
}
