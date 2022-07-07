class Solution {
public:

//     P(i, j) == P(i+1, j-1) && s[i] == s[j];

//     Base cases :

//     //One character
//     P(i, i) = true;

//     //Two character
//     P(i, i+1) = s[i] == s[i+1];

//     Time Complexity - O(N^2), Space Complexity - O(N^2) (caching all substring)

    string longestPalindrome(string s) {
        int n = s.length();
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        string ans = "";
        ans += s[0];
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        dp[i][j] = 1;
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        return ans;
    }
};