class Solution {
public:
    struct NumWithRank {
        int num, rank, index;
    };

    static bool compareNum(const NumWithRank &a, const NumWithRank &b) {
        return a.num < b.num;
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<NumWithRank> NR(arr.size());
        for(int i = 0; i < arr.size(); i++) {
            NR[i].num = arr[i];
            NR[i].rank = 1;
            NR[i].index = i;
        }
        sort(NR.begin(), NR.end(), compareNum);

        for(int i = 1; i < arr.size(); i++) {
            if(NR[i - 1].num < NR[i].num) {
                NR[i].rank = NR[i - 1].rank + 1;
            }
            else if(NR[i - 1].num == NR[i].num) {
                NR[i].rank = NR[i - 1].rank;
            }
        }

        vector<int> returnArr(arr.size());
        for(int i = 0; i < arr.size(); i++) {
            returnArr[NR[i].index] = NR[i].rank;
        }
        return returnArr;
    }
};
