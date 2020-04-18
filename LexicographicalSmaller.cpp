


//TO print lexicographical permutations

#include <iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
string sortString(string &str)
{
	sort(str.begin(), str.end());
	return str;
}
void permutation (string a, int l, int r, string s)
{
	if (l == r && s>a)
		cout<<a<<endl;
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a[l], a[i]);
			permutation (a, l+1, r, s);
			swap(a[l], a[i]);
		}
	}
}

int main()
{
	string str ;
	cin>>str;
	int n = str.length();
	string s=str;
	sortString(str);
	permutation (str, 0, n-1, s);
	return 0;
}
