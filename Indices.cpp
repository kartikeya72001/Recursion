// Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns an array containing indices of all items in the array which have value equal to M. Print all the values in the returned array.
//
// Input Format
// Enter a number N(size of the array) and add N more numbers to the array Enter number M to be searched in the array
//
// Constraints
// 1 <= Size of array <= 10^5
//
// Output Format
// Display all the indices at which number M is found in a space separated manner
//
// Sample Input
// 5
// 3
// 2
// 1
// 2
// 3
// 2
// Sample Output
// 1 3
// Explanation
// 2 is found at indices 1 and 3.
#include <bits/stdc++.h>
using namespace std;

// A recursive function to find all
// indices of a number
int AllIndexesRecursive(int input[], int size,
					int x, int output[])
{

	if (size == 0) {
		return 0;
	}

	int smallAns = AllIndexesRecursive(input + 1, 
									size - 1, x, output);

	if (input[0] == x) {
		for (int i = smallAns - 1; i >= 0; i--) {
			output[i + 1] = output[i] + 1;
		}

		output[0] = 0;
		smallAns++;
	}
	else {

		for (int i = smallAns - 1; i >= 0; i--) {
			output[i] = output[i] + 1;
		}
	}
	return smallAns;
}

void AllIndexes(int input[], int n, int x)
{
	int output[n];
	int size = AllIndexesRecursive(input, n,
								x, output);
	for (int i = 0; i < size; i++) {
		cout << output[i] << " ";
	}
}

// Driver Code
int main()
{
	int arr[100000], x;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>x;
	// Function call
	AllIndexes(arr, n, x);

	return 0;
}
