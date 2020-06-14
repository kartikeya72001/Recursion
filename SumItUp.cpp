#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void TargetSum(int *arr, int n, int k, int i, vector<int> ans)
{
    if(n==0 || i==n)
        return;
    if(k==0)
    {
        for(int j=0;j<ans.size();j++)
            cout<<ans[j]<<" ";
        cout<<endl;
        return;
    }
    if(arr[i]<=k)
    {
        ans.push_back(arr[i]);
        TargetSum(arr,n,k-arr[i],i+1,ans);
        ans.pop_back();
        TargetSum(arr,n,k,i+1,ans);
    }
    else{
        TargetSum(arr,n,k,i+1,ans);
    }
    return;
}

void SumitUp(int *arr, int n, int k, int idx, vector<int> ans)
{
    if(k==0)
    {
        for(int j=0;j<ans.size();j++)
            cout<<ans[j]<<" ";
        cout<<endl;
        return;
    }
    for (int i = idx; i < n; i++) {
        if(i>idx && arr[i] == arr[i-1])
               continue;
        if(k-arr[i] >=0)
        {
            ans.push_back(arr[i]);
            TargetSum(arr,n,k-arr[i],i+1,ans);
            ans.pop_back();
        }
    }
    return;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    vector<int> ans;
    //TargetSum(arr,n,k,0,ans);
    sort(arr,arr+n);
    SumitUp(arr,n,k,0,ans);
    return 0;
}
