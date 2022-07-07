class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0')
            return 0;
        if (n == 1)
            return 1;
        int dp[n];
        dp[0] = 1;
        dp[1] = (s[0] == '1' || s[0] == '2' && s[1] < '7' ? 1 : 0) + (s[1] != '0');
        for (int i = 2; i < n; i++)
        {
            if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0' ))
                return 0;
            dp[i] = (s[i] != '0' ? dp[i - 1] : 0);
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7')
                dp[i] += dp[i - 2];
        }
        return dp[n - 1];
    }
};