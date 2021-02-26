#include<iostream>
#include<stdlib.h>
using namespace std;
void merge(int arr[],int s,int e)
{
	int mid = (s+e)/2;
	int i=s;
	int j = mid+1;
	int k = s;
	int a[1000];

	while(i<=mid && j<=e)
	{
		if(arr[i]<arr[j])
			a[k++] = arr[i++];
		else
			a[k++] = arr[j++];
	}

	while(i<=mid)
		a[k++] = arr[i++];
	while(j<=e)
		a[k++] = arr[j++];

	for(int i=s;i<=e;i++)
	{
		arr[i] = a[i];
	}
}
void mergeSort(int arr[],int s,int e)
{
	if(s>=e)
		return;
	int mid = (s+e)/2;

	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);

	merge(arr,s,e);
}
int main()
{
	int n;
	cin>>n;
	int arr[10000];
	for(int i=0;i<n;i++)
	{
		arr[i] = rand();
	}
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
