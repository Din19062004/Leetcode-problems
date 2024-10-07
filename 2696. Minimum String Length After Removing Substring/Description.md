# Problem 2696. Minimum String Length After Removing Substring

You are given a string ```s``` consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings ```"AB"``` or ```"CD"``` from ```s```.

Return the _minimum possible length of the resulting string_ that you can obtain.

__Note__ that the string concatenates after removing the substring and could produce new ```"AB"``` or ```"CD"``` substrings.

__Example 1:__

🥇Input s = "ABFCACDB"

🥈Output: 2

Explanation: We can do the following operations:
- Remove the substring "AB" from "ABFCACDB", so s = "FCACDB".
- Remove the substring "CD" from "FCACDB", so s = "FCAB".
- Remove the substring "AB" from "FCAB", so s = "FC".
- So the resulting length of the string is 2. It can be shown that it is the minimum length that we can obtain.

__Example 2:__

🥇Input: s = "ACBBD"

🥈Output: 5

Explanation: We cannot do any operations on the string so the length remains the same.
 
__Constraints:__
- ```1 <= s.length <= 100```
- ```s``` consists only of uppercase English letters.
