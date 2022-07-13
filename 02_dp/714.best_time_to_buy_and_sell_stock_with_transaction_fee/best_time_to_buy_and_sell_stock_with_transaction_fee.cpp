#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int len = prices.size();
        if (len <= 1)
        {
            return 0;
        }

        int hold = -prices[0], sell = 0;

        for (int i = 1; i < len; i++)
        {
            int tempSold = sell;
            sell = max(sell, hold + prices[i] - fee);
            hold = max(hold, tempSold - prices[i]);
        }
        return max(sell, hold);
    }
};

int main()
{
    vector<int> arr{1, 5, 9};
    Solution s;
    cout << s.maxProfit(arr, 2);
}