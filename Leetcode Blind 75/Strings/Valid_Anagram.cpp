class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if (n1 != n2)
            return false;
        vector<int> fre(26);
        for (int i = 0; i < n1; i++)
            fre[s[i] - 'a']++;
        for (int i = 0; i < n2; i++)
        {
            if (fre[t[i] - 'a'] > 0)
                fre[t[i] - 'a']--;
            else
                return false;
        }
        return true;
    }
};