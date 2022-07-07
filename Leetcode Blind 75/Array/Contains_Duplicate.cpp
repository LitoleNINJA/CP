class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        int n = a.size();
        set<int> s;
        for (int i = 0; i < n; i++)
            s.insert(a[i]);
        if (s.size() == n)
            return false;
        return true;
    }
};