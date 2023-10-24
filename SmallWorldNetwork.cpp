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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> graph[101];
int dp[101];

bool isClear(int n){
    for(int i=1;i<=n;i++){
        if(dp[i] == -1 || dp[i]>6)
            return false;
    }
    return true;
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    dp[start] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
       
        for(const int next : graph[x]){
            if (dp[next] == -1)
            {
                q.push(next);
                dp[next] = dp[x]+1;
            }
        }
    }
}

int main()
{
    // input
    int n, m;
    cin>>n>>m;
    

    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        fill_n(dp, 101, -1);
        bfs(i);
        if(!isClear(n)){
            cout<<"Big World!"<<endl;
            return 0;
        }
    }
    cout<<"Small World!"<<endl;;

    return 0;
}
