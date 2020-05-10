// You will be given a numeric string S. Print all the possible codes for S.
//
// Following vector contains the codes corresponding to the digits mapped.
//
// string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
//
// For example, string corresponding to 0 is " " and 1 is ".+@$"
//
// Input Format
// A single string containing numbers only.
//
// Constraints
// length of string <= 10
//
// Output Format
// All possible codes one per line in the following order.
//
// The letter that appears first in the code should come first
//
// Sample Input
// 12
// Sample Output
// .a
// .b
// .c
// +a
// +b
// +c
// @a
// @b
// @c
// $a
// $b
// $c
// Explanation
// For code 1 the corresponding string is .+@$ and abc corresponds to code 2.
#include<iostream>
#include<cstring>
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void printKeys(char *in, char *out, int i, int j)
{
	//Base
	if(in[i]=='\0')
	{
		out[j]=='\0';
		cout<<out<<endl;
		return;
	}

	//rec
	int digit = in[i] - '0';
	for(int k=0;table[digit][k]!='\0';k++)
	{
		out[j] = table[digit][k];
		printKeys(in,out,i+1,j+1);
	}
}
int main() {
	char in[111];
	char out[111];
	cin>>in;
	printKeys(in,out,0,0);
	return 0;
}
