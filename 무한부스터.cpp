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

vector<int> arr[26];

bool bfs(int left, int right){
    queue<int> q;
    q.push(left);
    bool visited[26] = {false};
    visited[left] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : arr[x]){
            if (visited[next])
            {
                continue;
            }
            visited[next] = true;
            q.push(next);
        }
    }
    return visited[right];
}

int main()
{
    // input
    int n, m;
    cin>>n>>m;
    int arr[300][300];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int dp[300][300];
    for(int i=0;i<300;i++){
        fill_n(dp[i], 300, INF);
    }
    dp[0][0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});
    int ans = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        if (x == n-1 && y == m-1)
        {
            ans = dp[x][y];
            break;
        }
        // 아래
        for(int i=1;i+x<n && i<=arr[x][y];i++){
            if(dp[i+x][y] > dp[x][y]+1){
                dp[i+x][y] = dp[x][y] + 1;
                q.push({i+x, y});
            }
        }
        // 오른쪽
        for(int i=1;i+y<m && i<=arr[x][y];i++){
            if(dp[x][y+i] > dp[x][y]+1){
                dp[x][y+i] = dp[x][y] + 1;
                q.push({x, y+i});
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
