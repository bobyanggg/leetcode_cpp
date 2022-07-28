#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<bitset<101>> m;
        m.resize(n);
        for (auto &e : roads)
            m[e[0]][e[1]] = m[e[1]][e[0]] = 1;

        int max = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int sum = m[i].count() + m[j].count();
                if (m[i][j] == 1)
                    sum--;

                if (sum > max)
                    max = sum;
            }
        }
        return max;
    }
};

int main()
{
    vector<vector<int>> msg{{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
    Solution s;
    cout << s.maximalNetworkRank(5, msg);
}
