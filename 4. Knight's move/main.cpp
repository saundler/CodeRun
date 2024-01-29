#include <iostream>
#include <map>

static std::map<std::pair<int, int>, int> mp;

int WayCount(int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    }
    if (!i && !j) {


        return 1;
    }
    std::pair<int, int> tmp_key = std::make_pair(i, j);
    if (mp.find(tmp_key) != mp.end()){
        return mp[tmp_key];
    }
    mp[tmp_key] = WayCount(i - 1, j - 2) + WayCount(i - 2, j - 1);
    return mp[tmp_key];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << WayCount(n - 1, m - 1);
    return 0;
}
