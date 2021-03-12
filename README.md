# Assignment-4

**Team Members**
|   Enrollment No.  |   Name   | GithubId |
|   --------------  |   ----   | -------- |
|    IIT2019066  | Naveen Kumar | navmanak |
|    IIT2019067  |   Slok Aks | SlokAks | 
|    IIT2019068  |   Simhachalam Anirudh | anirudh2019  |

**Group No-**"22"

**Faculty Name-**"Dr. Mohammed Javed"

**Mentor Name-** "Md. Meraz"

---
## Problem Statement
Given an array representing n positions along a straight line. Find k (where k <= n) elements from the array such that the minimum distance between any two (consecutive points among the k points) is maximized.

---
## How to use code
Firstly Clone the project into the local machine using command:
```
#Download project
 git clone https://github.com/SlokAks/DAA.git

```
Go to the to the project directory:
```
cd DAA/Assignemt
```
Run the code
```
g++ FinalCode -o FinalCode.c
./a.out

```
Input
```
Number of testcases: 2

N : 9
K : 3

N : 14
K : 6
```
Output
```
arr : -64449 38662 68548 52923 -24042 -27017 97376 34382 -70521
The maximised minimum distance is : 62994
The K(= 3) - elements in which minimum distance between any two consecutive points is maximised are :                                           
-70521 34382 97376
Time : 139

arr: -39843 -95717 -5813 49365 -93684 48953 68251 35788 12838 -14005 -2931 52208 41558 83353                                                    
The maximised minimum distance is : 25838                                                                                                       
The K(= 6) - elements in which minimum distance between any two consecutive points is maximised are :                                           
-95717 -39843 -14005 12838 41558 68251                                                                                                          
Time : 132 
```
---

**Test case**

Find max
```
Test Case-1
Input:
13
5
Out:
arr: 39386 85632 93662 -41621 -40729 11831 45915 63566 -73732 -62103 -91581 -3245 41932
maximised minimum distance is : 38376
-91581 -41621 -3245 39386 85632
#--------------------------#
Test Case-2
Input:
20
9
Out:
arr: -54403 34539 -71936 -14719 99102 -61194 -73519 83509 -59020 -74589 75761 62292 58664 28896 -69299 8115 48738 -41456 -59110 -72628
maximised minimum distance is : 15569
-74589 -59020 -41456 -14719 8115 28896 48738 75761 99102
```

---

### Theory
To find the k elements (where k<=n), from the array such that the minimum distance between any two (consecutive points among the k points) is maximized, we implement the following steps in our algorithm :
1.  Sort the input array.

2.  Set lower = 1, which is the lowest possible distance, and set upper = arr[n-1] - arr[0], which is the maximum possible distance.
3.  Now, we apply binary search over lower to upper.

•Check  isFeasible()  for  the  mid  until lower < upper, i.e; if it is possible to select  ‘k’  elements  using  the  mid  as minimum distance.
If  feasible,  then  check  for  higher  distance  next,  i.e;  more  than  mid  and upto upper.
Else, check for lower distance next, i.e; less than mid and from lower

4.  So, we get the required distance.

5.  Now, we apply a modified version of isFeasible(), named printElem() to get the final ‘k’ selected elements with the maximum minimum distance, which was required.

---

### Analysis

**Time Complexity**

In the above algorithm, the time complexity of isFeasible() function is O(N) as in the worst case, the for loop will have N - 1 iterations. In the function maximised_min_dist(), the while loop iterates until “lower” becomes equal to “upper”.

When lower becomes equal to upper, then D/2^m = 1, where m is number of iterations and D is maximum possible distance between any two points among N points
                                                            => D = 2^m
                                                            => m = logD
But in each iteration of that while loop, isFeasible() function is called once, and also there is sort function before while loop in maximised_min_dist() whose time complexity is O(NlogN). 
Therefore Overall time complexity is O(N*logN + N*logD)
                                                            => **O(N*log(N*D)) **

**Space Complexity**

In the above algorithm, only one array of size N is used to store input array and some integer variables are used. So, the Overall space complexity is **O(N).**

---

### References

[1] GeeksforGeeks, 'Introduction to Arrays', GeeksforGeeks, 2018. [Online]. [Accessed: 5-Mar-2021] 
[2] GeeksforGeeks, 'Place k elements such that minimum distance is maximized)', GeeksforGeeks, 2018. [Online]. [Accessed: 5-Feb-2021]
[3] GeeksforGeeks, 'Sorting Algorithm', GeeksforGeeks, 2018. [Online]. [Accessed: 5-Mar-2021]

