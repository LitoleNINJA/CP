class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int mx = a[0], mn = a[0], ans = a[0];
        for (int i = 1; i < n; i++)
        {
            int t = mx;
            mx = max(mx * a[i], max(mn * a[i], a[i]));
            mn = min(t * a[i], min(mn * a[i], a[i]));

            ans = max(ans, mx);
        }
        return ans;
    }
};