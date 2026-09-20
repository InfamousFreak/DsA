class Solution {
public:
    int reverseDegree(string s) {

        //first initialize ans = 0
        int ans = 0;
        // string traversal 1 indexed
        for (int i = 0; i < s.size(); i++){
            int index = i + 1;
            int rev = 26 - (s[i] - 'a');


            ans += index * rev;
        }

        return ans;
        
    }
};