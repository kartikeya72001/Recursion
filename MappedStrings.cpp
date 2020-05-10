// We are given a hashmap which maps all the letters with number. Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z. Given a number, you have to print all the possible strings.
//
// Input Format
// A single line contains a number.
//
// Constraints
// Number is less than 10^6
//
// Output Format
// Print all the possible strings in sorted order in different lines.
//
// Sample Input
// 123
// Sample Output
// ABC
// AW
// LC
// Explanation
// '1' '2' '3' = ABC
// '1' '23' = AW
// '12' '3' = LC
#include<iostream>
using namespace std;

void findStrings(char *a, int i,int j, char *out)
{
	if(a[i] == '\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}

	int digit = a[i] - '0';
	char ch = digit + 'A' -1;
	out[j] = ch;

	findStrings(a,i+1,j+1,out);

	if(a[i+1]!='\0'){
		int second = a[i+1] - '0';
		int no = 10*digit + second;
		if(no<=26){
			ch = no +'A' -1;
			out[j] = ch;
			findStrings(a,i+2,j+1,out);
		}
	}
}
int main() {
	char A[1000000];
	char output[1000000];
	cin>>A;
	findStrings(A,0,0,output);
	return 0;
}
