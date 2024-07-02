#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

void printVector(vector<vector<int>>& vec){
    for(auto row:vec){
        for(auto num:row){
            cout<<num<<",";
        }
        cout<<"||";
    }
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),cmp);
    printVector(intervals);
    cout<<endl;
    int slow=0,fast=1;
    int count=0;
    while(fast<intervals.size()){
        if(intervals[fast][0]<intervals[slow][1]){
            if(intervals[fast][1]<intervals[slow][1]){
                slow=fast;
            }
            count++;
            fast++;
        }
        else{
            slow=fast;
            fast++;
        }
    }
    return count;
}

int main(){
    vector<vector<int>> vec={{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    cout<<eraseOverlapIntervals(vec);
    return 0;
}