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


vector<int> graph[101];
bool visited[101];
int dp[101][101];
int n, m;

int bfs(int x, int y){
    int dp[101];
    fill_n(dp, 101, INF);
    queue<int> q;
    q.push(x);
    q.push(y);
    dp[x] = 0;
    dp[y] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next : graph[cur]){
            if (dp[next] > dp[cur] + 1)
            {
                dp[next] = dp[cur] + 1;
                q.push(next);
            }
        }
    }
    int total = 0;
    for(int i=1;i<=n;i++){
        if (dp[i] != INF)
        {
            total += dp[i];
        }
    }
    return 2*total;
}

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    // int n, m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // brute force
    int ans = INF;
    int sx, sy;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int totalTime = bfs(i, j);
            if(ans>totalTime){
                sx = i;
                sy = j;
                ans = totalTime;
            }
        }
    }

    cout<<sx<<" "<<sy<<" "<<ans;
    
    return 0;
}
