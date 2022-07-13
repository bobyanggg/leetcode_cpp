#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &A)
    {
        const int n = A.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i)
            m[A[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        for (int j = 0; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
            {
                int a_i = A[k] - A[j];
                if (a_i >= A[j])
                    break; // pruning 168 ms -> 68 ms
                auto it = m.find(a_i);
                if (it == end(m))
                    continue;
                int i = it->second;
                dp[j][k] = dp[i][j] + 1;
                ans = max(ans, dp[j][k]);
            }
        return ans;
    }
};

int main()
{
    vector<int> arr{1, 3, 7, 11, 12, 14, 18};
    Solution s;
    cout << s.lenLongestFibSubseq(arr);
}