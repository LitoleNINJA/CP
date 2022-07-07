class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i - 1, k = i;
            while (k < n - 1 && s[k] == s[k + 1])
                k++;
            cnt += (k - j) * (k - j + 1) / 2;
            i = k++;
            while (j >= 0 && k < n && s[k++] == s[j--])
                cnt++;
        }
        return cnt;
    }
};