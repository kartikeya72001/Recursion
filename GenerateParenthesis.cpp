// Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
// The output strings should be printed in the sorted order considering '(' has higher value than ')'.
//
// Input Format
// Single line containing an integral value 'n'.
//
// Constraints
// 1<=n<=11
//
// Output Format
// Print the balanced parentheses strings with every possible solution on new line.
//
// Sample Input
// 2
// Sample Output
// ()()
// (())
#include <iostream>
using namespace std;

void Generate(int n, int openB, int closeB, string str) {
    if(closeB == n) {
        cout<<str<<endl;
        return;
    }
    if(openB > closeB) {
        Generate(n, openB, closeB+1, str+')');
    }
    if(openB < n) {
        Generate(n, openB+1, closeB, str+'(');
    }
}

int main()
{
    int n;
    cin>>n;
    Generate(n, 0, 0, "");
    return 0;
}
