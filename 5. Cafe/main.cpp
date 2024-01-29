#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << "\n" << 0 << " " << 0;
        return 0;
    }
    std::vector<int> inputs(n);
    for (int &i: inputs) {
        std::cin >> i;
    }
    std::vector<std::vector<std::pair<int, std::vector<int>>>> dp(1);
    if(inputs.front() > 100) {
        dp.front().emplace_back(-1, std::vector<int>());
        dp.front().emplace_back(inputs.front(), std::vector<int>());
    } else {
        dp.front().emplace_back(inputs.front(), std::vector<int>());
    }
    for (int i = 1; i < n; ++i) {
        dp.emplace_back(dp[i - 1].size() + 1, std::make_pair(-1, std::vector<int>()));
        for (int j = 0; j < dp[i - 1].size(); ++j) {
            if (dp[i - 1][j].first == -1) {
                continue;
            }
            if (inputs[i] < 101 && (dp[i][j].first == -1 || dp[i][j].first > dp[i - 1][j].first + inputs[i])) {
                dp[i][j].first = dp[i - 1][j].first + inputs[i];
                dp[i][j].second = dp[i - 1][j].second;
            }
            if (inputs[i] > 100 && (dp[i][j + 1].first == -1 || dp[i][j + 1].first > dp[i - 1][j].first + inputs[i])) {
                dp[i][j + 1].first = dp[i - 1][j].first + inputs[i];
                dp[i][j + 1].second = dp[i - 1][j].second;
            }
            if (j > 0 && (dp[i][j - 1].first == -1 || dp[i][j - 1].first > dp[i - 1][j].first)) {
                dp[i][j - 1] = dp[i - 1][j];
                dp[i][j - 1].second.push_back(i);
            }
        }
        if(dp[i].back().first == -1) {
            dp[i].pop_back();
        }
    }
    std::pair<int, std::vector<int>> ans = dp.back().front();
    int k = 0;
    for (int i = 1; i < dp.back().size(); ++i) {
        if (dp.back()[i].first == -1) {
            continue;
        }
        if (ans.first == -1 || dp.back()[i].first <= ans.first) {
            k = i;
            ans = dp.back()[i];
        }
    }
    std::cout << ans.first << "\n" << k << " " << ans.second.size() << std::endl;
    for(int &i: ans.second) {
        std::cout << i + 1 << std::endl;
    }
    return 0;
}
