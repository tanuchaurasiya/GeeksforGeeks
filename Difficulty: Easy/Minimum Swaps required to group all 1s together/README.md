<h2><a href="https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Minimum Swaps required to group all 1s together</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of 0s and 1s, we need to write a program to find the minimum number of swaps required to group all 1s present in the array together.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[ ] = {1, 0, 1, 0, 1}
<strong>Output :</strong> 1
<strong>Explanation:</strong>
Only 1 swap is required to group all 1's together. 
Swapping index 1 and 4 will give arr[] = {1, 1, 1, 0, 0}.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[ ] = {1, 0, 1, 0, 1, 1} <strong>
Output :</strong>  1</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>minSwaps()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(n)</strong>&nbsp;and return the minimum number of swaps required and if no 1's are present print <strong>-1</strong>. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N&nbsp; ≤ 10<sup>5</sup><br>
0 ≤ Arr<sub>i</sub> ≤ 1</span></p>
</div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;