<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>K-th Smallest in Lexicographical Order</title>
    <style>
        .colorful-box {
            background-color: lightblue;
            border: 2px solid red;
            padding: 20px;
            width: 100px;
            text-align: center;
            font-size: 20px;
            color: white;
            font-weight: bold;
            border-radius: 10px;
            box-shadow: 3px 3px 8px rgba(0, 0, 0, 0.3);
            margin-bottom: 20px;
        }
    </style>
    <!-- MathJax library -->
    <script src="https://polyfill.io/v3/polyfill.min.js?features=es6"></script>
    <script id="MathJax-script" async src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js"></script>
</head>
<body>
    <div class="colorful-box">hard</div>
    
    <p>Given two integers $$n$$ and $$k$$, return the $$k$$ th lexicographically smallest integer in the range $$[1, n]$$.</p>
    
    <p><b>Example 1:</b></p>
    <p>Input: $$n = 13, k = 2$$</p>
    <p>Output: $$10$$</p>
    <p>Explanation: The lexicographical order is $$[1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]$$, so the second smallest number is $$10$$.</p>

    <p><b>Example 2:</b></p>
    <p>Input: $$n = 1, k = 1$$</p>
    <p>Output: $$1$$</p>

    <p><b>Constraints:</b> $$1 \leq k \leq n \leq 10^9$$</p>
</body>
</html>
