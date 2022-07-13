#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{

    // declaration for new bst node
    struct node
    {
        int quiet;
        int idx;
        vector<node *> childs;
        struct node *smallest;
        bool visited;
    };

public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {

        vector<node *> arr;
        for (int i = 0; i < quiet.size(); ++i)
        {
            node *newNode = new node();
            newNode->idx = i;
            newNode->quiet = quiet[i];
            newNode->visited = false;
            newNode->smallest = newNode;
            arr.push_back(newNode);
        }

        for (int i = 0; i < richer.size(); ++i)
        {
            int parent = richer[i][1], child = richer[i][0];
            arr[parent]->childs.push_back(arr[child]);
        }

        for (int i = 0; i < arr.size(); ++i)
        {
            helper(arr[i]);
        }

        vector<int> result;
        for (int i = 0; i < arr.size(); ++i)
        {
            result.push_back(arr[i]->smallest->idx);
        }
        return result;
    }

private:
    void helper(node *root)
    {
        if (root->visited)
        {
            return;
        }
        for (int i = 0; i < root->childs.size(); ++i)
        {
            node *child = root->childs[i];
            helper(child);
            if (child->smallest->quiet < root->smallest->quiet)
            {
                root->smallest = child->smallest;
            }
        }
        root->visited = true;
    }
};

int main()
{
    // Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
    // Output: [5,5,2,5,4,5,6,7]
    // vector<vector<int>> msg{{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    // vector<int> quiet{3, 2, 5, 4, 6, 1, 7, 0};
    vector<vector<int>> msg{};
    vector<int> quiet{0};
    Solution s;
    vector<int> result = s.loudAndRich(msg, quiet);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}