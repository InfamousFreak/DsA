class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestx = max(x1, min(xCenter, x2));
        int closesty = max(y1, min(yCenter, y2));

        int dx = xCenter - closestx;
        int dy = yCenter - closesty;

        return dx*dx + dy*dy <= radius*radius;
        
    }
};

//cleanest path is, find the closest point on the rectangle to the center of the circle, then check whether that point is within the circle radius, 

//a circle overlaps the recatnagle if some point of the rectangle is at distance <= r from the circle's center
//the question becomes, "What is the cloest point of the rectangle to (xcenter, ycenter)"

//closestx = max(left, min(xcenter, right))
//closesty = max(bottom, min(ycenter, top))

//clamp = if the point is inside the range, keep it, if it is outside the range, the max of the range is the point

//then just pythagoras, dx = xcenter - closestx, dy = ycenter - closesty

//dx*dx + dy*dy <= r*r, then the circle touches/ overlaps the rectangle

