class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainFreq(k, 0);
        for(int num : arr) {
            int remain = ((num % k) + k) % k; //Calculate remainder for both positve and negative integers
            remainFreq[remain] ++;
        }
        
        //Case 1: If the number of numbers which are divisible by k is odd, it can't match
        if(remainFreq[0] % 2 != 0) {
            return false;
        }

        //Case 2: If k is even and the number of numbers which is divided by k remaining k/2 is odd, it can't match
        if((k % 2 == 0) && (remainFreq[k/2] % 2 != 0)) {
            return false;
        }

        //Case 3: It will be true if remainFreq[i] == remainFreq[k - i] for i in 1 to k - 1
        for(int i = 1; i < k; i++) {
            if(remainFreq[i] != remainFreq[k - i]) {
                return false;
            }
        }
      
        return true;
    }
};
