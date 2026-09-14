class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for (int n : nums1) {
            if (n % 2 == 0) {
                minEven = min(minEven, n);
            } else {
                minOdd = min(minOdd, n);
            }
        }


        if (minOdd == INT_MAX || minEven == INT_MAX) {
            return true;
        }

        return minEven >= minOdd;
    }
};