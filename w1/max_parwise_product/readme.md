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

## Further advice

This illustrates the stress testing technique, but let us give you some additional advice.

First, you noticed that the stress test "magically" gave us the test on which our solutions differ from the first attempt. This is not always like that. For example, we know that in this problem our initial solutions differed only in the case when the two maximal numbers in the input were the same. This is a pretty rare case if we generate lots of big numbers. So, we were lucky to find such a case when we generated numbers from 0 to 99999. If we started with generating numbers from a smaller range, we would find the test like that much faster, because number would coincide much more often.

This is true also in the general case: when you do stress testing, often the case with equal numbers or equal letters in a string, etc. is a kind of corner case. To ensure that your stress test finds that fast enough for you to notice, you should try to not only generate just some random test cases, but also try to generate some more "focused" random test cases, such as those with only small numbers or a small range of big numbers, only strings which consist of only letter "a" or only of two different letters (as opposed to strings composed of all possible lowercase latin letters), and so on. Think about other subspaces of possible tests which could be peculiar in some sense. For example, if you are generating graphs, try generating trees, disconnected graphs, full graphs, bipartite graphs. If you generate trees, try generating chains, balanced binary trees, "stars" - trees with a root and many direct children. If you are generating integer numbers, try generating prime and composite numbers. If you are generating sets of points, try generating them on one line and on one circle, etc.

Another important point is to try generating the smallest possible test case for which one of the solutions fails: it will simplify debugging a lot.

Don't expect stress testing to be the silver bullet. For example, it won't detect the problems your solution has with time limit or memory limit, because you will generate smaller tests because of the second, "trivial" solution, which would run too slow on those. Also, you probably won't detect the integer overflow problems, because you'll generate only small numbers, or because you'll have integer overflow problems in both solutions. You should really first test for all of those separately, before implementing a stress test.

However, if you've tried all of those tests listed in the beginning, stress test should be your next move. It is almost guaranteed to find you the test case on which your solution fails, especially if you try generating tests cleverly, in different subspaces of the test space, trying to make equal numbers or equal letters more likely, and trying to make other rare cases appear more often in the generated tests. The reason is that when the authors of the problems generate test suites, they follow more or less the same process. They add manual tests, corner case tests, big tests, integer overflow tests, and then they implement a few test generators and add them. They also implement wrong solutions which are expected from the learners and run the generators until they find the tests on which they differ from the correct solution, then they add those tests to the suite. So, if you follow the same process, although it is somewhat randomized, you are very likely to find all the traps they've set up for you :)

## Conclusion

Note that it is very important to learn to write programs that work correctly on all the tests which are allowed by the problem statement, and not just on most of them. In practice, doing otherwise leads to bugs in the services, and when users encounter your bugs, their experience deteriorates significantly. When you make mistakes that only rarely reveal themselves, those can affect the whole project: you will get some results of testing your hypotheses and will believe in them for a long time, base your decisions on that belief, only to learn later that the code had a bug in it. That is why we've prepared thorough test suites for all the problems that will try to check all the possible aspects where your solution might fail. And that is where stress testing will be so helpful - when you're stuck with a problem and don't even know what is the test case on which it fails. We hide it for purpose, so that you learn to find this test case yourself: in the real life very often you won't know what are the exact conditions under which your program fails.


Key points:

* It is very important to write programs that work correctly on all the allowed inputs.
* Testing is essential to writing correct programs.
* First test on a few small manual tests, then test for each type of answer, then test on large test cases for time limit and memory limit, then test on corner cases.
* After that, apply stress testing to ensure your program works - it will almost always lead to correct solution. You can do it before your first attempt to submit your solution - and will often get it right from the first attempt!
* Stress testing consists of implementing the intended solution, another simple possible slow solution, a test generator and an infinite loop which generates tests and compares answers of the two solutions.
* Always try to find the smallest test cases on which your solution fails.
* Try different regions of the test space when generating cases for stress testing.
