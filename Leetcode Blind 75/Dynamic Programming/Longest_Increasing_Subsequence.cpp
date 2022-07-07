class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        // DP ---> O(n^2)
        // int dp[n], ans = 0;
        // dp[0] = 1;
        // for(int i=1; i<n; i++)
        // {
        //     int mx = 1;
        //     for(int j=0; j<i; j++)
        //         if(a[j] < a[i])
        //             mx = max(mx, dp[j] + 1);
        //     dp[i] = mx;
        //     ans = max(ans, dp[i]);
        // }
        // return ans;

        // Binary Search ---> O(n lgn)
        int l = 0;
        for (int i : a)
        {
            if (l == 0 || a[l - 1] < i)
                a[l++] = i;
            else
                *lower_bound(a.begin(), a.begin() + l, i) = i;
        }
        return l;
    }
};