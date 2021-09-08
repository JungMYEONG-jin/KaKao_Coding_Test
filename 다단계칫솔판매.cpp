#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void DFS(string name, int cost,map<string, string>& db, map<string, int>& money)
{
    
    if(name=="-")
        return;
    int res = cost/10;
    if(res<1)
    {
        money[name]+=cost;
        return;
        
    }else
    {
     int rest = cost-res;
     money[name]+=rest;
     DFS(db[name],res,db,money);
        
    }
    
    
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    map<string, int> sales;
    map<string, string> db;

    for(auto& it : enroll)
    {
        sales[it]=0;
    }
    
    for(int i=0, len=enroll.size();i<len;i++)
        db[enroll[i]] = referral[i];
    
    
    for(int i=0,len=seller.size();i<len;i++)
    {
        DFS(seller[i], amount[i]*100, db, sales);
    }
    
    for(auto& it : enroll)
        answer.push_back(sales[it]);
    
    
    return answer;
}
