#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagCheck;
unordered_map<int,bool> bottomLeftDiagCheck;

void printSolution(vector<vector<char>> &board , int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row , int col,vector<vector<char>> &board , int n)
{

    if(rowCheck[row]==true)
        return false;

    if(upperLeftDiagCheck[n-1+col-row]==true)
        return false;

    if(bottomLeftDiagCheck[row+col]==true)
        return false;

    return true;

    // // check krenge k kya current cell [row,col] pr queen h  ya nhi
    // int i=row;
    // int j=col;

    // // check row
    // while(j>=0)
    // {
    //     if(board[i][j]=='Q')
    //     {
    //         return false;
    //     }
    //     j--;
    // }

    // // check upper left diagnol
    // i=row;
    // j=col;
    // while(i>=0 && j>=0)
    // {
    //     if(board[i][j]=='Q')
        // return false;

        // i--;
        // j--;
    // }

    // // check botom left diagnol
    // i=row;
    // j=col;
    // while(i<n && j>=0)
    // {
    //     if(board[i][j]=='Q')
    //     return false;

    //     i++;
    //     j--;
    // }

    // return true;
}

void solve(vector<vector<char>>& board , int col , int n)
{
    // base case
    if(col>=n)
    {
        printSolution(board,n);
        return ;
    }

    for(int row = 0 ; row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            // q rkho
            board[row][col] = 'Q';
            rowCheck[row]=true;
            upperLeftDiagCheck[n-1+col-row]=true;
            bottomLeftDiagCheck[row+col]=true;

            // recursive call
            solve(board,col+1,n);

            // backtracking
            board[row][col]='-';
            rowCheck[row]=false;
            upperLeftDiagCheck[n-1+col-row]=false;
            bottomLeftDiagCheck[row+col]=false;
        }
    }
}
int main(){
    int n=4;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    if(n<=3)
        cout<<"No solutions found";

    int col=0;
    solve(board,col,n);
}