// Take as input S, a string. Write a function that does basic string compression. Print the value returned. E.g. for input “aaabbccds” print out a3b2c2d1s1.
//
// Input Format
// A single String S
//
// Constraints
// 1 < = length of String < = 1000
//
// Output Format
// The compressed String.
//
// Sample Input
// aaabbccds
// Sample Output
// a3b2c2d1s1
// Explanation
// In the given sample test case 'a' is repeated 3 times consecutively, 'b' is repeated twice, 'c' is repeated twice and 'd and 's' occurred only once.
#include <bits/stdc++.h> 
using namespace std;

void printRLE(string str)
{
	int n = str.length();
	for (int i = 0; i < n; i++) {

		// Count occurrences of current character
		int count = 1;
		while (i < n - 1 && str[i] == str[i + 1]) {
			count++;
			i++;
		}

		// Print character and its count
		cout << str[i] << count;
	}
}

int main()
{
	string str;
    cin>>str;
	printRLE(str);
	return 0;
}
