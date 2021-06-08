#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > generateMatrix(int A) {
    vector<vector<int>> res( A, vector<int> (A, 0));
    int temp = 1;
    int top = 0, down = A - 1, left = 0, right = A - 1;
    
    //for direction, 0 means left to right, 1 indicates top to bottom, 2 indicates right to left and 3 indicates bottom to top
    int direction = 0; 
    while (top <= down && left <= right) {
        if (direction == 0) {
            for (int i = left; i <= right; i++){
                res[top][i] = temp;
                temp++;
            }
            top++;
        }
        else if (direction == 1) {
            for (int i = top; i <= down; i++) {
                res[i][right] = temp;
                temp ++;
            }
            right--;
        }
        else if (direction == 2) {
            for (int i = right; i >= left; i--) {
                res[down][i] = temp;
                temp++;
            }
            down--;
        }
        else if (direction == 3) {
            for (int i = down; i >=top; i--) {
                res[i][left] = temp;
                temp++;
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
    return res;
}

int main() 
{
    int n;
    cin >> n;
    vector<vector<int>> res = generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<res[i][j];
        }
        cout<<"\n";
    }
    return 0;
}