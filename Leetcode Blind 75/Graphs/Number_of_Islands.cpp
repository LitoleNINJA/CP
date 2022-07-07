class Solution {
public:
    vector<vector<int>> dir = {
        {0, 1},
        {0, -1},
        {1, 0},
        { -1, 0}
    };
    void dfs(vector<vector<char>>& a, int i, int j, int n, int m)
    {
        a[i][j] = '2';
        for (vector<int> d : dir)
        {
            if (i + d[0] >= 0 && i + d[0] < n && j + d[1] >= 0 && j + d[1] < m && a[i + d[0]][j + d[1]] == '1')
                dfs(a, i + d[0], j + d[1], n, m);
        }
        return;
    }
    int numIslands(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == '1')
                {
                    dfs(a, i, j, n, m);
                    cnt++;
                }
        return cnt;
    }
};