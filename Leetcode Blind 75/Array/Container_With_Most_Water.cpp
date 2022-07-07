class Solution {
public:
    int maxArea(vector<int>& a) {
        int ans = -1;
        int l = 0, r = a.size() - 1;
        while (l < r)
        {
            int d = min(a[l], a[r]);
            ans = max(ans, d * (r - l));
            while (l < r && a[l] <= d)
                l++;
            while (l < r && a[r] <= d)
                r--;
        }
        return ans;
    }
};