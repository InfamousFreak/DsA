class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& current_permutation, vector<bool>& visited, vector<vector<int>>& final_result) {

        if (current_permutation.size() == nums.size()) {
            final_result.push_back(current_permutation);
            return; 
        }


        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            if (i > 0 && nums[i] == nums[i - 1] && !visited[i-1]) {
                continue;
            }


            visited[i] = true;
            current_permutation.push_back(nums[i]);

            backtrack(nums, current_permutation, visited, final_result);

            current_permutation.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> final_result;
        vector<int> current_permutation;
        vector<bool> visited(nums.size(), false);

        sort(nums.begin(), nums.end());

        backtrack(nums, current_permutation, visited, final_result);

        return final_result;

    }
};