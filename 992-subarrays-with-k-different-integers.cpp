class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atmostK(nums, k) - atmostK(nums, k - 1);
    }

private:
    int atmostK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, count = 0;

        unordered_map<int, int> freq;

        for (int r = 0; r < n; ++r)
        {
            if (freq[nums[r]] == 0)
                k--;
            freq[nums[r]]++;

            while (k < 0)
            {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    k++;
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }
};