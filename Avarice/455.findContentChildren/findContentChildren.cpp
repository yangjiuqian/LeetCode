#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int gPoint=0;
    int sPiont=0;
    int satis=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    while(gPoint<g.size()&&sPiont<s.size()){
        if(g[gPoint]<=s[sPiont]){
            gPoint++;
            sPiont++;
            satis++;
        }
        else{
            sPiont++;
        }
    }
    return satis;
}

int main(){
    vector<int> g={1,2};
    vector<int> s={1,122,3};
    cout<<findContentChildren(g,s);
    return 0;
}