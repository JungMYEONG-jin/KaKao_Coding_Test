#include <string>
#include <vector>
#include <queue>

using namespace std;

int num;
vector<vector<int>> res;
vector<int> dist;

pair<int, int> bfs(int start)
{

    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<bool> visited(num+1, false);
    visited[start]=true;
    pair<int, int> temp = {start, 0};
    while(!q.empty())
    {
        auto temp2 = q.front();
        q.pop();

        int cur = temp2.first;
        int cnt = temp2.second;


        if(cnt>temp.second)
        {
            temp = {cur, cnt};
            dist.clear();
            dist.push_back(cur);
        }else if(cnt==temp.second)
            dist.push_back(cur);



        for(auto& it : res[cur])
        {
            if(visited[it])
                continue;

            visited[it] = true;
            q.push({it, cnt+1});
        }





    }



    return temp;




}

int solution(int n, vector<vector<int>> edges) 
{
   num = n;
    res.resize(n+1, vector<int>());

    for(auto& i : edges)
    {
        res[i[0]].push_back(i[1]);
        res[i[1]].push_back(i[0]);
    }

    auto x = bfs(1);
    auto y = bfs(x.first);

    if(dist.size()>=2)
        return y.second;
    auto z = bfs(y.first);
    if(dist.size()>=2)
        return y.second;
    else if(dist.size()==1)
        return y.second-1;



}
