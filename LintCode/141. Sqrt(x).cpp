class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if (x <= 1) return x;
        int start = 0, end = x;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int res = x / mid;
            if (res == mid) {
                return mid;
            } else if (res > mid) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }
};
