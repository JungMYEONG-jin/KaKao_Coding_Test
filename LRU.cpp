#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize==0)
        return cities.size()*5;
    
    
    vector<string> res;
    map<string ,int> res2;
    int time=0;
    int idx=0;
    for(auto& i : cities)
    {
        transform(i.begin(), i.end(), i.begin(),[](auto e){return tolower(e);});
        auto it = find(res.begin(), res.end(), i);
        
        if(it==res.end())
        {
            answer+=5;
            if(res.size()<cacheSize)
            {
                res.push_back(i);
                res2[i]=idx;
                
            }else if(res.size()==cacheSize)
            {
                // least recently used find
                auto minval = min_element(res2.begin(), res2.end(), [](auto e, auto k){return e.second<k.second;});
                auto it2 = find(res.begin(), res.end(), minval->first);
                res.erase(it2);
                auto it3 = res2.find(minval->first);
                res2.erase(it3);
                res.push_back(i);
                res2[i]=idx;
                //cout<<i<<endl;
            }
        }else
        {
            answer+=1;
            res2[i]=idx;
        }
        
        idx++;
    }
    
    
    return answer;
}
