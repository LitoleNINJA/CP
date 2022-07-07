class Solution {
public:
    // T(n) ==> O(n lgn)
    // store {ele} in set
    // if(next elem in set = prev elem in set + 1)
    //      cnt ++
    // else
    //      cnt = 1
    // return max(cnt)

    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        // O(n lgn)
        set<int> s;
        for (int i : a)
            s.insert(i);
        int ans = 0, cur = 0, prev = INT_MIN;
        for (auto itr : s)
        {
            if (prev == INT_MIN)
            {
                prev = itr;
                cur = 1;
            }
            else
            {
                if (itr == prev + 1)
                    cur ++;
                else
                    cur = 1;
                prev = itr;
            }
            ans = max(ans, cur);
        }
        return ans;

    }
};