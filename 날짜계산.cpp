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
    int a, b, c;
    cin>>a>>b>>c;
    int e =1, s = 1, m =1;
    int cnt = 0;
    while(true){
        e%=15;
        s%=28;
        m%=19;
        cnt++;

        e = (e == 0) ? 15 : e;
        s = (s == 0) ? 28 : s;
        m = (m == 0) ? 19 : m;

        if (e == a && s == b && m == c)
        {
            break;
        }
        e++;
        s++;
        m++;
    }
    cout<<cnt<<endl;

    return 0;
}
