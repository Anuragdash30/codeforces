// C++ program to count inversions of size three using 
// Binary Indexed Tree 
#include<bits/stdc++.h> 
#include <stdio.h>
#include <map>
#include <algorithm>
#include <memory.h>
using namespace std; 
int const N = 1e6 + 1;
int arr[N];
int temp[N]; 
long long greater1[N], smaller1[N]; 
int BIT[4*N+1]; 
map<int, int> mp;
// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[]. 
long long getSum(int BITree[], int index) 
{ 	int sum = 0; // Initialize result 

	// Traverse ancestors of BITree[index] 
	while (index > 0) 
	{ 	
		
		// Add current element of BITree to sum 
		sum += BITree[index]; 

		// Move index to parent node in getSum View 
		index -= index & (-index); 
	} 
	return sum; 
} 

// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
	// Traverse all ancestors and add 'val' 
	while (index <= n) 
	{ 
	// Add 'val' to current node of BI Tree 
	BITree[index] += val; 

	// Update index to that of parent in update View 
	index += index & (-index); 
	} 
} 

// Converts an array to an array with values from 1 to n 
// and relative order of smaller and greater elements remains 
// same. For example, {7, -90, 100, 1} is converted to 
// {3, 1, 4 ,2 } 

// Returns count of inversions of size three 
long long getInvCount(int arr[], int n) 
{ 
	// Convert arr[] to an array with values from 1 to n and 
	// relative order of smaller and greater elements remains 
	// same. For example, {7, -90, 100, 1} is converted to 
	// {3, 1, 4 ,2 } 


	// Create and initialize smaller and greater arrays 
	
	memset(greater1, 0, sizeof greater1);
    memset(smaller1, 0, sizeof smaller1);
	// Create and initialize an array to store Binary 
	// Indexed Tree 
	
	memset(BIT, 0, sizeof BIT);

	for(int i=n-1; i>=0; i--) 
	{ 
		smaller1[i] = getSum(BIT, arr[i]-1); 
		updateBIT(BIT, n, arr[i], 1); 
	} 
	for (int i=0; i<n; i++) 
	{ 
		cout<<smaller1[i];
	}


	// Reset BIT 
	memset(BIT, 0, sizeof BIT);

	// Count greater elements 
    updateBIT(BIT, n, arr[0], 1); 
	for (int i=1; i<n; i++) 
	{ 
		greater1[i] = i - getSum(BIT,arr[i]); 
		updateBIT(BIT, n, arr[i], 1); 
	} 

	// Compute Inversion count using smaller[] and 
	// greater[]. 
	long long invcount = 0; 
	for (int i=0; i<n; i++) 
		invcount += (1LL*smaller1[i]*greater1[i]); 

	cout<<invcount; 
} 

// Driver program to test above function 
int main() 
{ 
	long n;
    cin>>n;

    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        temp[i]=arr[i];
        

    }
	sort(temp , temp + n );
	for(int i = 0, cnt = 1; i < n; i++)
		if(!mp.count(temp[i]))
			mp[temp[i]] = cnt++;
	for(int i = 0; i < n; ++i)
		arr[i] = mp[arr[i]];
	getInvCount(arr, n);
	return 0; 
} 
