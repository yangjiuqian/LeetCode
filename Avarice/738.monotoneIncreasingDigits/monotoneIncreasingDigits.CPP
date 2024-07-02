#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

vector<int> int2vec(int n){
    vector<int> result;
    while(n>0){
        result.push_back(n%10);
        n/=10;
    }
    return result;
}

int vec2int(vector<int> vec){
    int result=0;
    for(int i=vec.size()-1;i>=0;i--){
        result+=vec[i]*pow(10,i);
    }
    return result;
}

void printVec(vector<int> vec){
    for(auto num:vec){
        cout<<num<<",";
    }
    cout<<endl;
}

int findFallingEdge(vector<int> vec){
    int fast=vec.size()-2,slow=vec.size()-1;
    int start=0;
    while(fast>=0){
        if(vec[fast]>vec[slow]){
            slow = fast;
            fast--;
        }
        else if(vec[fast]==vec[slow]){
            start=slow;
            fast--;
        }
        else{
            start=slow;
            return start;
        }
    }
    return -1;
}

int monotoneIncreasingDigits(int n) {
    vector<int> vec=int2vec(n);
    int fallEdge = findFallingEdge(vec);
    int result = 0;
    if(fallEdge==-1){
        return n;
    }
    else{
        for(int i=vec.size()-1;i>fallEdge;i--){
            result+=vec[i]*pow(10,i);
        }
        result+=(vec[fallEdge]-1)*pow(10,fallEdge);
        for(int i=fallEdge-1;i>=0;i--){
            result+=9*pow(10,i);
        }
    }
    return result;
}

int monotoneIncreasingDigitsSmartAss(int N) {
        string strNum = to_string(N);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i] ) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }

int main(){
    int n=556205;
    vector<int> vec=int2vec(n);
    printVec(vec);
    cout<<monotoneIncreasingDigitsSmartAss(n);
    return 0;
}