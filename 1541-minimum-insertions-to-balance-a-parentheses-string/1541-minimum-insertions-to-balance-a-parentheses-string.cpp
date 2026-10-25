class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    insertions++; // insert an ) to match this pair
                }

                if (open > 0) {
                    open--;
                } else {
                    insertions++; // insert an ( to match thi spair
                }
            } 
        }

        return insertions + 2 * open;  // cause for 1 ( we count 2 )), so necessity wise
        
    }
};

//my thought, : lc 1541, i think ive got the gist, for every (, we increment balance with 1, but with every ), we decrement it by 2 or something like that, cause for 1 open it needs to balance with 2 close.,
//chatgpt : we dont decrement the balance by 2 for every ), we track how many closing parenthesis are still needed

//we maintain 2 variables : open and insertions, open : number of openign parenthesis stil waiting for their two closing parenthesis, insertions : number of parenthesis we need to fix the string
//case 1 : see ( - match it with )), open++
//we get ), we need to track the number of close if theyre in odd or even, but we can track them better if open > 0, we have an open to be matched, if open == 0, we need to make an insertion 