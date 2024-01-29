#include <iostream>
#include <vector>
#include <climits>

int FindCheapestWay(std::vector<std::vector<int>> &v, int i, int j) {
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    if (!i && !j) {
        return v[i][j];
    }
    return v[i][j] + std::min(FindCheapestWay(v, i - 1, j), FindCheapestWay(v, i, j - 1));
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
    std::cout << FindCheapestWay(v, n - 1, m - 1);
    return 0;
}
