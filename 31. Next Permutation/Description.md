# Problem 31. Next Permutation

A __permutation__ of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for ```arr = [1, 2, 3]```, the following are all the permutations of ```arr```: ```[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]```.

The __next permutation__ of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the __next permutation__ of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

🥇 For example, the next permutation of ```[1, 2, 3]``` is ```[1, 3, 2]```.

🥈 Similarly, the next permutation of ```[2, 3, 1]``` is ```[3, 1, 2]```.

🥉 While the next permutation of ```[3, 2, 1]``` is ```[1, 2, 3]``` because ```[3, 2, 1]``` does not have a lexicographical larger rearrangement.

Given an array of integers ```nums```, _find the next permutation of_ ```nums```.

The replacement must be __in place__ and use only constant extra memory.

__Example 1:__

➡️ Input: nums = [1, 2, 3]

➡️ Output: [1, 3, 2]

__Example 2:__

➡️ Input: nums = [3, 2, 1]

➡️ Output: [1, 2, 3]

__Example 3:__

➡️ Input: nums = [1, 1, 5]

➡️ Output: [1, 5, 1]
 
__Constraints:__
- ```1 <= nums.length <= 100```
- ```0 <= nums[i] <= 100```
