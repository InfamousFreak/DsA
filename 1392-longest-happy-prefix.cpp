class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = (int)s.size();
        int lps[n];
        lps[0] = 0;
        int i = 0;
        for (int j = 1; j < n; ++j)
        {
            while (i > 0 && s[j] != s[i])
                i = lps[i - 1];
            if (s[j] == s[i])
                ++i;
            lps[j] = i;
        }

        return s.substr(0, lps[n - 1]);
    }
};