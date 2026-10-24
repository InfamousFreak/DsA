class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  //-1 is sentinel boundary, helps us measure the actual length of the substring in case it starts from index 0

        int maxi = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();

                if (st.empty()){
                    st.push(i);
                }
                 else {
                    maxi = max(maxi, i - st.top());
                 }
            }
        }

        return maxi;
    }
};