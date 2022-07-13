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
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        for (int j = 0; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
            {
                int a_i = A[k] - A[j];
                if (a_i >= A[j])
                    break;
                auto it = lower_bound(begin(A), begin(A) + j, a_i);
                int i = it - begin(A);
                if (A[i] != a_i)
                    continue;
                dp[j][k] = dp[i][j] + 1;
                ans = max(ans, dp[j][k]);
            }
        return ans;
    }
};

int main()
{
    vector<int> arr{1, 5, 9};
    Solution s;
    cout << s.lenLongestFibSubseq(arr);
}