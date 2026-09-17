class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF); //best[i] → shortest target-sum subarray found in arr[0...i]

        int left = 0; //left end of slidign window
        int sum = 0; //current window sum
        int ans = INF; //minimum combined lnegth of two non overlapping subarrays

        for (int right = 0; right  < n; right++){
            sum += arr[right];

            while (sum > target){
                sum -= arr[left];
                left++;
            }

            if (sum == target){
                int len = right - left + 1;

                if (left > 0 && best[left - 1] != INF){
                    ans = min(ans, len + best[left - 1]);
                }

                best[right] = len;
            }

            if (right > 0){
                best[right] = min(best[right], best[right - 1]);
            }
        }
        return ans == INF ? -1 : ans;   
    }
};

//we need ti find 2 subarrays such that, each subarray has a sum = target, they dont overlap, their sum is minimum, 
// first we need to find the subarray whos sum is target , we need sliding window, BUT , they might overlap, so what we actually need to search is "What is the shortest target sum subarray that I have already seen before this current subarray starts"
//best[i] means shortest target sum subarray foud anywhere from index 0 to index i, 

// for sliding window, we first move till we reach target sum, after then we only move right, if the sum is larger than target sum then only we mmove left

//the dp part, 2 comparisons, best[right] = min(best[right], best[right - 1])
//whats the shortest subarray weve seen so far

//ans = min(ans, best[left - 1] + len)
//whats the shortest pair of non overlapping target subarrays ive found

