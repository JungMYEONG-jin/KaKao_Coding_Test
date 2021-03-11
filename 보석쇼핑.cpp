#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<pair<int ,int>> temp;
    map<string, int> res;
    set<string> gem_name(gems.begin(), gems.end());
    
    int len = gem_name.size(); // 보적의 종류
    int tot = gems.size(); // 길이
    
    int left=0;
    int right=0;
    
    while(true)
    {
        int len2 = res.size();
        
        if(left>=tot)
            break;
        
        if(len2==len)
        {
            temp.push_back({left+1, right});
            res[gems[left]]--;
            if(res[gems[left]]==0)
            {
                auto it = res.find(gems[left]);
                res.erase(it);
            }
            left++;
            continue;
        }
        
        
        
        
        if(right>=tot)
            break;
        
        
        if(len2!=len)
        {
            
            res[gems[right]]++;
            right++;
            continue;
        }
        
        
        
        
        
    }
    
    sort(temp.begin(), temp.end(), [](auto e, auto k){
        int len = e.second-e.first;
        int len2 = k.second-k.first;
        return len<len2 || len==len2 && e.first<k.first;
    });
    
    
    
    
    
    answer.push_back(temp[0].first);
    answer.push_back(temp[0].second);
    
    
    
    return answer;
}
