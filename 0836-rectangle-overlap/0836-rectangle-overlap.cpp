class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
            //rec1 completely 
        if (rec1[2] <= rec2[0] || //left
            rec2[2] <= rec1[0] || //right
            rec1[3] <= rec2[1] || //above
            rec2[3] <= rec1[1]) {  //below rec2
                return false;
            }


            return true;
        
    }
};