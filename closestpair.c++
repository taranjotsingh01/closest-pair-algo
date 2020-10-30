#include <bits/stdc++.h> 
using namespace std; 

//structure to store x and y coordinate of points
struct Point 
{ 
	int x, y; 
}; 


//A utility function to sort values according to X coordinate
int compareX(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->x - p2->x); 
} 

//A utility function to sort values according to Y coordinate
int compareY(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->y - p2->y); 
} 


// Function to calculate dist between two points
float dist(Point p1, Point p2) 
{ 
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
				(p1.y - p2.y)*(p1.y - p2.y) 
			); 
} 


float bruteForce(Point P[], int n) 
{ 
	float min = FLT_MAX; 
	for (int i = 0; i < n; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j]) < min) 
				min = dist(P[i], P[j]); 
	return min; 
} 


float min(float x, float y) 
{ 
	return (x < y)? x : y; 
} 


// A utility function to find the distance between the closest points of 
// strip of a given size. All points in strip[] are sorted according to 
// y coordinate. They all have an upper bound on minimum distance as d. 
float stripClosest(Point strip[], int size, float d) 
{ 
	float min = d; 
	for (int i = 0; i < size; ++i) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
			if (dist(strip[i],strip[j]) < min) 
				min = dist(strip[i], strip[j]); 

	return min; 
} 

// Recursive function to calculate  minimum distance
float closestUtil(Point Px[], Point Py[], int n) 
{ 
	// If there are 2 or 3 points, then use brute force 
	if (n <= 3) 
		return bruteForce(Px, n); 

	// Find the middle point 
	int mid = n/2; 
	Point midPoint = Px[mid]; 


	Point Pyl[mid];  
	Point Pyr[n-mid];  
	int li = 0, ri = 0;
	for (int i = 0; i < n; i++) 
	{ 
	if (Py[i].x <= midPoint.x && li<mid) 
		Pyl[li++] = Py[i]; 
	else
		Pyr[ri++] = Py[i]; 
	} 

	// Consider the vertical line passing through the middle point 
	float dl = closestUtil(Px, Pyl, mid); 
	float dr = closestUtil(Px + mid, Pyr, n-mid); 

	float d = min(dl, dr); 

	// Build an array strip[] that contains points close (closer than d) 
	// to the line passing through the middle point 
	Point strip[n]; 
	int j = 0; 
	for (int i = 0; i < n; i++) 
		if (abs(Py[i].x - midPoint.x) < d) 
			strip[j] = Py[i], j++; 

	return stripClosest(strip, j, d); 
} 


float closest(Point P[], int n) 
{ 
	Point Px[n]; 
	Point Py[n]; 
	for (int i = 0; i < n; i++) 
	{ 
		Px[i] = P[i]; 
		Py[i] = P[i]; 
	} 

	qsort(Px, n, sizeof(Point), compareX); 
	qsort(Py, n, sizeof(Point), compareY); 

	return closestUtil(Px, Py, n); 
} 

int main() 
{ 
	Point P[100]; 
	int n = 100;
	for(int i=0;i<n;i++)
	{
		P[i].x=rand();
		P[i].y=rand();
	} 
	cout << "The smallest distance is " << closest(P, n); 
	return 0; 
}  
