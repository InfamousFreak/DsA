class Solution
{
public:
    unordered_map<int, unordered_set<int>> memo;
    bool dfs(int idx, int lastJump, vector<int> &stones)
    {
        int n = stones.size();

        if (idx == n - 1)
            return true;

        if (memo[idx].count(lastJump))
            return false;

        for (int jump = lastJump - 1; jump <= lastJump + 1; jump++)
        {
            if (jump <= 0)
                continue;

            int nextPos = stones[idx] + jump;

            for (int i = idx + 1; i < n; i++)
            {
                if (stones[i] == nextPos)
                {
                    if (dfs(i, jump, stones))
                        return true;
                }
            }
        }
        memo[idx].insert(lastJump);
        return false;
    }

    bool canCross(vector<int> &stones)
    {

        if (stones[1] != 1)
            return false;

        return dfs(1, 1, stones);
    }
};