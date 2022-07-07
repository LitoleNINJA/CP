class Solution {
public:
    int coinChange(vector<int>& a, int t) {
        int dp[10001];
        int n = a.size();
        if (n == 0 || t == 0)
            return t == 0 ? 0 : -1;
        int mn = 1e9;
        for (int i = 0; i <= t; i++)
            dp[i] = 0;
        for (int i = 1; i <= t; i++)
        {
            mn = 1e9;
            for (int j = 0; j < n; j++)
            {
                if (i - a[j] >= 0 && dp[i - a[j]] != -1)
                    if (dp[i - a[j]] < mn)
                        mn = dp[i - a[j]];
            }
            if (mn != 1e9)
                dp[i] = mn + 1;
            else
                dp[i] = -1;
        }
        return dp[t];
    }
};