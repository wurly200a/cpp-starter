#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <filesystem>

int main(int argc, char* argv[]) {
    using namespace std;

    cout << "cpp-starter running.\n";
    cout << "Args (" << argc << "):";
    for (int i = 0; i < argc; ++i) cout << ' ' << argv[i];
    cout << "\n";

    cout << "Current path: " << std::filesystem::current_path() << "\n";

    auto now = chrono::system_clock::now();
    auto secs = chrono::time_point_cast<chrono::seconds>(now).time_since_epoch().count();
    cout << "Epoch seconds: " << secs << "\n";

    vector<int> xs = {1,2,3,4,5};
    long long sum = 0;
    for (int v : xs) sum += v;
    cout << "Sum = " << sum << "\n";

    cout << "OK.\n";
    return 0;
}
