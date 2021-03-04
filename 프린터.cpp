#include <string>
#include <vector>
#include <algorithm>



using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<pair<int, int>> res;
    
    int j=0;
    for(auto i : priorities)
    {
        res.push_back({j, i});
        j++;
    }
    
    
    
    
    auto val = res[location];
    int stage=0;
    while(!res.empty())
    {
        
        auto temp = res[0];
        
        auto it = find_if(res.begin(), res.end(), [temp](auto e){return e.second>temp.second;});
        if(it!=res.end()) // 더큰 원소가 존재하면
        {
            res.push_back(temp);
            res.erase(res.begin());
        }else
        {
            if(temp==val)
            {
                stage++;
                res.erase(res.begin());
                break;
            }
            
            
            stage++;
            res.erase(res.begin());
            
        }
        
        
        
        
        
        
    }
    
    
    return stage;
}

/*

if 큐를 쓴다면

queue<int> res;
for(int i=0;i<len;i++)
{
res.push(i);
}

vector<int> result;

while(!res.empty())
{
int cur = res.front();
res.pop();

if(vec[cur]==*max_element(vec.begin(), vec.end()))
{
result.push_back(cur);
vec[cur]=0;

}
else
{
res.push(cur);


}


}


for(int i=0;i<len;i++)
{
if(result[i]==location) return i+1;

}



*/
