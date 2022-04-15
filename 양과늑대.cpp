#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Status
{
    int cur, ship, wolf, state;
};

bool visited[17][1<<17];
vector<int> temp_info;
vector<int> adj[20];

int bfs()
{
    queue<Status> q;
    q.push({0,1,0,1}); // 첫 시작은 양이 있어야함. current ship wolf state
    visited[0][1] = true;
    int cnt = 0;
    
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        cnt = max(cnt, it.ship);
        for(int next : adj[it.cur])
        {
            int cntShip = 0;
            int cntWolf = 0;
            
            if(!temp_info[next]&&!(it.state&(1<<next))) // ship 0
                cntShip++;
            if(temp_info[next]&&!(it.state&(1<<next))) // wolf 1
                cntWolf++;
            
            if(temp_info[next] && (it.ship<=(it.wolf+cntWolf))) // case when wolf is greater or equal than shi
                continue;
               
            int cntState = it.state | (1<<next);
            if(visited[next][cntState])
               continue;
               
            visited[next][cntState] = true;
            q.push({next, it.ship+cntShip, it.wolf+cntWolf, cntState});
            
        }
        
    }
    return cnt;
}



int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    temp_info = info;
    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    answer = bfs();
    
    return answer;
}
