class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        int pre[n], suf[n];
        pre[0] = a[0];
        suf[n - 1] = a[n - 1];
        vector<int> ans;
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] * a[i];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] * a[i];
        for (int i = 0; i < n; i++)
        {
            int prod;
            if (i == 0)
                prod = suf[i + 1];
            else if (i == n - 1)
                prod = pre[i - 1];
            else
                prod = pre[i - 1] * suf[i + 1];
            ans.push_back(prod);
        }
        return ans;
    }
};