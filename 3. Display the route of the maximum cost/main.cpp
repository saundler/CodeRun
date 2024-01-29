#include <iostream>
#include <vector>
#include <climits>
#include <map>

static std::map<std::pair<int, int>, std::pair<int, std::string>> mp;

std::pair<int, std::string> FindCheapestWay(std::vector<std::vector<int>> &v, int i, int j) {
    if (i < 0 || j < 0) {
        return std::make_pair(INT_MIN, "");
    }
    if (!i && !j) {
        return std::make_pair(v[i][j], "");
    }
    std::pair<int, int> tmp_key = std::make_pair(i, j);
    if (mp.find(tmp_key) != mp.end()){
        return mp[tmp_key];
    }
    std::pair<int, std::string> up_tmp = FindCheapestWay(v, i - 1, j);
    std::pair<int, std::string> left_tmp = FindCheapestWay(v, i, j - 1);
    if(up_tmp.first > left_tmp.first) {
        mp[tmp_key] = std::make_pair(v[i][j] + up_tmp.first, up_tmp.second + "D ");
        return mp[tmp_key];
    }
    mp[tmp_key] = std::make_pair(v[i][j] + left_tmp.first, left_tmp.second + "R ");
    return mp[tmp_key];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> v(n, std::vector<int>(m));
    for (std::vector<int> &i: v) {
        for (int &j: i) {
            std::cin >> j;
        }
    }
    std::pair<int, std::string> ans = FindCheapestWay(v, n - 1, m - 1);
    std::cout << ans.first << '\n' << ans.second;
    return 0;
}
