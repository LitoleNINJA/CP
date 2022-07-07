class Solution {
public:
    bool isPalin(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
            if (s[i] != s[n - 1 - i])
                return false;
        return true;
    }
    bool isPalindrome(string s) {
        string ans;
        for (char ch : s)
        {
            int val = int(ch);
            if (isalpha(ch) || isdigit(ch))
                ans.push_back(tolower(ch));
        }
        return isPalin(ans);
    }
};