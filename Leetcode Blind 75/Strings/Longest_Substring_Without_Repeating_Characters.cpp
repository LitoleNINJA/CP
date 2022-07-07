class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Sliding window
        int n = s.length();
        vector<int> vis(256, 0);
        int l = 0, r = 0, cnt = 0;
        while (r < n)
        {
            vis[s[r]]++;
            while (vis[s[r]] > 1)
            {
                vis[s[l]]--;
                l++;
            }
            cnt = max(cnt, r - l + 1);
            r++;
        }
        return cnt;
    }
};