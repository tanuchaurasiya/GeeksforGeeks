<h2><a href="https://www.geeksforgeeks.org/problems/design-a-tiny-url-or-url-shortener2031/1">Design a tiny URL or URL shortener</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Design a system that takes big URLs like “<strong>http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/</strong>” and converts them into a short<strong>&nbsp;URL</strong>. It is given that URLs are stored in the database and every URL has an associated integer <strong>ID</strong>.&nbsp; So your program should take an integer ID and generate a URL.&nbsp; </span></p>
<p><span style="font-size: 18px;"><strong>Note</strong>: A URL character can be one of the following</span></p>
<ol>
<li><span style="font-size: 18px;">A lowercase alphabet [‘a’ to ‘z’], total 26 characters</span></li>
<li><span style="font-size: 18px;">An upper case alphabet [‘A’ to ‘Z’], a total of 26 characters</span></li>
<li><span style="font-size: 18px;">A digit [‘0′ to ‘9’], a total of 10 characters</span></li>
</ol>
<p><span style="font-size: 18px;">There are total of 26 + 26 + 10 = 62 possible characters.</span></p>
<p><span style="font-size: 18px;">So the task is to convert an integer ID to a short URL and convert a short URL back to the integer ID.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 12345
<strong>Output:</strong> 
dnh
12345
<strong>Explanation:</strong> "dnh" is the url for id 12345</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 30540
<strong>Output:</strong> 
h6K
30540
<strong>Explanation:</strong> "h6K" is the url for id 30540</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(log<sub>62</sub><sup>n</sup>)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>15</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<code>Hike</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Strings</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Hash</code>&nbsp;