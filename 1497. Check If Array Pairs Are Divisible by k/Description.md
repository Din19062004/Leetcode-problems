# Problem 1497. Check If Array Pairs Are Divisible by k

Given an array of integers ```arr``` of even length ```n``` and an integer ```k```.

We want to divide the array into exactly ```n / 2``` pairs such that the sum of each pair is divisible by ```k```.

Return ```true``` if you can find a way to do that or ```false``` otherwise.

__Example 1:__

Input: ```arr = [1, 2, 3, 4, 5, 10, 6, 7, 8, 9]```, ```k = 5```

Output: ```true```

Explanation: Pairs are ```(1, 9), (2, 8), (3, 7), (4, 6) and (5, 10)```.

__Example 2:__

Input: ```arr = [1, 2, 3, 4, 5, 6]```, ```k = 7```

Output: ```true```

Explanation: Pairs are ```(1, 6), (2, 5) and (3, 4)```.

__Example 3:__

Input: ```arr = [1, 2, 3, 4, 5, 6]```, ```k = 10```

Output: ```false```

Explanation: You can try all possible pairs to see that there is no way to divide arr into ```3``` pairs each with sum divisible by ```10```.
 

__Constraints:__
- ```arr.length = n```
- ```1 <= n <= 10⁵```
- ```n is even.```
- ```-10⁹ <= arr[i] <= 10⁹```
- ```1 <= k <= 10⁵```
