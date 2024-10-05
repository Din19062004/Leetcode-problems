class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //Edge case: s1 is longer than s2
        if(s1.length() > s2.length()) {
            return false;
        }

        //s1Count: to count the frequency of each character in s1
        //s2Window: to count the frequency of each character in a sub string (which has the same length as s1) of s2.
        vector<int> s1Count(26, 0), s2Window(26, 0);
      
        for(int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Window[s2[i] - 'a']++; //The first window of s2
        }

        for(int i = s1.length(); i < s2.length(); i++) {
            //Compare the frequency of each character in s1 with all the windows of s2
            if(s1Count == s2Window) {
                return true;
            }
            
            //Slide the window of s2
            s2Window[s2[i] - 'a']++;
            s2Window[s2[i - s1.length()] - 'a']--;
        }
      
        //Compare the frequency of each character in s1 with the last window of s2
        return s1Count == s2Window;
    }
};
