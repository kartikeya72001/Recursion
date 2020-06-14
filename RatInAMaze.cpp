// #include <iostream>
// using namespace std;
//
// bool RatInAMAze(char arr[1001][1001], int sol[1001][1001], int i, int j, int n, int m)
// {
//     if(i==n&&j==m)
//     {
//         sol[n][m]=1;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//                 cout<<sol[i][j];
//             cout<<endl;
//         }
//         cout<<endl;
//
//         return true;
//     }
//     //False Case
//     if(i>n||j>m)
//         return false;
//     if(arr[i][j]=='X')
//         return false;
//
//     sol[i][j] = 1;
//     bool Right = RatInAMAze(arr,sol,i,j+1,n,m);
//     bool Down = RatInAMAze(arr,sol,i+1,j,n,m);
//     sol[i][j] = 0;
//
//     if(Right || Down)
//         return true;
//     return false;
// }
//
// int main(int argc, char const *argv[]) {
//     int n,m;
//     cin>>n>>m;
//
//     char arr[1001][1001];
//
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>arr[i][j];
//         }
//     }
//
//     int sol[1001][1001] = {0};
//
//     if(!RatInAMAze(arr,sol,0,0,n-1,m-1))
//         cout<<"No Solution Possible"<<endl;
//
//     return 0;
// }
#include<iostream>
using namespace std;

bool visited[1001][1001],solution[1001][1001];
bool RatinMaze(char maze[][1001], int i,int j,int m, int n){

    if(i==m && j==n){
        solution[i][j] = 1;
        for(int x=0;x<=m;x++){
            for(int y=0;y<=n;y++){
                cout<<solution[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    if(visited[i][j]){
        return false;
    }

    visited[i][j]=1;
    solution[i][j] = 1;
        if(j+1<=n && !visited[i][j+1]){
                bool rightsuccess = RatinMaze(maze,i,j+1,m,n);
                if(rightsuccess==true){
                    return true;
                }
        }
        if(i+1<=m && !visited[i+1][j]){
                bool downsuccess = RatinMaze(maze,i+1,j,m,n);
                if(downsuccess==true){
                    return true;
                }
        }
    solution[i][j] = 0;
    return false;
}


int main(){
    char maze[1001][1001];
    int n,m;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='X')
                visited[i][j]=1;
        }
    }
    m--;
    n--;
    int Y = RatinMaze(maze,0,0,m,n);
    if(Y==false){
        cout<<"-1";
    }
    return 0;
}
