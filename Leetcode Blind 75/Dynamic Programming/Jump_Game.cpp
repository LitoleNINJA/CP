class Solution {
public:
    bool canJump(vector<int>& a) {
        // O(n^2) dp
        int n = a.size();
        // vector<int> dp(n+1);
        // dp[n-1] = 1;
        // for(int i=n-2; i>=0; i--)
        // {
        //     for(int j=a[i]; j>0; j--)
        //         if(i+j < n && dp[i+j] == 1)
        //         {
        //             dp[i] = 1;
        //             break;
        //         }
        // }
        // return dp[0];


        // O(n)
        int i = 0;
        for (int mx = 0; i < n && i <= mx; i++)
            mx = max(mx, i + a[i]);
        return i == n;
    }
};