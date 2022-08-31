class Solution {
public:
    // The idea is simpy to start from the beginWord, then visit its neighbors, then the non-visited neighbors of its neighbors until we arrive at the endWord.
    // This is a typical BFS structure.
    int ladderLength(string beginWord, string endWord, vector<string>& a) {
        set<string> s(a.begin(), a.end());
        if (s.find(endWord) == s.end())
            return 0;
        queue<string> q;
        set<string> vis;
        vis.insert(beginWord);
        q.push(beginWord);
        int ans = 1;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string f = q.front();
                q.pop();
                if (f == endWord)
                    return ans;
                s.erase(f);
                for (int j = 0; j < f.size(); j++)
                {
                    char temp = f[j];
                    for (char k = 'a'; k <= 'z'; k++)
                    {
                        f[j] = k;
                        if (s.find(f) != s.end() && vis.find(f) == vis.end())
                        {
                            q.push(f);
                            vis.insert(f);
                        }
                    }
                    f[j] = temp;
                }
            }
            ans++;
        }
        return 0;
    }
};