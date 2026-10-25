class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int balance = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (balance > 0) {
                    ans += s[i];
                }
                balance++;
            } else {
                balance--;
                if (balance > 0) {
                    ans += s[i];
                }
            }
        }

        return ans;
    }
};

//no need of stack, countign of open and close parentheses and balance is enough, we're decomposing the tsring intoprimitive vad parethesis, not necessarily just two strings, so we need to validate them too, 
//it goes like, the partition is where the balance is 0, and we ahve to account for all those when baalnce is 0 and just recently 1, 