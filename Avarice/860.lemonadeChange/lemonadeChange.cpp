#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five=0;
    int ten=0;
    int twenty=0;
    for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
            five++;
        }
        else if(bills[i]==10&&five>=1){
            five--;
            ten++;
        }
        else if(bills[i]==20&&five>=1&&ten>=1){
            ten--;
            five--;
            twenty++;
        }
        else if(bills[i]==20&&five>=3&&ten<1){
            five-=3;
            twenty++;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> bills={5,5,10,10,20};
    cout<<lemonadeChange(bills);
    return 0;
}