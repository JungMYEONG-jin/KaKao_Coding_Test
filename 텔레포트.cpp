#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <random>
#include <numeric>

#define INF 999999999

using namespace std;

int getMinKickCount(int start, int end){
    
}

int main()
{
    // input
    int n, m;
    cin>>n>>m;
    vector<int> graph[300001];
    bool visited[300001];
    fill_n(visited, 300001, false);
    int start, end;
    cin>>start>>end;
    for(int i=0;i<m;i++){
        int tx, ty;
        cin>>tx>>ty;
        graph[tx].push_back(ty);
        graph[ty].push_back(tx);
    }

    // do bfs

    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    int ans = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int cur = it.first;
        int cnt = it.second;

        if (cur == end)
        {
            ans = cnt;
            break;   
        }
        if(cur+1 <= n && !visited[cur+1]){
            q.push({cur+1, cnt+1});
            visited[cur+1] = true;
        }
        if(cur-1>0 && !visited[cur-1]){
            q.push({cur-1, cnt+1});
            visited[cur-1] = true;
        }
        
        
        // search graph
        for(const auto value : graph[cur]){
            if(!visited[value]){
                q.push({value, cnt+1});
                visited[value] = true;
            }
            
        }
    }

    cout<<ans<<endl;

    return 0;
}
