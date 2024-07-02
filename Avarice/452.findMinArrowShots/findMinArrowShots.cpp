#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}


int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(),points.end(),cmp);
    int shut=1;
    int start=0,end=1;
    while(end<points.size()){
        if(points[end][0]<=points[start][1]){
            if(points[end][1]<points[start][1]){
                start = end;
            }
            end++;
        }
        else{
            shut++;
            start = end;
            end++;
        }
    }
    return shut;
}

int main(){
    vector<vector<int>> points={{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
    cout<<findMinArrowShots(points);
    return 0;
}