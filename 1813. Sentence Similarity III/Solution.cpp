class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        //Split each word of two senteces
        vector<string> s1 = splitWord(sentence1);
        vector<string> s2 = splitWord(sentence2);

        //Always assume that s1.size() < s2.size() (sentence1 is shoter than sentence2)
        if(s2.size() < s1.size()) {
            swap(s1, s2);
        }

        //Use two pointers: l points to the head of the list, r points to the tail of the list
        int l1 = 0, l2 = 0;
        int r1 = s1.size() - 1, r2 = s2.size() - 1;
        while(l1 < s1.size() && l2 < s2.size() && s1[l1] == s2[l2]) {
            l1++;
            l2++;
        }
        while(r1 >= 0 && r2 >= 0 && s1[r1] == s2[r2]) {
            r1--;
            r2--;
        }
        return l1 > r1;
    }
private:
    vector<string> splitWord(string line) {
        vector<string> word;
        stringstream ss(line);
        string w;
        while(ss >> w) {
            word.push_back(w);
        }
        return word;
    }
};
