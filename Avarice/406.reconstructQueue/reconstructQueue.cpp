#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(),cmp);
    vector<vector<int>> queue;
    for(int i=0;i<people.size();i++){
        int position=people[i][1];
        queue.insert(queue.begin()+position,people[i]);
    }
    return queue;
}

int main(){
    vector<vector<int>> arr={{7,0},{4,4},{7,1},{5,0},{6,0},{5,2}};
    for(auto row:reconstructQueue(arr)){
        for(int num:row){
            cout<<num<<",";
        }
        cout<<endl;
    }
    return 0;
}