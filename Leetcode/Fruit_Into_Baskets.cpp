class Solution {
public:
    // Longest subarray not having more than 2 distinct elements.
    int totalFruit(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> m;
        int l = 0, r = 0, cnt = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            m[a[i]]++;
            if (m[a[i]] == 1)
                cnt++;
            while (cnt > 2)
            {
                m[a[l]]--;
                if (m[a[l]] == 0)
                    cnt--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};