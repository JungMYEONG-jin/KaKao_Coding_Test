#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second>b.second;
    }
};


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    
    int len = jobs.size();

    int time=0, idx=0;
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int ,int>>, cmp> res;
    
    while(idx<len || !res.empty())
    {
        while(idx<len && time>=jobs[idx][0])
        {
            res.push({jobs[idx][0], jobs[idx][1]});
            idx++;
        
        }
        
        if(!res.empty())
        {
            time+=res.top().second;
            answer+=time-res.top().first;
            res.pop();
        }else
            time = jobs[idx][0];
        
    }
    
    
    
    
    
    
    return answer/len;
}
