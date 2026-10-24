class Solution {
public:
    vector<string> ans;

    void dfs(string s, int start, int last, char open, char close) {
        int balance = 0;

        for (int i = start; i < s.size(); i++) {
            if (s[i] == open) balance++;
            if (s[i] == close) balance--;

            if (balance >= 0) continue;


            for (int j = last; j <= i; j++) {
                if (s[j] == close && (j == last || s[j - 1] != close)) {

                    string next = s.substr(0, j) + s.substr(j+1);

                    dfs(next, i, j, open, close);
                }
            }

            return;
        }

        reverse(s.begin(), s.end());

        if (open == '(') {
            dfs(s, 0, 0, ')', '(');
        } else {
            ans.push_back(s);
        }
    }


    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        dfs(s, 0, 0, '(', ')');
        return ans;
    }
};