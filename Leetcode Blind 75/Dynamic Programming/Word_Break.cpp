class Solution {
public:
    bool wordBreak(string s, vector<string>& a) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (string j : a)
            {
                int m = j.size() - 1, temp = i;
                while (temp > 0 && j[m] == s[temp - 1])
                    m--, temp--;
                dp[i] = dp[temp];
            }
        }
        for (auto i : dp)
            cout << i << ' ';
        return false;
    }
};