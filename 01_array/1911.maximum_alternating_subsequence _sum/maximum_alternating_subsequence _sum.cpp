#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	long long maxAlternatingSum(vector<int> &nums)
	{
		long long odd = 0;
		long long even = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			long long temp = odd;
			odd = max(odd, even - nums[i]);
			even = max(even, max((long long)nums[i], temp + nums[i]));
		}
		return max(even, odd);
	}
};

int main()
{
	vector<int> msg{6, 2, 1, 2, 4, 5};
	Solution s;
	cout << s.maxAlternatingSum(msg);
}
