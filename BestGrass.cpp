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
    vector<string> arr;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    bool visited[101][101];

    for(int i=0;i<101;i++)
        fill_n(visited[i], 101, false);

    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (arr[i][j]=='#' && !visited[i][j])
            {
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while(!q.empty()){
                    auto it = q.front();
                    q.pop();
                    int x= it.first;
                    int y = it.second;
                    for(int i=0;i<4;i++){
                        int nx = x+dx[i];
                        int ny = y+dy[i];
                        if(nx <0 || nx>=n || ny<0 || ny>=m){
                            continue;
                        }
                        if (arr[nx][ny]=='#' && !visited[nx][ny])
                        {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
             }
        }
    }
    cout<<ans<<endl;

    return 0;
}
