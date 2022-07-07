class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = a[0];
        for (int i = 1; i < n; i++)
            dp[i + 1] = max(dp[i], (a[i] + dp[i - 1]));
        return dp[n];
    }
};