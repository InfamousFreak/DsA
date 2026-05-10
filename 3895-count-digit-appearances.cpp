class Solution
{
public:
    int countDigitOccurrences(vector<int> &nums, int digit)
    {
        int total_count = 0;

        vector<int> solqaviren = nums;

        for (int num : solqaviren)
        {

            while (num > 0)
            {

                if (num % 10 == digit)
                {

                    total_count++;
                }

                num /= 10;
            }
        }

        return total_count;
    }
};