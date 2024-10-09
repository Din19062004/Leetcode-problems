# Problem 20. Valid Parentheses

Given a string ```s``` containing just the characters ```'('```, ```')'```, ```'{'```, ```'}'```, ```'['``` and ```']'```, determine if the input string is valid.

An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.
 
__Example 1:__

➡️ Input: s = "()"

➡️ Output: true

__Example 2:__

➡️ Input: s = "()[]{}"

➡️ Output: true

__Example 3:__

➡️ Input: s = "(]"

➡️ Output: false

__Example 4:__

➡️ Input: s = "([])"

➡️ Output: true
 
__Constraints:__
- ```1 <= s.length <= 10⁴```
- ```s``` consists of parentheses only ```'()[]{}'```.
