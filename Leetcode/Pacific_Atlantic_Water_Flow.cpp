class Solution {
public:
    // We start from the cells connected to altantic ocean and visit all cells having height
    // greater than current cell. Next, we start from the cells connected to pacific ocean and
    // repeat the same process. The final answer we get will be the intersection of sets.
    int n, m;
    void dfs(vector<vector<int>>& a, vector<vector<bool>>& b, int i, int j)
    {
        b[i][j] = true;
        if (i + 1 < n && a[i + 1][j] >= a[i][j] && !b[i + 1][j])
            dfs(a, b, i + 1, j);
        if (i - 1 >= 0 && a[i - 1][j] >= a[i][j] && !b[i - 1][j])
            dfs(a, b, i - 1, j);
        if (j + 1 < m && a[i][j + 1] >= a[i][j] && !b[i][j + 1])
            dfs(a, b, i, j + 1);
        if (j - 1 >= 0 && a[i][j - 1] >= a[i][j] && !b[i][j - 1])
            dfs(a, b, i, j - 1);
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        vector<vector<bool>> m1(n, vector<bool>(m, false));
        vector<vector<bool>> m2(n, vector<bool>(m, false));
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            dfs(a, m1, i, 0);
            dfs(a, m2, i, m - 1);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(a, m1, 0, i);
            dfs(a, m2, n - 1, i);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (m1[i][j] && m2[i][j])
                    ans.push_back(vector<int> {i, j});
        return ans;
    }
};