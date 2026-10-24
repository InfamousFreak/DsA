class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(0);
            }
            else {
                int inner = st.top();
                st.pop();

                int score = max(2 * inner, 1);
                st.top() += score;
            }
        }

        return st.top();

    }
};