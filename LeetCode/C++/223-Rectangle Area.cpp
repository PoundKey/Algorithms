// Thoughts: Consider two cases that the rectangles don't overlap:
// 1. the top most horizontal line is smaller than or equal to the bottom most horizontal line of the other rectangle.
// 2. the top right vertical line is smaller than or equak to the left most vertical line of the other reactangle.
// if overlapped, how do we calculate the overlapping region? same idea, but this time compare the same side from two reactangles.

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int A1 = (C - A) * (D - B);
        int A2 = (G - E) * (H - F);
        if(C <= E || G <= A || D <= F || H <= B) return A1 + A2;
        
        int w =  (A <= E) ? min(C-E, G-E) : min(C-A, G-A);
        int h = (B >= F) ? min(D-B, H-B) : min(D-F, H-F);
        return A1 + A2 - w * h;
    }
};