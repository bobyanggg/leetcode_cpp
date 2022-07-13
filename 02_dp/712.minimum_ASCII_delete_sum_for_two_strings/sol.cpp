#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int a = s1.size();
        int b = s2.size();

        int dp[a + 1][b + 1];
        int t1 = 0, t2 = 0;
        for (int i = 0; i < a; i++)
        {
            t1 += (int)s1[i];
            dp[i][0] = 0;
        }
        for (int i = 0; i < b; i++)
        {
            t2 += (int)s2[i];
            dp[0][i] = 0;
        }

        dp[a][0] = 0;
        dp[0][b] = 0;

        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = (int)s1[i - 1] + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return t1 + t2 - (2 * dp[a][b]);
    }
};

int main()
{
    Solution s;
    cout << s.minimumDeleteSum("delete", "leet");
}