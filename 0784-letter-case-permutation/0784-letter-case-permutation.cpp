class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;

        backtrack(s, 0, result);

        return result;        
    }

private:
    void backtrack(string& s, int index, vector<string>& result) {


        //first we proess the entire string, 
        if (index == s.length()) {
            result.push_back(s);
            return;
        }


        //if what we have is a letter
        if (isalpha(s[index])) {


            s[index] = tolower(s[index]);
            backtrack(s, index + 1, result);


            s[index] = toupper(s[index]);
            backtrack(s, index + 1, result);
        } else {
            backtrack(s, index + 1, result);
        }
    }
};