# Problem 2206. Divide Array Into Equal Pairs
<body>
<p>You are given an integer array nums consisting of $$2n$$ integers.</p>
<p>You need to divide nums into $$n$$ pairs such that:</p>
<p>&nbsp;1. Each element belongs to exactly one pair.</p>
<p>&nbsp;2. The elements present in a pair are equal.</p>
<p>&nbsp;3. Return true if nums can be divided into $$n$$ pairs, otherwise return false.</p> 
<p><b>Example 1:</b></p>
<p>Input: $$nums = [3,2,3,2,2,2]$$</p>
<p>Output: true</p>
<p>Explanation:</p>
<p>&nbsp;- There are $$6$$ elements in nums, so they should be divided into $$6 : 2 = 3$$ pairs.</p>
<p>&nbsp;- If nums is divided into the pairs $$(2, 2), (3, 3), and (2, 2)$$, it will satisfy all the conditions.</p>
<p><b>Example 2:</b></p>
<p>Input: $$nums = [1,2,3,4]$$</p>
<p>Output: false</p>
<p>Explanation: 
There is no way to divide nums into $$4 : 2 = 2$$ pairs such that the pairs satisfy every condition.</p>
<p><b>Constraints:</b>$$nums.length = 2n$$, $$1 \leq n \leq 500$$ and $$1 \leq nums[i] \leq 500$$.</p>
</body>
