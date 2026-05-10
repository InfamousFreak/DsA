class Solution
{
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();

        string original = s;
        string strrev = s; // will store both string and * and string reversed
        reverse(s.begin(), s.end());
        strrev += '*' + s;

        vector<int> lps(2 * n + 1);
        int i = 0, j = 1;

        while (j < strrev.size())
        {
            if (strrev[i] == strrev[j])
            {
                lps[j] = i + 1;
                i++;
                j++;
            }
            if (j == strrev.size())
                break;
            if (strrev[i] != strrev[j])
            {
                if (i > 0)
                {
                    i = lps[i - 1];
                }
                else
                {
                    lps[j] = 0;
                    j++;
                }
            }
        }
        // marks the number of characters to be appended
        int diff = n - lps[2 * n];

        original = s.substr(0, diff) + original;
        return original;
    }
};