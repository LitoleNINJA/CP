class Solution {
public:
    int robber(vector<int> a, int l, int r)
    {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++)
        {
            int mx = max(cur, pre + a[i]);
            pre = cur;
            cur = mx;
        }
        return cur;
    }
    int rob(vector<int>& a) {
        int n = a.size();
        if (n < 2)
            return n ? a[0] : 0;
        return max(robber(a, 0, n - 2), robber(a, 1, n - 1));
    }
};