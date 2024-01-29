#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    std::vector<int> dp(n);
    for (int &i: v) {
        std::cin >> i;
    }
    std::sort(v.begin(), v.end());
    if (v.size() < 4) {
        std::cout << v.back() - v.front();
        return 0;
    }
    dp[1] = v[1] - v[0];
    dp[2] = v[2] - v[0];
    for (int i = 3; i < n; i++) {
        dp[i] = std::min(dp[i - 1], dp[i - 2]) + v[i] - v[i - 1];
    }
    std::cout << dp.back();
    return 0;
}