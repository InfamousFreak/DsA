class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> choc(n, 1);
        int count = 0;

        for (int i = 1; i < n; i++)
        {
            if (ratings[i - 1] < ratings[i])
            {
                choc[i] = choc[i - 1] + 1;
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
            {
                choc[i - 1] = max(choc[i] + 1, choc[i - 1]);
            }
            count += choc[i - 1];
        }
        return count + choc[n - 1];
    }
};minimum-window-substring