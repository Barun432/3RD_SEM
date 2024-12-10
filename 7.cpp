class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int whiteCount = 0, blackCount = 0;
        for (char c : s) {
            if (c == '0') {
                whiteCount++;
            } else {
                blackCount++;
            }
        }
        if (string(whiteCount - blackCount) > 1) {
            return -1;
        }
        int whiteLeft = 0, blackRight = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                whiteLeft++;
            } else {
                blackRight++;
            }
        }
        if (whiteCount == blackCount) {
            return min(whiteLeft, blackRight);
        } else if (whiteCount > blackCount) {
            return whiteLeft;
        } else {
            return blackRight;
        }
    }
};