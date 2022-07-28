#include <iostream>
#include <vector>
#include <string>

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
    int count = 0;
    pair<int, int> solve(TreeNode *root)
    {
        pair<int, int> left = root->left ? solve(root->left) : make_pair(0, 0);
        pair<int, int> right = root->right ? solve(root->right) : make_pair(0, 0);
        int sum = root->val + left.second + right.second;
        int nodes = left.first + right.first + 1;
        int value = sum / nodes;
        if (value == root->val)
            count++;
        return make_pair(nodes, sum);
    }
    int averageOfSubtree(TreeNode *root)
    {
        solve(root);
        return count;
    }
};