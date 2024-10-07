# Problem 539. Minimum Time Difference

Given a list of 24-hour clock ```time points``` in ```"HH:MM"``` format, return the _minimum minutes difference_ between any two time-points in the list.
 
__Example 1:__

🥇 Input: timePoints = ["23:59","00:00"]

🥈 Output: 1

Explanation: The minimum time difference between 23:59pm and 00:00am is 1 minute.

__Example 2:__

🥇 Input: timePoints = ["00:00","23:59","00:00"]

🥈 Output: 0

Explanation: The minimum time difference between 00:00am and 00:00am is 0.

__Constraints:__
- ```2 <= timePoints.length <= 2*10⁴```
- ```timePoints[i]``` is in the format ```"HH:MM"```.
