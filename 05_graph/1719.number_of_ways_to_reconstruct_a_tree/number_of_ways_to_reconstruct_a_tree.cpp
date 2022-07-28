#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int checkWays(vector<vector<int>> &pairs)
    {
        // Construct a map, key is the node, value is the accessible nodes.
        unordered_map<int, bitset<501>> m;
        for (auto &e : pairs)
            m[e[0]][e[0]] = m[e[1]][e[1]] = m[e[0]][e[1]] = m[e[1]][e[0]] = 1;

        // The tree must have one+ node/root that has paths to all the nodes.
        if (!any_of(begin(m), end(m), [&m](const auto &kv)
                    { return kv.second.count() == m.size(); }))
            return 0;

        int multiple = 0;
        for (const auto &e : pairs)
        {
            // For each pair, check whether one can be the parent of another
            // that can conver all the children nodes.
            const auto &all = m[e[0]] | m[e[1]];
            const int r0 = m[e[0]] == all;
            const int r1 = m[e[1]] == all;
            if (r0 + r1 == 0)
                return 0;
            // If both can be parents, there can be multiple trees.
            multiple |= r0 * r1;
        }
        return 1 + multiple;
    }
};

int main()
{
    vector<vector<int>> msg{{3, 4}, {2, 3}, {4, 5}, {2, 4}, {2, 5}, {1, 5}, {1, 4}};
    Solution s;
    cout << s.checkWays(msg);
}