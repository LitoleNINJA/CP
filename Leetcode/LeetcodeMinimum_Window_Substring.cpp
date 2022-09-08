class Solution {
public:
    // sliding window 2 pointer
    string minWindow(string s, string t) {
        vector<int> fre(128);
        for(char c : t)
            fre[c]++;
        int cnt = t.size(), l = 0, r = 0, len = INT_MAX, st = 0;
        while(r < s.size())
        {
            if(fre[s[r++]]-- > 0)
                cnt--;
            while(cnt == 0)
            {
                if(r - l < len)
                {
                    len = r-l;
                    st = l;
                }
                if(fre[s[l++]]++ == 0)
                    cnt++;
            }
        }
        return len==INT_MAX ? "" : s.substr(st, len);
    }
};
