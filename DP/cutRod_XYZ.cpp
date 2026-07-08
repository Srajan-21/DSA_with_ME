#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;

int solveRecursion(int n , int x , int y , int z){
    if(n == 0)return 0;
    if(n < 0)return INT_MIN;

    int a = solveRecursion(n - x , x , y , z) + 1;
    int b = solveRecursion(n - y , x , y , z) + 1;
    int c = solveRecursion(n - z , x , y , z) + 1;

    return max(a , max(b , c));
}

int cutSegments(int n , int x , int y , int z){
    int ans = solveRecursion(n , x , y , z);
    return ans < 0 ? 0 : ans;
}

int main(){
    int n , x , y , z;
    cin >> n >> x >> y >> z;
    cout << cutSegments(n , x , y , z) << endl;
    return 0;
}