# Problem 539. Minumum Time Difference
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 
<b>Example 1:</b> <br>
Input: timePoints = ["23:59","00:00"]<br>
Output: 1<br>
Explanation: The minumum time difference between 23:59pm and 00:00am is 1 minute.

<b>Example 2:</b> <br>
Input: timePoints = ["00:00","23:59","00:00"]<br>
Output: 0<br>
Explanation: The minumum time difference between 00:00am and 00:00am is 0.

<b>Constraints:</b> <br>
2 <= timePoints.length <= 2 * 10^4<br>
timePoints[i] is in the format "HH:MM".
