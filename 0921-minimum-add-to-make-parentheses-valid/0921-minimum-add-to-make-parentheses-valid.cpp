class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0; //closing brackets required for opening brackdets
        int add = 0;    // incrementing opening bracs for closed ones with no open

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                if (open > 0) {
                    open--;
                } else {
                    add++;
                }
            }
        }

        return add + open;


        
    }
};