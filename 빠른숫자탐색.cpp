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
    int arr[5][5];
    int visited[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
            if (arr[i][j] == 1)
            {
                n = i;
                m = j;
            }
        }
        fill_n(visited[i], 5, INF);
    }
    int sx, sy;
    cin>>sx>>sy;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    int ans = INF;
    visited[sx][sy] = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;

        if (x == n && y == m)
        {
            ans = min(ans, visited[x][y]);
        }

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5){
                continue;
            }
            if (arr[nx][ny] != -1 && visited[nx][ny] > visited[x][y] + 1)
            {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if (ans == INF)
    {
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    

    return 0;
}
