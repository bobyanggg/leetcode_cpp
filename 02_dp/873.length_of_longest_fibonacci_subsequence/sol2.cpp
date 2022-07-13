#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &A)
    {
        const int n = A.size();
        unordered_set<int> m(begin(A), end(A));
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                int a = A[i];
                int b = A[j];
                int c = a + b;
                int l = 2;
                while (m.count(c))
                {
                    a = b;
                    b = c;
                    c = a + b;
                    ans = max(ans, ++l);
                }
            }
        return ans;
    }
};