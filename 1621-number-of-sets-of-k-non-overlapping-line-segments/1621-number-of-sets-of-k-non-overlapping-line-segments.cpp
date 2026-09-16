class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<long long> outside(k + 1, 0);
        vector<long long> inside(k + 1, 0);

        outside[0] = 1;

        for (int i = 0; i < n; i++){
            vector<long long> newoutside(k+1, 0);
            vector<long long> newinside(k+1, 0);

            for (int j = 0; j <= k; j++){
                newoutside[j] += outside[j]; //stay outside, dont start/end anythign at this point

                newinside[j] += outside[j]; //start a new segment


                newinside[j] += inside[j]; //continue the current segment

                if (j > 0){ //end the current segment

                    newoutside[j] += inside[j - 1];

                    newinside[j] += inside[j - 1];
                }

                newoutside[j] %= MOD;
                newinside[j] %= MOD;
            }

            outside = newoutside;
            inside = newinside;
        }


        return outside[k];
        
    }
};


//potentially many ways to choose the endpoints, like if we're currenlty at point i, a segment can end at any later point, so much more naturally DP = number of ways, rather than DP = maximum number, ironially unsimilar to non overlapping subsetrings

//imagine choosign segments from left to right, dp[i][j], number of ways to choose j non overlappign segments using points up to i 

//were nto simply asking, "Can I take this segment?", How many ways can I arrange k segments?, thats why dp is going to be about counting ways


//we have to measure two states at every point, 1. we are not currently inside a segment, 2. we are currently inside a segment

//state 1. outside a segment, havent started a segment or finished one, state 2 is we've started a segment, but havent chosen its ending point, dp[i][j][0], dp[i][j][1]

//j = number of segments weve completed/started depending on the state, but cleanly, J = number of segments weve started, meaning dp[i][j][0] means weve satrted j segments and currently outside a segment, and dp[i][j][1], weve started j egments and currently isndie one

//supose were outside, we can either stay outside, or go inside a segment, and if were inside a segment, we can either stay inside or go outside, this is where counting of j becomes important

//at one endpoitn special case, we may end a segment and start another segment at the same point
//we increment j when we end a segment

//meaning, if were outside a segment, j can not imcrement, inside outside dp