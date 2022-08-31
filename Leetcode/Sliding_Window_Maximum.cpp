class Solution {
public:
    // Use a monotonic queue (always sorted).
    // https://abitofcs.blogspot.com/2014/11/data-structure-sliding-window-minimum.html
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && a[q.back()] <= a[i])
                q.pop_back();
            q.push_back(i);
            if (q.front() == i - k)
                q.pop_front();
            if (i >= k - 1)
                ans.push_back(a[q.front()]);
        }
        return ans;
    }
};