class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int sum[n/2];
        sum[0] = skill[0] + skill[n - 1];
        int i = 1, j = n - 2, index = 1;
        long long chem = skill[0] * skill[n - 1];

        //Check if sum of all pairs are equal
        while(i < j) {
            sum[index] = skill[i] + skill[j];
            if(sum[index] != sum[index - 1]) {
                return -1;
            }
            chem += skill[i] * skill[j];
            index++;
            i++;
            j--;
        }
        return chem;
    }
};
