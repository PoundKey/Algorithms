// Thoughts: End is the explorer, whereas start is the protector.
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isBadVersion(mid)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};