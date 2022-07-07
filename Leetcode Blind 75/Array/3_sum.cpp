class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        unordered_map<int, int> m;
        int n = a.size();
        sort(a.begin(), a.end());
        if (n < 3 || a[0] > 0)
            return {};
        for (int i = 0; i < n; i++)
            m[a[i]] = i;
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            if (a[i] > 0)
                break;
            for (int j = i + 1; j < n - 1; j++)
            {
                int x = -1 * (a[i] + a[j]);
                if (m.count(x) > 0 && m.find(x)->second > j)
                    ans.push_back({a[i], a[j], x});
                j = m.find(a[j])->second;
            }
            i = m.find(a[i])->second;
        }
        return ans;
    }
};