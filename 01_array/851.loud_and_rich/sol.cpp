#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        vector<vector<int>> myvec(quiet.size(), vector<int>());
        for (int i = 0; i < richer.size(); i++)
        {
            myvec[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int> res(quiet.size(), -1);
        for (int i = 0; i < res.size(); i++)
        {
            dfs(quiet, i, res, myvec);
        }
        return res;
    }
    int dfs(vector<int> &quiet, int i, vector<int> &res, vector<vector<int>> &myvec)
    {
        if (res[i] != -1)
            return res[i];
        res[i] = i;
        for (auto k : myvec[i])
        {
            if (quiet[dfs(quiet, k, res, myvec)] <= quiet[res[i]])
            {
                res[i] = res[k];
            }
        }
        return res[i];
    }
};

int main()
{
    // Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
    // Output: [5,5,2,5,4,5,6,7]
    vector<vector<int>> msg{{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    vector<int> quiet{3, 2, 5, 4, 6, 1, 7, 0};
    // vector<vector<int>> msg{};
    // vector<int> quiet{0};
    Solution s;
    vector<int> result = s.loudAndRich(msg, quiet);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}