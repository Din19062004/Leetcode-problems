/**
* Notice that: If the total number of 'F' in a substring str[i...j] is smaller than k, we can change all of the characters 'F' into 'T'
* The problem is equivalent when we want to change 'T' into 'F'
* Use two pointers L, R (both initial value are 0). R will run through all the string. If countF > k, increase L until countF <= k
* Update maxLength = R - L + 1. The final result is the maximum value of two cases: change 'T' to 'F' and change 'F' to 'T'
*/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int L1 = 0, R1 = 0, L2 = 0, R2 = 0;
        int maxLength1 = INT_MIN, maxLength2 = INT_MIN, cntF = 0, cntT = 0;

        while(R1 < answerKey.length()) {
            char c = answerKey[R1];
            if(c == 'F') {
                cntF++;
            }
            while(cntF > k) {
                c = answerKey[L1];
                if(c == 'F') {
                    cntF--;
                }
                L1++;
            }
            maxLength1 = max(maxLength1, R1 - L1 + 1);
            R1++;
        }

        while(R2 < answerKey.length()) {
            char m = answerKey[R2];
            if(m == 'T') {
                cntT++;
            }
            while(cntT > k) {
                m = answerKey[L2];
                if(m == 'T') {
                    cntT--;
                }
                L2++;
            }
            maxLength2 = max(maxLength2, R2 - L2 + 1);
            R2++;
        }
        return max(maxLength1, maxLength2);
    }
};
