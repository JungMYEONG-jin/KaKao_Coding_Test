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
#include <cstring>

#define INF 999999999

using namespace std;


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<string>& arr, int n, int m){
    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i=0;i<n;i++){
        for (size_t j = 0; j < m; j++)
        {
            if (arr[i][j]=='#' && !visited[i][j])
            {
                /* code */
                visited[i][j] = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    auto it = q.front();
                    q.pop();
                    int x = it.first;
                    int y = it.second;

                    for(int d=0;d<4;d++){
                        int nx = x+dx[d];
                        int ny = y+dy[d];

                        if (nx<0 || nx>=n || ny<0 || ny>=m)
                        {
                            continue;
                        }

                        if (visited[nx][ny] || arr[nx][ny]!='#')
                        {
                            continue;
                        }
                        
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    // input
    ios_base::sync_with_stdio(0);
	cin.tie(0); 
    cout.tie(0);
    int n, m, p;
    cin>>m>>n>>p;

    int count = 0;
    int start[2] = {1, 0};
    int dir = 1;
    if (n * m < p)
    {
        cout<<0;
        return 0;
    }else{
        while(1){
            for(int i=0;i<n;i++){
                start[1] += dir;
                count ++;

                if (count == p)
                {
                    cout<<start[0]<<" "<<start[1];
                    return 0;
                }
                
            }

            m--;

            for(int i=0;i<m;i++){
                start[0]+=dir;
                count++;
                if (count == p)
                {
                    cout<<start[0]<<" "<<start[1];
                    return 0;
                }
            }

            n--;
            dir*=-1;

        }
    }
    

    return 0;
}
