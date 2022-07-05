#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	bool PredictTheWinner(vector<int> &nums)
	{
		int n = nums.size();
		if (n % 2 == 0)
		{
			return true;
		}

		vector<vector<int>> dp(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; (i + j) < n; j++)
			{
				if (i == 0)
				{
					dp[j][i + j] = nums[j];
				}
				else
				{
					dp[j][i + j] = max(nums[i + j] - dp[j][i + j - 1], nums[j] - dp[j + 1][i + j]);
				}
			}
		}

		if (dp[0][n - 1] >= 0)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	vector<int> msg{1, 5, 2};
	Solution s;
	cout << s.PredictTheWinner(msg);
}