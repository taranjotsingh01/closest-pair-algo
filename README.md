# closest-pair-algo

## Strategy used to solve this problem is divide and conquer.
This Documentation refers to the thinking process and solution to the problem Closer Pair of Points.
Looking at the problem statement, we need to generate 100 pairs of random numbers and have to find the closet pair(distance) of points.

Idea to solve the problem:
1) We sort all points according to x coordinates.

2) Divide all points in two halves.

3) Recursively find the smallest distances in both subarrays.

4) Take the minimum of two smallest distances. Let the minimum be d.

5) Create an array strip[] that stores all points which are at most d distance away from the middle line dividing the two sets.

6) Find the smallest distance in strip[].

7) Return the minimum of d and the smallest distance calculated in above step 6.

To maintain O(NlogN) complexity:
The idea is to presort all points according to y coordinates. Let the sorted array be Py[]. When we make recursive calls, we need to divide points of Py[] also according to the vertical line. We can do that by simply processing every point and comparing its x coordinate with x coordinate of the middle line.
