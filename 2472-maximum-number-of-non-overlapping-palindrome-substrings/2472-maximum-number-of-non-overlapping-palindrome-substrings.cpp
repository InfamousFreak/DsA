class Solution {
public:

    bool isPalindrome(string s, int l, int r){
        while (l < r){
            if (s[l] != s[r])
                return false;
                
            l++;
            r--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();

        int count = 0;
        int lastended = -1;

        for (int r = k - 1; r < n; r++){
            int l = r - k + 1; //try length k

            if (l > lastended && isPalindrome(s, l, r)){
                count++;
                lastended = r;
                continue;
            }

            l = r - k; //try length k + 1

            if (l >= 0 && l > lastended && isPalindrome(s, l, r)){
                count++;
                lastended = r;
                
            }
        }

        return count;
    }

    


    //find all possible substrings
    //for (int l = 0; l < n; l++){
        //for (int r = l; r < n; r++){
          //  if (r - l + 1 >= k && isPalindrome(s, l, r)){
                //found a valid palindrome
            
        
    
};



//as we cannot seletc overlapping substrings, if l,r is the first substring, the nest substring must start at l >= r + 1
//another thing si we cannot select all the palindromes we find, we need to find the non overlapping ones only, which means we need to keep track of where our last palindrome substring ended, int lastended, 

//but we cannot pick the palindrome that starts first, cause that might block a better or more max ans, so we need to instead select the palindrome that ends first, SAME IDEA AS INTERVAL SCHEDULING
//need to start at the end point right so we encounter the easliest ending palidnrome