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

int arr[101][71];
bool visited[101][71];
bool peak = true;

int dx[8] = {1, 1, 0, 0, -1, -1, 1, -1};
int dy[8] = {0, -1, 1, -1, 0, 1, 1, -1};
int n, m;

void check(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int curX = it.first;
        int curY = it.second;

        for(int i=0;i<8;i++){
            int nx = curX+dx[i];
            int ny = curY+dy[i];

            if(nx<0 || nx>=n || ny<0 || ny>=m)
                continue;

            if(arr[x][y]<arr[nx][ny]){
                peak = false;
            }
            if(visited[nx][ny] || arr[x][y] != arr[nx][ny])
                continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    // int n, m;
    cin>>n>>m;

    int ans = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                peak = true;
                check(i, j);
                if (peak)
                {
                    ans++;
                }
                
            }
        }
    }

    cout<<ans<<endl;
 

    return 0;
}
