class Solution
{
private:
    bool isPrime(int n)
    {

        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6)
        {

            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }

        return true;
    }

public:
    long long minOperations(vector<int> &nums)
    {
        vector<int> qerlanovid = nums;

        long long total_operations = 0;

        for (int i = 0; i < qerlanovid.size(); ++i)
        {
            int current = qerlanovid[i];

            if (i % 2 == 0)
            {

                while (!isPrime(current))
                {

                    current++;

                    total_operations++;
                }
            }
            else
            {

                while (isPrime(current))
                {

                    current++;

                    total_operations++;
                }
            }
        }

        return total_operations;
    }
};