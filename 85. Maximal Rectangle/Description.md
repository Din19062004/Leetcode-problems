# Problem 85. Maximal Rectangle

Given a ```rows x cols``` binary ```matrix``` filled with ```0```'s and ```1```'s, find the largest rectangle containing only ```1```'s and return its _area_.

__Example 1:__

Input: ```matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]```

Output: ```6```

Explanation: The maximal rectangle is shown in the below picture.

![Example](https://imgur.com/5KxreZ3.png)

__Example 2:__

Input: ```matrix = [["0"]]```

Output: ```0```

__Example 3:__

Input: ```matrix = [["1"]]```

Output: ```1```
 
__Constraints:__
- ```rows == matrix.length```
- ```cols == matrix[i].length```
- ```1 <= row, cols <= 200```
- ```matrix[i][j]``` is ```'0'``` or ```'1'```.
