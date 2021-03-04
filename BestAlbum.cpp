#include <string>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    
    // first map
    
    int len = plays.size();
    map<string ,int> res;
    
    map<string, vector<pair<int, int>>> m; // genre : idx, number
    
    for(int i=0;i<len;i++)
    {
        m[genres[i]].push_back({i, plays[i]});
        res[genres[i]]+=plays[i];
    }
    
    map<int, string, greater<int>> reverse_res;
    for(auto i : res)
        reverse_res[i.second] = i.first;
    // use map's greater sort attribute
    // 3100 pop 1450 classic~
    
    for(auto i : reverse_res)
    {
        auto val = m[i.second]; // will be vector<pair<int, int>> 
        // sort val 
        sort(val.begin(), val.end(), [](auto e, auto k){return e.second>k.second || e.second==k.second && e.first<k.first;});
        answer.push_back(val[0].first);
        if(val.size()>1)
        {
            
            answer.push_back(val[1].first);
        }
        
    }
    
    
    return answer;
}
