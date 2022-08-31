class Solution {
public:
    // 1. For each cell matrix[i][j], we find the longest path that we can go to, starting from the current cell such that each next cell value in the path is greater than the previous cell value.
    // 2. Repeated calculation can be avoided if we use dynamic programming to store the previously calculated results.
    int ans, n, m;
    int dp[200][200];
    int findPath(vector<vector<int>>& a, int i, int j, int k)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] <= k)
            return 0;
        if (dp[i][j] > 0)
            return dp[i][j];
        return dp[i][j] = 1 + max({
            findPath(a, i + 1, j, a[i][j]),
            findPath(a, i, j + 1, a[i][j]),
            findPath(a, i - 1, j, a[i][j]),
            findPath(a, i, j - 1, a[i][j])
        });
    }
    int longestIncreasingPath(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = max(ans, findPath(a, i, j, -1));
        return ans;
    }
};