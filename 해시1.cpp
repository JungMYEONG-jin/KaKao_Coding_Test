#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string ,int> res;
    
    for(auto& i : participant)
    {
        res[i]++;      
    }
    
    for(auto& i : completion)
    {
        res[i]--;
        if(res[i]<0)
            return i;
    }
    
    
    
    auto it = max_element(res.begin(), res.end(), [](auto e, auto k){return e.second<k.second;});
    
    answer = it->first;
    return answer;
}
