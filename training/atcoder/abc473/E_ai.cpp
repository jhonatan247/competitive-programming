#include <iostream>
#include <map>
#include <ranges>

using namespace std;
int main() {
    unsigned N, K;
    cin >> N >> K;
    
    unsigned ans{};
    // Associate array from the value of S to its position
    map<unsigned, unsigned> prev;
    prev[0] = 0;
    for (unsigned S{}, last{}; const auto &[i, A] : views::istream<unsigned>(cin) | views::enumerate) {
        (S += A) %= K; // Find the prefix sum
        // If the prefix sum has already appeared in the past, and does not overlap with any chosen interval
        if (prev.contains(S) && last <= prev[S]) {
            ++ans;
            last = i + 1; // Choose that interval
        }
        prev[S] = i + 1; // Update the position
    }
    
    cout << ans << endl;
    return 0;
}

