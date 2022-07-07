class Solution {
public:
    void showstack(stack<char> s)
    {
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
    char counter(char c)
    {
        if (c == ')')
            return '(';
        else if (c == '}')
            return '{';
        else
            return '[';
    }
    bool isValid(string a) {
        int n = a.length();
        stack<char> s;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '(' || a[i] == '{' || a[i] == '[')
                s.push(a[i]);
            else
            {
                if (s.empty())
                    return false;
                if (s.top() == counter(a[i]))
                    s.pop();
                else
                    return false;
            }
        }
        if (s.empty())
            return true;
        return false;
    }
};