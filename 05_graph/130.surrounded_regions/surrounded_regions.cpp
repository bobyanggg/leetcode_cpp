#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> temp(m, vector<char>(n, 'X'));
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, board, temp);
            dfs(i, n - 1, board, temp);
        }

        for (int i = 0; i < n; i++)
        {
            dfs(0, i, board, temp);
            dfs(m - 1, i, board, temp);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[i][j] != '*')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<char>> &temp)
    {
        if (board[i][j] == 'X' || temp[i][j] == '*')
        {
            return;
        }
        temp[i][j] = '*';
        if (i > 0)
        {
            dfs(i - 1, j, board, temp);
        }
        if (i < board.size() - 1)
        {
            dfs(i + 1, j, board, temp);
        }
        if (j > 0)
        {
            dfs(i, j - 1, board, temp);
        }
        if (j < board[0].size() - 1)
        {
            dfs(i, j + 1, board, temp);
        }
    }
};

int main()
{
    // vector<vector<char>> board{
    //     {'X', 'X', 'X', 'X'},
    //     {'X', 'O', 'O', 'X'},
    //     {'X', 'O', 'O', 'X'},
    //     {'X', 'O', 'X', 'X'},
    // };
    vector<vector<char>> board{
        {'O', 'O'},
        {'O', 'O'},
    };
    Solution s;
    s.solve(board);
    cout << endl;
}
