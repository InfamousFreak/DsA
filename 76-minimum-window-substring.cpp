class Solution
{
public:
    string minWindow(string s, string t)
    {
        int l = 0, r = 0;

        unordered_map<int, int> map; // hashmap for t
        for (int i = 0; i < t.size(); ++i)
        {
            map[t[i]]++;
        }

        int i = 0, j = 0;

        // hash of chars in t that must be in s
        int counter = t.size();

        int minStart = 0;
        int minlength = INT_MAX;

        while (j < s.size())
        {
            if (map[s[j]] > 0)
            {
                counter--;
            }

            map[s[j]]--; // chars that are not in t will have their frequency negative
            j++;         // increment j for window

            while (counter == 0)
            { // perfect window found
                if (j - i < minlength)
                {
                    minStart = i;
                    minlength = j - i;
                }

                map[s[i]]++;

                // when char exists in t, increase
                if (map[s[i]] > 0)
                {
                    counter++;
                }
                i++;
            }
        }

        if (minlength != INT_MAX)
        {
            return s.substr(minStart, minlength);
        }
        return "";
    }
};