class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int suf[n];
        suf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = max(a[i], suf[i + 1]);
        int p, m = -1;
        for (int i = 0; i < n - 1; i++)
        {
            p = suf[i + 1] - a[i];
            m = max(p, m);
        }
        if (m <= 0)
            return 0;
        return m;
    }
};