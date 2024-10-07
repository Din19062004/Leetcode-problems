/**
* size_t find(const string &str, size_t pos): 
*** para in [str]: find str in the original string
*** para in [pos]: position in the original string to start searching
*** para out: If str is found, return the index to the first occurence, else return string::npos
* string erase(size_t pos, size_t len)
*** para in [pos]: the position from where deletion starts
*** para in [len]: the number of characters to be deleted starting from pos
*** para out: the string after deleting (len) characters from string[pos]
*/

class Solution {
public:
    int minLength(string s) {
        size_t found = 0;
        while((found = s.find("AB")) != string::npos || (found = s.find("CD")) != string::npos) {
            s.erase(found, 2);
        }
        return s.length();
    }
};
