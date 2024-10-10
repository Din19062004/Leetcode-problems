# Problem 1493. Longest Subarray of 1's After Deleting One Element

Given a binary array ```nums```, you should delete one element from it.

Return the _size of the longest non-empty subarray containing only ```1```'s in the resulting array_. Return ```0``` if there is no such subarray.

__Example 1:__
- Input: nums = [1, 1, 0, 1]
- Output: 3
- Explanation: After deleting the number in position 2, [1, 1, 1] contains 3 numbers with value of 1's.

__Example 2:__
- Input: nums = [0, 1, 1, 1, 0, 1, 1, 0, 1]
- Output: 5
- Explanation: After deleting the number in position 4, [0, 1, 1, 1, 1, 1, 0, 1] longest subarray with value of 1's is [1, 1, 1, 1, 1].
  
__Example 3:__
- Input: nums = [1, 1, 1]
- Output: 2
- Explanation: You must delete one element.
 
__Constraints:__
- ```1 <= nums.length <= 10⁵```
- ```nums[i]``` is either ```0``` or ```1```.
