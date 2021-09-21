#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<int> s;
    string ans = "";
    vector<int> fact;

    void compute(int n)
    {
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = fact[i - 1] * i;
        }
    }

    void util(int k)
    {
        int n = s.size();
        if (n == 1)
        {
            ans.push_back('0' + *s.begin());
            return;
        }
        int window_size = fact[n - 1];
        // cout << window_size;

        int window_index = k / window_size;
        // cout << window_index;
        int num = *next(s.begin(), window_index);
        ans.push_back('0' + num);
        s.erase(num);
        int newK = k - window_size * window_index;
        util(newK);
    }

    string getPermutation(int n, int k)
    {
        fact = vector<int>(n + 1);
        compute(n);
        // compute required factorials
        for (int i = 1; i <= n; i++)
            s.insert(i);
        k--;
        util(k);
        return ans;
    }
};

int main()
{
    int n, k;
    Solution s = Solution();
    cin >> n >> k;
    cout << s.getPermutation(n, k) << '\n';
    return 0;
}