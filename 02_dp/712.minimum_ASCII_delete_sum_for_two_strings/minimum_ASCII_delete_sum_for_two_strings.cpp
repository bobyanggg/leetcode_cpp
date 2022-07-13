#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();
        int dp[m + 1][n + 1];

        for (int i = 0; i < m + 1; i++)
        {

            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                if (i == 0)
                {
                    dp[0][j] = dp[0][j - 1] + int(s2[j - 1]);
                }
                else if (j == 0)
                {
                    dp[i][0] = dp[i - 1][0] + int(s1[i - 1]);
                }
                else
                {
                    int topLeft = dp[i - 1][j - 1];
                    if (s1[i - 1] != s2[j - 1])
                    {
                        topLeft = topLeft + int(s1[i - 1]) + int(s2[j - 1]);
                    }
                    int left = dp[i][j - 1] + int(s2[j - 1]);
                    int top = dp[i - 1][j] + int(s1[i - 1]);
                    dp[i][j] = min(min(topLeft, left), top);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    cout << s.minimumDeleteSum("delete", "leet");
}