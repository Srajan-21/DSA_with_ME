#include<iostream>
#include<queue>
using namespace std;

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // how much petrol is less
        int deficit = 0;
         
        // how much petrol left
        int balance = 0;

        // from where circuit will start
        int start = 0;

        for(int i=0;i<gas.size();i++){
            balance += gas[i] - cost[i];
            if(balance < 0){
                deficit += balance;
                start = i+1;
                balance = 0;
            }
        }

        if(deficit + balance >= 0)
            return start;
        else
            return -1;
    }

    int main(){
        vector<int> gas = {1,2,3,4,5};
        vector<int> cost = {3,4,5,1,2};
        cout<<canCompleteCircuit(gas , cost);
    }