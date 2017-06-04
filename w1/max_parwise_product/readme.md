# Problem Description

#### Problem

Given a sequence of non-negative integers a0,…,an−1, find the maximum pairwise product, that is, the largest integer that can be obtained by multiplying two different elements from the sequence (or, more formally, max(0≤i≠j≤n−1) ai aj). Different elements here mean ai and aj with i≠j (it can be the case that ai=aj).


#### Input format

The first line of the input contains an integer n. The next line contains n non-negative integers a0,…,an−1 (separated by spaces).


**Constraints**

2≤n≤2⋅105; 0≤a0,…,an−1≤10^5.


**Output format**

Output a single number — the maximum pairwise product.



## Stress testing

First test for  the possible cases:
* smallest input
* biggest input
* answer doestn't exist
* check time and memory consumption

A stress testing consists of four parts:
1. The solution you want to test.
2. A different, possibly trivial and slow, but easy to implement and obviously correct solution to the problem.
3. A test generator.
4. An infinite loop in which a new test is generated, it is fed into both solutions, then the results are compared, and if they differ, the test and both answers are Output, and the program stops, otherwise the loop repeats.


The idea behind stress testing is that if you have two correct solutions, and the answer to the problem is unique, then for any possible test case they are guaranteed to give the same answer. If, however, at least one of the solutions is incorrect, then with very high probability there exists a test on which their answers differ. The only case when it is not so is when there is a common mistake in both solutions, but that is very unlikely (unless the mistake is somewhere in the input/output routines which are common to both solutions - check for that separately). Indeed, if one solution is correct and the other is wrong, then there obviously exists a test case on which they differ. If both are wrong, but the bugs are different, then most probably there exists a test on which one solution gives a correct answer and another gives wrong answer, so they differ.
