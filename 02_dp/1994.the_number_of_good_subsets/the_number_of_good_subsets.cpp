#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

#define M 1000000007
#define S 1024
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
class Solution
{
public:
    int getMask(int num)
    {
        int mask = 0;
        for (int i = 0; i < 10; i++)
        {
            int factor = 0, p = primes[i];
            while (num % p == 0)
            {
                num /= p;
                factor++;
            }
            if (factor > 1)
                return -1;
            mask |= (factor << i);
        }
        return mask;
    }
    int numberOfGoodSubsets(vector<int> &nums)
    {
        int counts[31] = {0};
        for (auto n : nums)
            counts[n]++;
        int ans, mask, dp[S] = {1};
        for (int i = 2; i <= 30; i++)
        {
            if (counts[i] == 0 || (mask = getMask(i)) == -1)
                continue;
            for (int j = 0; j < S; j++)
            {
                if (mask & j)
                    continue;
                dp[mask | j] = ((long long)dp[j] * counts[i] + dp[mask | j]) % M;
            }
        }
        ans = accumulate(dp + 1, dp + S, 0ll) % M;
        long long a = 1, r = 2, p = counts[1];
        while (p)
        {
            if (p & 1)
                a = a * r % M;
            r = r * r % M;
            p >>= 1;
        }
        return (a * ans) % M;
    }
};

int main()
{
    vector<int> msg{1, 1, 1, 1, 2, 3};
    Solution s;
    cout << s.numberOfGoodSubsets(msg);
}
