#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n=gas.size();
    int j;
    for(int i=0;i<n;i++){
        j=i;
        while(gas[j]>cost[j]&&gas[j]-cost[j]+gas[(j+1)%n]>cost[(j+1)%n]){
            j=(j+1)%n;
            if(j==i){
                return j+1;
            }
        }
    }
    // if(startPosition>=n)return -1;
    // remain=gas[startPosition];
    // int i=startPosition;
    // int naxt=i+1;
    // while(1){
    //     if(naxt==startPosition)return naxt;
    //     remain = remain-cost[i]+gas[naxt];
    //     i=(i+1)%n;
    //     if(i==n-1){
    //         naxt=0;
    //     }
    //     else{
    //         naxt=i+1;
    //     }
    //     if(remain<cost[i])return -1;
    // }
    // if(remain>=0&&i%n==startPosition)return startPosition;
    return -1;
}

int main(){
    vector<int> gas={1,2,3,4,5};
    vector<int> cost={3,4,5,1,2};
    cout<<canCompleteCircuit(gas,cost);
    return 0;
}