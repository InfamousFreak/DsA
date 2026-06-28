class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentpartition;

        backtrack(s, 0, currentpartition, result);
        return result;
    }

private: 
    void backtrack(const string& s, int start, vector<string>& currentpartition, vector<vector<string>>& result) {

        if (start == s.length()) {
            result.push_back(currentpartition);
            return;
        }


        for (int end = start; end < s.length(); ++end) {

            if (isPalindrome(s, start, end)) {
                currentpartition.push_back(s.substr(start, end - start + 1));

                backtrack(s, end + 1, currentpartition, result);

                currentpartition.pop_back();
            }
        }
    }


    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};