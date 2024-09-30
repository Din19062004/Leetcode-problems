# Problem 1381. Design a Stack With Increment Operation
<body>
<p>Design a stack that supports increment operations on its elements.</p>
<p>Implement the CustomStack class:</p>
<p>&nbsp;&nbsp;1. CustomStack(int maxSize): Initializes the object with maxSize which is the maximum number of elements in the stack.</p>
<p>&nbsp;&nbsp;2. void push(int x): Adds x to the top of the stack if the stack has not reached the maxSize.</p>
<p>&nbsp;&nbsp;3. int pop(): Pops and returns the top of the stack or -1 if the stack is empty.</p>
<p>&nbsp;&nbsp;4. void inc(int k, int val): Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.</p>

<p><b>Example 1:</b></p>
<p><b>Input:</b></p>
<p>["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]</p>
<p><b>Output:</b></p>
<p>[null,null,null,2,null,null,null,null,null,103,202,201,-1]</p>
<p><b>Explanation:</b></p>
</body>
| Operation                                   | Stack State           |
|---------------------------------------------|-----------------------|
| CustomStack stk = new CustomStack(3);      | []                    |
| stk.push(1);                                | [1]                  |
| stk.push(2);                                | [1, 2]               |
| stk.pop();                                  | [1]                  |
| stk.push(2);                                | [1, 2]               |
| stk.push(3);                                | [1, 2, 3]            |
| stk.push(4);                                | [1, 2, 3]            |
| stk.increment(5, 100);                      | [101, 102, 103]      |
| stk.increment(2, 100);                      | [201, 202, 103]      |
| stk.pop();                                  | [201, 202]           |
| stk.pop();                                  | [201]                |
| stk.pop();                                  | []                    |
| stk.pop();                                  | -1                    |

