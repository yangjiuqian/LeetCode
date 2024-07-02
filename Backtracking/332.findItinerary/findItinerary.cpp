#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<string> result;
    void backtracking (vector<vector<string>>& tickets, vector<bool>& used) {
        if(result.front()!="JFK")return;
        if(result.size()==tickets.size()+1){
            return;
        }
        for(int i=0;i<tickets.size();i++){
            if(used[i]==true)continue;
            if(result.empty()){
                result.push_back(tickets[i][0]);
                result.push_back(tickets[i][1]);
                used[i]==true;
            }
            else if(tickets[i][0]==result.back()){
                result.push_back(tickets[i][1]);
                used[i]==true;
            }
            else{
                result.push_back(tickets[i][0]);
                result.push_back(tickets[i][1]);
            }
            backtracking(tickets,used);
            result.pop_back();
            used[i]==false;
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(),false);
        backtracking(tickets,used);
        return result;
    }
};

int main(){
    vector<vector<string>> tickets={
        {"MUC","LHR"},
        {"JFK","MUC"},
        {"SFO","SJC"},
        {"LHR","SFO"}};
    Solution a;
    vector<string> ans=a.findItinerary(tickets);
    for(auto row:ans){
        for(auto num:row){
            cout<<num;
        }
        cout<<endl;
    }
    return 0;
}