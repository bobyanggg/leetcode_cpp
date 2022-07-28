#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int averageOfSubtree(TreeNode *root)
    {
        auto [s, sum, matches] = dfs(root);
        return matches;
    }

private:
    // number of childs/sum of childs/number of child matches
    tuple<int, int, int> dfs(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0, 0};

        auto [ls, lSum, lmatches] = dfs(root->left);
        auto [rs, rSum, rmatches] = dfs(root->right);
        int matched = 0;
        if (root->val == (root->val + lSum + rSum) / (ls + rs + 1))
            return {ls + rs + 1, lSum + rSum + root->val, lmatches + rmatches + 1};
        return {ls + rs + 1, lSum + rSum + root->val, lmatches + rmatches};
    }
};

int main()
{
    TreeNode node0 = TreeNode(0);
    TreeNode node1 = TreeNode(1);
    TreeNode node6 = TreeNode(6);
    TreeNode node8 = TreeNode(8, &node0, &node1);
    TreeNode node5 = TreeNode(5, nullptr, &node6);
    TreeNode node4 = TreeNode(4, &node8, &node5);

    Solution s;
    cout << s.averageOfSubtree(&node4) << endl;
}