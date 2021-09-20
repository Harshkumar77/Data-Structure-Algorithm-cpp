#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<vector<string>> ans = {};
    vector<vector<vector<string>>> dp = {};

    string substr(string s, int from, int to)
    {
        string st = "";
        if (from >= s.length() || to >= s.length())
            return "";
        for (int i = from; i <= to; i++)
            st.push_back(s[i]);
        // cout << st << '\n';
        return st;
    }
    bool isP(string s, int size)
    {
        int l = 0;
        int r = size - 1;
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    void util(string st, vector<string> v = {})
    {
        if (st.empty())
            ans.push_back(v);
        else
            for (int i = 1; i <= st.size(); i++)
            {
                vector<string> v1 = v;
                if (isP(st, i))
                {

                    v1.push_back(substr(st, 0, i - 1));
                    util(substr(st, i, st.length() - 1), v1);
                }
            }
    }
    vector<vector<string>> partition(string s)
    {
        util(s);
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution obj = Solution();
    for (vector<string> v : obj.partition(s))
    {
        for (string st : v)
            cout << st << ' ';
        cout << '\n';
    }
    cout << '\n';
    return 0;
}
