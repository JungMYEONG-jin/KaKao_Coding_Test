#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parent(101);
    for(int i=0;i<=100;i++)
        parent[i]=i;
    
  sort(costs.begin(), costs.end(), [](auto e, auto k){return e[2]<k[2];});
   
   function<int(int)> find_parent = [&parent, &find_parent](auto e){
        if(e==parent[e])
            return e;
        return parent[e] = find_parent(parent[e]);
    };
    
    function<bool(int, int)> cycle = [&parent, &find_parent](auto e, auto k){
        e = find_parent(e);
        k = find_parent(k);
        if(e==k)
            return false; //사이클이 존재함 사이클이 존재하면 안되므로 false
        else
        {
            if(e>k)
                parent[e]=k;
            else
                parent[k]=e;
        }
        return true;
    };
    
    for(auto i : costs)
    {
        if(cycle(i[0], i[1]))
            answer+=i[2];
    }
    
    
    
    
    
    
    
    return answer;
}
