#include<iostream>
using namespace std;
void towerOfHanoi(int n, char src, char dest, char help)
{
	if(n==0)
		return;
	towerOfHanoi(n-1,src,help,dest); //To place n-1 discs on the helper stack and free up the nth disc
	cout<<"Moving ring "<<n<<" from "<<src<<" to "<<dest<<endl;
	towerOfHanoi(n-1,help,dest,src);//To place the n-1 discs back on the dest stack with the nth disc
	return;

}
int main()
{
	int n;
	cin>>n;
	towerOfHanoi(n,'A','B','C');
	return 0;
}
