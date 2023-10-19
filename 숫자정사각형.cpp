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

int solution(vector<string> board) {
    int answer = 9999999;
    int fx = board.size();
    int fy = board[0].size();
    int sx, sy = 0;
    int ex, ey = 0;

    for(int i=0, len = fx; i<len; i++){
        for(int j=0, blen =fy;j<blen;j++){
            if (board[i][j]=='R')
            {
                sx = i;
                sy = j;
            }else if(board[i][j]=='G'){
                ex = i;
                ey = j;
            }
            
        }
    }
    vector<vector<bool>> visited(fx, vector<bool>(fy, false));
    vector<vector<int>> dp(fx, vector<int>(fy, 9999999));
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dp[sx][sy] = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        visited[x][y] = true;
        if (x==ex && y==ey)
        {
            answer = min(answer, dp[x][y]);
        }
        for(int i=0;i<4;i++){
            int nx = x;
            int ny = y;
            int px = nx;
            int py = ny;
            while((nx!=0 && nx!=fx) || (ny!=0 && ny!=fy) || board[nx][ny]!='D'){
                px = nx;
                py = ny;
                nx += dx[i];
                ny += dy[i];
            }
            
            if (visited[px][py])
            {
                continue;
            }
            

            q.push({px, py});
            dp[px][py] = min(dp[x][y] + 1, dp[px][py]);
        }
    }
    
    return answer == 9999999 ? -1 : answer;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<string> temp;
    for(int i=0;i<n;i++){
        string v;
        cin>>v;
        temp.push_back(v);
    }
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = temp[i][j] - '0';
        }
    }

    int base = min(n ,m);
    while(base>1){
        for(int i=0;i<=n-base;i++){
        for(int j=0;j<=m-base;j++){
            int value = arr[i][j];
            // if square?
            if(arr[i+base-1][j] == value && arr[i+base-1][j+base-1] == value && arr[i][j+base-1] == value){
                cout<<base*base;
                return 0;
            }
        }
        }
        base--;
    }
    
    cout<<1;
    
    return 0;
}
