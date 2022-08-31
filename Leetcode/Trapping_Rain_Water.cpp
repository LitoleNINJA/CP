class Solution {
public:
    // 1. A ith bar can trap the water if and only if there exists a higher bar to the left and a higher bar to the right of ith bar.
    // 2. The water level can be formed at ith bar is: waterLevel = min(maxLeft[i], maxRight[i])
    // 3. If waterLevel >= height[i] then ith bar can trap waterLevel - height[i] amount of water.
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> left(n), right(n);
        left[0] = a[0];
        right[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], a[i]);
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], a[i]);

        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            ans += min(left[i], right[i]) - a[i];
        return ans;
    }
};