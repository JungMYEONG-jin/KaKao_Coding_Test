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

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	  cin.tie(0); 
    cout.tie(0);
    // int n, m;
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    vector<pair<int, int>> path;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]!=0)
                path.push_back({i, j});
        }
    }
    int ans = 0;
    int twoSum = 0;
    // find path
    for(int i=0, len = path.size() ; i<len ; i++){
        bool visited[51][51];
        for(int i=0;i<51;i++)
            fill_n(visited[i], 51, false);
        auto it = path[i];
        visited[it.first][it.second];
        int ex, ey, ecnt;
        queue<tuple<int, int, int>> q;
        q.push({it.first, it.second, 1});
        // do bfs
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int x, y, cnt;
            tie(x, y, cnt) = cur;
            ex = x;
            ey = y;
            ecnt = cnt;
            for(int d=0;d<4;d++){
                int nx = x+dx[d];
                int ny = y+dy[d];
                if(nx<0 || nx>=n || ny<0 || ny>=m)
                    continue;
                if (!visited[nx][ny] && arr[nx][ny]!=0)
                {
                    q.push({nx, ny, cnt+1});
                    visited[nx][ny] = true;
                }
            }
        }
        if(ecnt > ans){
            ans = ecnt;
            twoSum = arr[it.first][it.second] + arr[ex][ey];
        }else if(ecnt == ans && arr[it.first][it.second] + arr[ex][ey] > twoSum){
            twoSum = arr[it.first][it.second] + arr[ex][ey];
        }
    }
    cout<<twoSum<<endl;
    return 0;
}
