#include<iostream>
using namespace std;
int grid[11][11];
int counter=0;
void print(int n) {
    for (int i = 0;i <= n-1; i++) {
        for (int j = 0;j <= n-1; j++) {
            if(grid[i][j]==1)
                cout <<"Q ";
            else
                cout<<"_ ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
bool isSafe(int col, int row, int n) {
    for (int i = 0; i < row; i++) {
        if (grid[i][col]) {
            return false;
        }
    }
    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
        if (grid[i][j]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}

bool solve (int n, int row) {
    if (n == row) {
        print(n);
		counter++;
        return false;
    }
    bool res = false;
    for (int i = 0;i <=n-1;i++) {
        if (isSafe(i, row, n)) {
            grid[row][i] = 1;
            res = solve(n, row+1) || res;

            grid[row][i] = 0;
        }
    }
    return res;
}
int main()
{
        int n;
        cin >> n;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                grid[i][j] = 0;
            }
        }
        solve(n, 0);
        if(counter == 0) {
            cout << "No Cases Possible" << endl;
        } else {
            cout<<counter<<endl;
        }
  return 0;
}
