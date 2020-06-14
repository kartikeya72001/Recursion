#include<iostream>
#include<cmath>
using namespace std;
bool placement(int mat[][9], int i, int j, int n, int num)
{
	for(int x=0;x<n;x++)
	{
		if(mat[x][j]==num || mat[i][x]==num)
		{
			return false;
		}
	}
	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;

	for(int x=sx;x<sx+rn;x++)
	{
		for(int y=sy;y<sy+rn;y++)
		{
			if(mat[x][y]==num)
				return false;
		}
	}
	return true;
}
bool solveSudoku(int mat[][9], int i, int j, int n)
{
	if(i==n)
	{
		for(int k=0;k<n;k++)
		{
			for(int l=0;l<n;l++)
			{
				cout<<mat[k][l  ]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
		return false;
	}

	if(j==n)
		return solveSudoku(mat,i+1,0,n);
	if(mat[i][j]!=0)
		return solveSudoku(mat,i,j+1,n);

	//Main Recursion
	for(int num = 1;num<=n;num++)
	{
		if(placement(mat,i,j,n,num))
		{
			mat[i][j] = num;
			bool isSolved = solveSudoku(mat,i,j+1,n);
			if(isSolved)
			{
				return true;
			}
		}
	}
	mat[i][j] = 0;
	return false;
}
int main()
{
	int n;
	cin>>n;
	// int mat[9][9] = {0};
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cin>>mat[i][j];
	// 	}
	// }
	int mat[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
			         {5, 2, 0, 0, 0, 0, 0, 0, 0},
			         {0, 8, 7, 0, 0, 0, 0, 3, 1},
			         {0, 0, 3, 0, 1, 0, 0, 8, 0},
			         {9, 0, 0, 0, 6, 3, 0, 0, 5},
			         {0, 5, 0, 0, 9, 0, 6, 0, 0},
			         {1, 3, 0, 0, 0, 0, 2, 0, 0},
			         {0, 0, 0, 0, 0, 0, 0, 7, 4},
			         {0, 0, 5, 2, 0, 0, 3, 0, 0} };
	cout<<endl<<endl;
	solveSudoku(mat,0,0, n);
	return 0;
}
/*#include<iostream>
#include<cmath>
using namespace std;
bool placement(int mat[][9], int i, int j, int n, int num)
{
	for(int x=0;x<n;x++)
	{
		if(mat[x][j]==num || mat[i][x]==num)
		{
			return false;
		}
	}
	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;

	for(int x=sx;x<sx+rn;x++)
	{
		for(int y=sy;y<sy+rn;y++)
		{
			if(mat[x][y]==num)
				return false;
		}
	}
	return true;
}
bool solveSudoku(int mat[][9], int i, int j, int n)
{
	if(i==n)
	{
		for(int k=0;k<n;k++)
		{
			for(int l=0;l<n;l++)
			{
				cout<<mat[k][l]<<" ";
			}
			cout<<endl;
		}
		return false;
	}

	if(j==n)
		return solveSudoku(mat,i+1,0,n);
	if(mat[i][j]!=0)
		return solveSudoku(mat,i,j+1,n);

	//Main Recursion
	bool res  = false;
	for(int num = 1;num<=n;num++)
	{
		if(placement(mat,i,j,n,num))
		{
			mat[i][j] = num;
			res = res || solveSudoku(mat,i,j+1,n);
			mat[i][j] = 0;
		}
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	int mat[9][9] = {0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	solveSudoku(mat,0,0,n);
	return 0;
}*/
