#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

void printDuralVector(vector<vector<int>>& vec){
    for(auto row:vec){
        for(auto num:row){
            cout<<num<<",";
        }
        cout<<"||";
    }
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),cmp);
    printDuralVector(intervals);
    cout<<endl;
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=result.back()[1]&&intervals[i][1]>result.back()[1]){
            result.back()[1]=intervals[i][1];
        }
        else if(intervals[i][0]<=result.back()[1]&&intervals[i][1]<=result.back()[1]){
            continue;
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    printDuralVector(result);
    return result;
}

int main(){
    // vector<vector<int>> intervals ={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> intervals ={{1,4},{2,3}};
    merge(intervals);
    return 0;
}